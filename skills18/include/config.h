#ifndef _CONFIG_H_
#define _CONFIG_H_

enum motors {
    leftIntakeMotor = 1,
    rightFrontMotor, // 2
    leftBackMotor, // 3
    rightBackMotor, // 4
    leftFrontMotor, // 5
    leftArmMotor, // 6
    rightArmMotor, // 7
    clawLiftMotor, // 8
    clawMotor, // 9
    rightIntakeMotor, // 10
};

enum joysticks {
    turnJoystick = 1,
    forwardJoystick = 3,
    sideJoystick, // 4
    armButtons, // 5
    clawButtons, // 6
};

#endif /* end of include guard: _CONFIG_H_ */
