#include "main.h"
#include "arm.h"
#include "config.h"
#include "slavemaster.h"

void armSet(bool up, bool down, smd data)
{
    mutexTake(data.mutex, -1);
    if (up)        *data.state = 1;
    else if (down) *data.state = -1;
    else           *data.state = 0;
    motorSet(leftArmMotor, -(*data.state) * data.speed);
    mutexGive(data.mutex);
}

smd armSetup(int speed) {
    return setup_slave_master(rightArmMotor, clawLiftMotor, speed,
        armEncoder, clawLiftEncoder, 2.0/3.0);
};

void armSetTarget(int angle) {

}
