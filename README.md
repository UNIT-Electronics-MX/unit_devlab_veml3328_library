# DevLab_VEML3328

Arduino driver for the Vishay VEML3328 RGBCIR color sensor.

## Usage

After installation, add this line to the top of your `.ino` file:

```cpp
#include <DevLab_VEML3328.h>
```

Initialize the sensor before reading values:

```cpp
void setup() {
    Serial.begin(115200);

    if (DevLab_VEML3328.begin()) {
        Serial.println("Error: could not start DevLab_VEML3328 library");
    }
}
```

The previous `#include <veml3328.h>` and `Veml3328` object are still available
as compatibility aliases.

## Examples

Examples can be found in the `examples` folder:

- `color`: Reads red, green, blue, infrared and clear channels.
- `config`: Shows the configuration functions.
- `device_id`: Reads the VEML3328 device ID.

## Reference

- [VEML3328 datasheet](https://www.vishay.com/docs/84968/veml3328.pdf)
