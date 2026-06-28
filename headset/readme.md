# Mecha-inspired Headset Attachments (and a bracelet accerlerometer)

I took inspiration from [Nasha's wing headset!](https://vt.tiktok.com/ZSCBQKjPd/) Since at undercity me and my buddies made a gundam outfit, I wanted to make a outfit for Opensauce. Plus demoing will be really easy because I'll just be wearing it.

## CAD
I designed the headset attachment and the electronics case through Onshape. I made the case look like a walkman, to be a bit more performative.

<img width="300" height="250" alt="image" src="https://github.com/user-attachments/assets/d92499b9-5e0a-4a8a-84ca-e19e97a87f9a" />
<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/fef4916b-9f6b-41aa-96d9-bb468d43bc34" />

## PCB
For the accelerometer, I wanted to make it with lace, so I made a small-ish pcb with holes on the side to tie the lace and I'll make a pocket with the lace to fit the battery.

<img width="300" height="200" alt="image" src="https://github.com/user-attachments/assets/0c2e789f-498c-4904-911c-e3639bf3e896" />
<img width="300" height="250" alt="image" src="https://github.com/user-attachments/assets/b0daf0c9-7042-43ce-b7fc-1a3d0efbf4c4" />
<img width="300" height="270" alt="image" src="https://github.com/user-attachments/assets/969dc52b-7fbf-4138-89e8-8d228cc38a7b" />

## BOM

Things I already have:
ESP32, MPU6050 (essentially the same as sen142), breadboard, wires, basic assembly things
| Item Name             | Price (CAD) | Quantity | Total (CAD) | Purchase Link | 
|-----------------------|-------------|----------|-------------|----------------|
| 2pc SG90 Servo Motor | 9.99$ | 1 | 9.99$ | [Amazon](https://www.amazon.ca/Servo-Helicopter-Airplane-Remote-Control/dp/B09L525KDT/ref=sr_1_5?crid=34HWQBXT8V32I&dib=eyJ2IjoiMSJ9.lB4sKn152VCulFDSWZREaQKsBY1f47T5zTrOWkggWz6o29wHPzpGaezLYTDF5j9YDjOF2-Be6fnQFoniWeTVeog5F76RXJoD1975FQQU7kRHofisq_CoLa8HxtHKcpEMv6ZJApCI24m0toXThBvgovdDTaCEhHExNfqfFOA1z7cYHUjcEAJ1X12H72CjFBWkh0u2evTOo0TemK6UIR4qCvGx5ZuB5BZPjpTtXmuetclEnJaIYVnKs8l14_iS83vYa8z5hT7lU7AaESKIAyDGOc2MM-MLoNI8L-aA8_RBbug.OnCujQ50fPdUj5sg2o5UQIn_tEcg-Uc0c3T1IRc_tp4&dib_tag=se&keywords=2pc+servos&qid=1782616651&sprefix=2pc+servos%2Caps%2C119&sr=8-5) |
| ESP32 C3 Devkit | 21.99$ | 1 | 21.99$ | [Amazon](https://www.amazon.ca/ESP32-C3-Blue-Tooth-Internet-Development-ESP32-C3-DevKitM-1/dp/B0DQJ8KGJM/ref=sr_1_1_sspa?crid=20OITKQMD4UNK&dib=eyJ2IjoiMSJ9.xL2w3IwP7v_dTK_eSsR-XJVw2KZWvNploiQXYmuV3wjMtZFhEESDoFnjQxTxqKTS0XveGVrDAm_S7jKpQKXenOuKuIXC8JvlcIdq85tL_Q6j421w4zlQcCYyjumDkyHGEozdGuAx2UVCeOyXk-knJagE6XwDMz_HUnxtAyGZyss9b3HYjB1_CPP5FDwFjMvka78aHBCWglh_-AiKDvjNhEgqBoUyvB5HJsYhfeHqmNYp0WmFQ_n3BY_gSgvJ2iH8cqhMTHFp_Z9X6I0MiPTGSE2jCit6wqZXc6YDQHeXDIs.TSmrqjff2Nopq9ZYE9S6yyi6kHHkAekmwD6LJR2bqAA&dib_tag=se&keywords=esp+32+devkitc+c3&qid=1782617069&sprefix=esp+32+devkit+c3%2Caps%2C144&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) |
| 2pc Lipo Battery | 21.99$ | 1 | 21.99$ | [Amazon](https://www.amazon.ca/Rechargeable-Controller-CUH-ZCT1-Electronic-Bluetooth/dp/B0CG178SHB/ref=sr_1_5?crid=37V9S3HSW8FWH&dib=eyJ2IjoiMSJ9.Ig80C9FPZMDP6OZVlEMddYtKekPGsA6gflmkYTcaJLdS5S-S-7lMY-gVBui4mIA9Bb5xFRwe-ees-3FQPoEfJtlj7vVaGqONRlM_F_8ZE0MJiRiuZT3rIJUABpq9Xj8MOF5VcWCjjg6PhFnt57f8VE3YhPArscAdSLWPXSGCmvtXxwPlsuP9_gZLxA4EGniIk9YQT51bMaj_-adbg9yQRH6q_lQ0yeWq06xC8xVSdKLD3mB69YetcGo1A1J3tGmg3Gf0u43ABDZmsxYBdgkRPsODpjRi_10Mys3QCahDFgA.05bsjhzHxu-FM3ppHEQ-eFWVtnVoLrA0EBFctOQSVXs&dib_tag=se&keywords=lipo+battery&qid=1782616967&sprefix=lipo+batter%2Caps%2C171&sr=8-5)|
| Velcro | 7.23$ | 1 | 7.23$ | [Amazon](https://www.amazon.ca/EILKBLA-Strips-Adhesive-Fastener-Mounting/dp/B0DFCN752Q/ref=sr_1_7?crid=1GUVIIWOQ81ID&dib=eyJ2IjoiMSJ9.UaP0FlQC7kWk-MntfrZdMqDVk-MssZkwYtXJstO-MDm6F_nVnHCdCSRH6sFK_4XqQQX1KG-Npw1t9s3BpH2vpOJBjJIhpJYKuxZrmRYT8aEh9bDHoo9SIwB2FsCYJ610l5Ddr5jWArDv6rxRJoZcgRNEkKaVLKZ3rlJsoqIsNXg_b2SjM88JpiEzqwiEI7RCtvs52KQ2Uu2hwgYeZmioS34o0cauWq6VyNbDZLIVlPxIa6DmW_7_lED-nBBjKOM8TJzcvXaQypPMx1wQQUg8p9QKwC4qbW3c5-TCMb7bISU.4IAdjpTpywW73G5bgv8BcWg7qzbs9O4_Rs03qL-Fva0&dib_tag=se&keywords=velcro&qid=1782617265&sprefix=velcro%2Caps%2C144&sr=8-7) |
| PCB | 2.40$ | 1 | 2.40$ | JLCPCB |
