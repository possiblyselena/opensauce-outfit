#include <BluetoothSerial.h>
#include <MPU6050.h>
#include <Wire.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

// Bluetooth setup
BluetoothSerial SerialBT;
const char *headsetBTName = "ESP32test"; // Name of the headset ESP32 to connect to

// MPU6050 setup
MPU6050 mpu;
const int MPU_ADDR = 0x68; // I2C address of MPU6050

// I2C pins for ESP32
const int SDA_PIN = 21;
const int SCL_PIN = 22;

// Timing
unsigned long lastSendTime = 0;
const unsigned long SEND_INTERVAL = 50; // Send data every 50ms

void setup()
{
    Serial.begin(115200);
    delay(1000);

    // Initialize I2C for accelerometer
    Wire.begin(SDA_PIN, SCL_PIN);

    // Initialize MPU6050
    mpu.initialize();
    if (!mpu.testConnection())
    {
        Serial.println("MPU6050 connection failed!");
        while (1)
            delay(10);
    }
    Serial.println("MPU6050 connected successfully!");

    // Initialize Bluetooth
    SerialBT.begin("ESP32bracelet"); // This device's Bluetooth name
    Serial.println("Bluetooth started. Searching for headset...");

    // Attempt to connect to headset
    connectToHeadset();
}

void loop()
{
    // If not connected, try to reconnect
    if (!SerialBT.connected())
    {
        Serial.println("Lost connection to headset. Attempting to reconnect...");
        connectToHeadset();
    }

    // Read and send accelerometer data at regular intervals
    if (millis() - lastSendTime >= SEND_INTERVAL)
    {
        readAndSendAccelerometerData();
        lastSendTime = millis();
    }

    delay(10);
}

void connectToHeadset()
{
    Serial.print("Scanning for Bluetooth devices... ");
    delay(1000);

    int numDevices = SerialBT.discoverAsyncAuto(10); // Discover for 10 seconds
    Serial.printf("Found %d devices\n", numDevices);

    // Try to connect to the headset
    if (SerialBT.connect(headsetBTName))
    {
        Serial.printf("Connected to %s successfully!\n", headsetBTName);
    }
    else
    {
        Serial.printf("Failed to connect to %s. Retrying in 5 seconds...\n", headsetBTName);
        delay(5000);
    }
}

void readAndSendAccelerometerData()
{
    int16_t ax, ay, az;
    mpu.getAcceleration(&ax, &ay, &az);

    // Convert to more readable values (dividing by 16384 gives approx g-force for ±2g range)
    float accelX = ax / 16384.0;
    float accelY = ay / 16384.0;
    float accelZ = az / 16384.0;

    // Create a simple data packet: "X:value,Y:value,Z:value\n"
    char dataBuffer[50];
    snprintf(dataBuffer, sizeof(dataBuffer), "X:%.2f,Y:%.2f,Z:%.2f\n", accelX, accelY, accelZ);

    // Send over Bluetooth if connected
    if (SerialBT.connected())
    {
        SerialBT.print(dataBuffer);
        Serial.printf("Sent: %s", dataBuffer);
    }
    else
    {
        Serial.println("Not connected to headset, cannot send data");
    }
}
