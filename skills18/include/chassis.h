#ifndef _CHASSIS_H_
#define _CHASSIS_H_

void chassisSet(int forward, int side, int turn);

enum chassisMotor {
    rightFrontMotor = 2,
    leftBackMotor,
    rightBackMotor,
    leftFrontMotor,
};

enum chassisJoystick {
    forwardJoystick = 3,
    sideJoystick,
    turnJoystick = 1
};

#endif /* end of include guard: _CHASSIS_H_ */
