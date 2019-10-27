//motor definitions for full robot
#include "main.h"

//purposely didn't include the guard

class MotorDefs {
    public:


        pros::Motor *fleft_drive;
        pros::Motor *fright_drive; //true
        pros::Motor *bright_drive; //true
        pros::Motor *bleft_drive;

        pros::Motor *roller_right;
        pros::Motor *roller_left;

        pros::Motor *lift;
        pros::Motor *arm_motor;

        MotorDefs();
        ~MotorDefs();
};