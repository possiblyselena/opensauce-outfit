#include <BluetoothSerial.h>
#include <ESP32Servo.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

// Bluetooth setup
BluetoothSerial SerialBT;
const char *braceletBTName = "ESP32bracelet"; // Name of the bracelet ESP32 to connect to

// Servo setup
Servo servo;
const int SERVO_PIN = 15; // GPIO pin for servo signal (adjust as needed)
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

// Accelerometer data storage
float accelX = 0, accelY = 0, accelZ = 0;
unsigned long lastReceiveTime = 0;
const unsigned long RECEIVE_TIMEOUT = 2000; // Timeout if no data received (ms)

void setup()
{
    Serial.begin(115200);
    delay(1000);

    // Initialize Servo
    servo.setPeriodHertz(50);           // Standard servo frequency
    servo.attach(SERVO_PIN, 500, 2400); // Attach servo with min/max pulse widths
    servo.write(90);                    // Start at neutral position
    Serial.println("Servo initialized to 90 degrees");

    // Initialize Bluetooth as slave (waiting for bracelet to connect)
    SerialBT.begin("ESP32headset"); // This device's Bluetooth name
    Serial.println("Headset Bluetooth started, waiting for bracelet connection...");
}

void loop()
{
    // Read incoming Bluetooth data from bracelet
    if (SerialBT.available())
    {
        String data = SerialBT.readStringUntil('\n');
        parseAccelerometerData(data);
        lastReceiveTime = millis();

        // Map accelerometer X-axis to servo angle (adjust mapping as needed)
        // accelX range: -2.0 to +2.0 g-force -> servo angle: 0 to 180 degrees
        int servoAngle = map(constrain((int)(accelX * 45), -90, 90), -90, 90, MIN_ANGLE, MAX_ANGLE);
        servo.write(servoAngle);

        Serial.printf("Accel - X:%.2f Y:%.2f Z:%.2f | Servo Angle: %d\n", accelX, accelY, accelZ, servoAngle);
    }

    // Timeout check: if no data received for too long, return servo to neutral
    if (millis() - lastReceiveTime > RECEIVE_TIMEOUT && lastReceiveTime != 0)
    {
        Serial.println("No data received from bracelet. Returning servo to neutral...");
        servo.write(90);
        lastReceiveTime = 0; // Reset to avoid repeated messages
    }

    delay(10);
}

void parseAccelerometerData(String data)
{
    // Expected format: "X:value,Y:value,Z:value"
    // Example: "X:0.50,Y:-0.25,Z:1.02"

    int xStart = data.indexOf("X:") + 2;
    int xEnd = data.indexOf(',');
    int yStart = data.indexOf("Y:") + 2;
    int yEnd = data.indexOf(',', yStart);
    int zStart = data.indexOf("Z:") + 2;
    int zEnd = data.length();

    if (xStart > 1 && xEnd > xStart && yStart > 1 && yEnd > yStart && zStart > 1)
    {
        accelX = data.substring(xStart, xEnd).toFloat();
        accelY = data.substring(yStart, yEnd).toFloat();
        accelZ = data.substring(zStart, zEnd).toFloat();
    }
    else
    {
        Serial.println("Failed to parse accelerometer data");
    }
}