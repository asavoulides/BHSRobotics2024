#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor Motor11 = motor(PORT11, ratio6_1, true);
motor Motor12 = motor(PORT12, ratio6_1, true);
motor Motor13 = motor(PORT13, ratio6_1, true);
motor Motor14 = motor(PORT14, ratio6_1, false);
motor Motor15 = motor(PORT15, ratio6_1, false);
motor Motor16 = motor(PORT16, ratio6_1, false);
controller Controller1 = controller(primary);
motor Motor18 = motor(PORT18, ratio6_1, true);
inertial Interial16 = inertial(PORT16);


//Add your devices below, and don't forget to do the same in robot-config.h:
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1XBButtonsControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonX/ButtonB status to control Motor18
      if (Controller1.ButtonX.pressing()) {
        Motor18.setVelocity(600, rpm);
        Motor18.spin(reverse);
        Controller1XBButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonB.pressing()) {
        Motor18.setVelocity(600, rpm);
        Motor18.spin(forward);
        Controller1XBButtonsControlMotorsStopped = false;
      } else if (!Controller1XBButtonsControlMotorsStopped) {
        Motor18.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1XBButtonsControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}


void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}