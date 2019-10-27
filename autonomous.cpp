#include "main.h"
#include "motor_defs.h"
#include "okapi/api.hpp"

//#define delay(time) pros::delay(time)

using namespace okapi;


//motor defs
MotorDefs mo;

//turn scale factor from @mukulr
const double TURN_SCALE_FACTOR = 7.44444;



auto myChassis = ChassisControllerFactory::create(
  {-7, -12}, // Left motors
  {8, 6},   // Right motors
  AbstractMotor::gearset::red, // Torque gearset
  {3.25_in, 13.5_in} // 4 inch wheels, 12.5 inch wheelbase width
);

auto profileController = AsyncControllerFactory::motionProfile(
  0.2,  // Maximum linear velocity of the Chassis in m/s
  0.5,  // Maximum linear acceleration of the Chassis in m/s/s
  10.0, // Maximum linear jerk of the Chassis in m/s/s/s
  myChassis // Chassis Controller
);

//pid turning
//thanks to @mukulr
void turn(double angle, int multiplier){
  double scaled_angle = TURN_SCALE_FACTOR * angle;
  mo.fleft_drive->move_relative(scaled_angle * multiplier, 100);
  mo.bleft_drive->move_relative(scaled_angle * multiplier, 100);
  mo.fright_drive->move_relative(-scaled_angle * multiplier, 100);
  mo.bright_drive->move_relative(-scaled_angle * multiplier, 100);
}

void tilt(int power, int time){
    mo.lift -> move(power);
    //delay(time);
}

void roller_intake(int power, int timedelay){

  mo.roller_right -> move(-power);
  mo.roller_left -> move(-power);
  //delay(timedelay);

}

void roller_outake(int power, int timedelay){

  mo.roller_right -> move(power);
  mo.roller_left -> move(power);
  //delay(timedelay);

}

void autonomous() {

  // roller_intake(-110,4);

  //moves 3 feet forward
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{1.8_ft, 0_ft, 0_deg}}, "A");
  pros::Task::delay(3);
  profileController.setTarget("A");
  profileController.waitUntilSettled();

  pros::Task::delay(2);

  // profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.5_ft, 0_ft, 0_deg}}, "B");
  // delay(3);
  // profileController.setTarget("A");
  // profileController.waitUntilSettled();

  //if red alliance going to small zone
  turn(21, 5);


  roller_intake(0,1);


  //just test the tilting

  roller_outake(-50,1);

  mo.lift -> move(95);

  pros::Task::delay(4000);

  roller_outake(-25,1);

  //delay(1);

  tilt(-127,1);

  // //moves 3 feet forward
  // profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{-4_ft, 0_ft, 0_deg}}, "D");
  // profileController.setTarget("D");
  // profileController.waitUntilSettled();

}

