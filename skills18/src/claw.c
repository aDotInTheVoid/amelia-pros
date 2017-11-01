#include "main.h"
#include "claw.h"
#include "config.h"

void clawSet(bool up, bool down, int speed){

        if (up) {
            motorSet(clawMotor, speed);

        } else if (down) {
            motorSet(clawMotor, -speed);

        } else {
            motorSet(clawMotor, 0);

        }


}
