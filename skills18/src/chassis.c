#include "main.h"    // includes API.h and other headers
#include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included

void chassisSet(int forward, int side, int turn)
{
    int leftFrontVal = forward + side + turn;
    int rightFrontVal = -forward + side + turn;
    int leftBackVal = forward - side + turn;
    int rightBackVal = -forward - side + turn;

    motorSet(leftFrontMotor, leftFrontVal);
    motorSet(rightFrontMotor, rightFrontVal);
    motorSet(leftBackMotor, leftBackVal);
    motorSet(rightBackMotor, rightBackVal);
}
