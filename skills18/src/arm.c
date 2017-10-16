#include "main.h"
#include "arm.h"
#include "config.h"

void armSet(bool up, bool down, int speed)
{
    if (up) {
        motorSet(leftArmMotor, speed);
        motorSet(rightArmMotor, -speed);

        motorSet(clawLiftMotor, -speed * (2.0/3.0));

    } else if (down) {
        motorSet(leftArmMotor, -speed);
        motorSet(rightArmMotor, speed);

        motorSet(clawLiftMotor, speed * (2.0/3.0));
    } else {
        motorSet(leftArmMotor, 0);
        motorSet(rightArmMotor, 0);
        motorSet(clawLiftMotor, 0);
    }
}

void armSetTarget(int target) {

}
