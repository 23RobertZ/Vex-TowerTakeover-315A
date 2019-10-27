#include "main.h"
#include "motor_defs.h"


MotorDefs::MotorDefs(){
	//motor creation using new for allocating memory (programmers job)
	fleft_drive = new pros::Motor(7, false);
    fright_drive = new pros::Motor(12, true);
    bright_drive = new pros::Motor(8,true);
    bleft_drive = new pros::Motor(6,false);
    roller_right = new pros::Motor(2,true);
    roller_left = new pros::Motor(10,false);
    lift = new pros::Motor(13,false);
    arm_motor = new pros::Motor(20,false);
}


MotorDefs::~MotorDefs(){
		//motor deletion to avoid memory leaks (because we are using dynamic allocation)
        delete fleft_drive;
        delete fright_drive; //true
        delete bright_drive; //true
        delete bleft_drive;
        delete roller_right;
        delete roller_left;
        delete lift;
        delete arm_motor; 
}