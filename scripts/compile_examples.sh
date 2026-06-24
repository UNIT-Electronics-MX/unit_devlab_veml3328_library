#!/bin/bash

BOARD_CONFIG="${BOARD_CONFIG:-arduino:avr:uno}"

for d in examples/*/ ; do
        echo "Compiling $d..."
        arduino-cli compile -b "$BOARD_CONFIG" --libraries=".." "$d" --build-path "/tmp/devlab-veml3328-build/$(basename "$d")"

        # Check the error code
        if [ $? != 0 ]; then
            exit 1
        fi
done
