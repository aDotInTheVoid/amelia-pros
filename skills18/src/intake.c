#include "main.h"
#include "config.h"
#include "intake.h"

void intakeSet(bool up, bool down, int speed)
{
    if (up) {
        motorSet(leftIntakeMotor, speed);
        motorSet(rightIntakeMotor, -speed);
    } else if (down) {
        motorSet(leftIntakeMotor, -speed);
        motorSet(rightIntakeMotor, speed);
    } else {
        motorSet(leftIntakeMotor, 0);
        motorSet(rightIntakeMotor, 0);
    }
}
