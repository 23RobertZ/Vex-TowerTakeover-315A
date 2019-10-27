#include "main.h"
#include "motor_defs.h"

MotorDefs mi; 

/**
 * Runs initialization code. This occurs as soon as the program is started.
 */
void initialize() {
    mi.fleft_drive -> set_gearing(pros::E_MOTOR_GEARSET_18);
    mi.fright_drive -> set_gearing(pros::E_MOTOR_GEARSET_18);
    mi.bleft_drive -> set_gearing(pros::E_MOTOR_GEARSET_18);
    mi.bright_drive -> set_gearing(pros::E_MOTOR_GEARSET_18);
    mi.arm_motor -> set_gearing(pros::E_MOTOR_GEARSET_36);
    mi.lift -> set_gearing(pros::E_MOTOR_GEARSET_36);
    mi.roller_right -> set_gearing(pros::E_MOTOR_GEARSET_36);
    mi.roller_left -> set_gearing(pros::E_MOTOR_GEARSET_36);
}

/**
 * Runs while the robot is in the disabled state of the match or field controller.
 * In a match, this runs between the autonomous and driver control modes.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the match or field controller.
 * You can put code for autonomous selection or other initialization tasks here.
 */
void competition_initialize() {}
