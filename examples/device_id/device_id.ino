/** @file veml3328.ino 
2 *
3 * @brief Code example for VEML3328 UNIT Module Light Sensor
4 *
5 * @author Jonathan Mejorado Lopez
6 *
7 * @bug No known bugs.
8 */

#include <veml3328.h>
#include <Wire.h>
#define SDA_PIN 6
#define SCL_PIN 7



//Predefined values  f the sensor 
sens_config_t cfg = {
    .sd1 = false, 
    .sd_als_only = false , 
    .dg = dg_x1, 
    .gain = gain_x1, 
    .sensitivity = false, 
    .integration_time = time_100, 
    .af = false , 
    .trigger = false, 
    .sd0 = false };



void setup() {
    Serial.begin(115200);
    Wire.begin(SDA_PIN,SCL_PIN);
    if (Veml3328.begin(&Wire)) {
        Serial.println("Error: could not start VEML3328 library");
    }
    Serial.printf("Device ID: 0x%x\r\n", Veml3328.deviceID());
    uint16_t config = Veml3328.config(cfg) ;

}

void loop() {
    
    Serial.printf("Red: %u\r\n", Veml3328.getRed());
    Serial.printf("Green: %u\r\n", Veml3328.getGreen());
    Serial.printf("Blue: %u\r\n", Veml3328.getBlue());
    Serial.printf("IR: %u\r\n", Veml3328.getIR());
    Serial.printf("Clear: %u\r\n\r\n", Veml3328.getClear());
    delay(2000);
}