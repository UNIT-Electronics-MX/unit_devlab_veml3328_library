#include <DevLab_VEML3328.h>

#define SerialDebug Serial

void setup() {
    SerialDebug.begin(115200);

    if (DevLab_VEML3328.begin()) {
        SerialDebug.println("Error: could not start DevLab_VEML3328 library");
    }
}

void loop() {

    SerialDebug.println();
    SerialDebug.print("Red: ");
    SerialDebug.println(DevLab_VEML3328.getRed());
    SerialDebug.print("Green: ");
    SerialDebug.println(DevLab_VEML3328.getGreen());
    SerialDebug.print("Blue: ");
    SerialDebug.println(DevLab_VEML3328.getBlue());
    SerialDebug.print("IR: ");
    SerialDebug.println(DevLab_VEML3328.getIR());
    SerialDebug.print("Clear: ");
    SerialDebug.println(DevLab_VEML3328.getClear());
    SerialDebug.println();

    delay(2000);
}
