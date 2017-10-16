/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "chassis.h"
#include "arm.h"
#include "config.h"
#include "intake.h"

const int joystickNumber = 1;
const int armSpeed = 100;

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl() {
    while (1) {

        // Get chassis motion
        int forward = joystickGetAnalog(joystickNumber, forwardJoystick);
        int side = joystickGetAnalog(joystickNumber, sideJoystick);
        int turn = joystickGetAnalog(joystickNumber, turnJoystick);
        chassisSet(forward, side, turn);

        // Get arm motion
        bool up = joystickGetDigital(joystickNumber, armButtons, JOY_UP);
        bool down = joystickGetDigital(joystickNumber, armButtons, JOY_DOWN);

        armSet(up, down, armSpeed);

        // Get intake motion
        bool intakeUp = joystickGetDigital(joystickNumber, intakeButtons, JOY_UP);
        bool intakeDown = joystickGetDigital(joystickNumber, intakeButtons, JOY_DOWN);
        intakeSet(intakeUp, intakeDown, 100);

    }
}
