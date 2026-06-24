#include <DevLab_VEML3328.h>

#define SerialDebug Serial

void setup() {
    SerialDebug.begin(115200);

    if (DevLab_VEML3328.begin()) {
        SerialDebug.println("Error: could not start DevLab_VEML3328 library");
    }

    // Set differential gain value
    if (DevLab_VEML3328.setDG(dg_x2)) {
        SerialDebug.println("Error: unable to set DG value");
        return;
    }

    // Set gain
    if (DevLab_VEML3328.setGain(gain_x2)) {
        SerialDebug.println("Error: unable to set device gain");
        return;
    }

    // Set sensitivity (high sensitivity = false, low sensitivity = true)
    if (DevLab_VEML3328.setSensitivity(true)) {
        SerialDebug.println("Error: unable to set device sensitivity");
        return;
    }

    // Set integration time
    if (DevLab_VEML3328.setIntTime(time_400)) {
        SerialDebug.println("Error: unable to set device integration time");
        return;
    }
}

void loop() {}
