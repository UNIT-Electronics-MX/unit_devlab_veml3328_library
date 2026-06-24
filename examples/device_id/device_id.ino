#include <DevLab_VEML3328.h>

#define SerialDebug Serial

void setup() {
    SerialDebug.begin(115200);

    if (DevLab_VEML3328.begin()) {
        SerialDebug.println("Error: could not start DevLab_VEML3328 library");
    }
}

void loop() {
    SerialDebug.print("Device ID: 0x");
    SerialDebug.println(DevLab_VEML3328.deviceID(), HEX);
    delay(2000);
}
