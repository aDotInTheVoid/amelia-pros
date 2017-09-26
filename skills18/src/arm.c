#include "main.h"
#include "arm.h"
#include "config.h"

void armSet(bool up, bool down, int speed)
{
    if (up) {
        motorSet(leftArmMotor, speed);
        motorSet(rightArmMotor, -speed);
    } else if (down) {
        motorSet(leftArmMotor, -speed);
        motorSet(rightArmMotor, speed);
    } else {
        motorSet(leftArmMotor, 0);
        motorSet(rightArmMotor, 0);
    }
}
