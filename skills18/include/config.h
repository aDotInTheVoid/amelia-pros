#ifndef _CONFIG_H_
#define _CONFIG_H_

enum Motor {
    rightFrontMotor = 1,
    leftFrontMotor,
    rightBackMotor,
    rightArmMotor,
    leftIntakeMotor,
    rightIntakeMotor,
    clawLiftMotor,
    leftArmMotor,
    clawMotor,
    leftBackMotor
};

enum Joystick {
    turnJoystick = 1,
    forwardJoystick = 3,
    sideJoystick, // 4
    armButtons, // 5
    clawButtons, // 6
    intakeButtons, // 7
};

enum DigitalSensor {
    limitSwitch = 1,
};

enum IME {
    armEncoder,
    clawLiftEncoder,
};

#endif /* end of include guard: _CONFIG_H_ */
