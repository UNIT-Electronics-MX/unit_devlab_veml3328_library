#include <veml3328.h>
#include <Wire.h>
#define SDA_PIN 6
#define SCL_PIN 7




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
uint16_t VEMLClass::config(sens_config_t sens_config) { 
    uint16_t configReg = ((uint16_t)sens_config.sd0   << 0)  | 
                         ((uint16_t) 0b0 << 1   )  | 
                         ((uint16_t)sens_config.trigger  << 2)  | 
                         ((uint16_t)sens_config.af << 3 )  | 
                         ((uint16_t)sens_config.integration_time << 4)  |
                         ((uint16_t) 0b000 << 7)  | // reserved bits
                         ((uint16_t)sens_config.sensitivity   << 6)  | 
                         ((uint16_t)sens_config.gain << 10)  | 
                         ((uint16_t)sens_config.dg << 12)  | 
                         ((uint16_t)sens_config.sd_als_only << 14)  | 
                         ((uint16_t)sens_config.sd1 << 15);

    uint16_t config = Veml3328.config(cfg) ;

    Serial.print("0x");
    Serial.println(config,HEX);
}

void loop() {
    //Serial.printf("Device ID: %x\r\n", Veml3328.deviceID());
    Serial.printf("Red: %u\r\n", Veml3328.getRed());
    Serial.printf("Green: %u\r\n", Veml3328.getGreen());
    Serial.printf("Blue: %u\r\n", Veml3328.getBlue());
    Serial.printf("IR: %u\r\n", Veml3328.getIR());
    Serial.printf("Clear: %u\r\n\r\n", Veml3328.getClear());
    delay(2000);
}