#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor Motor11 = motor(PORT11, ratio6_1, false);
motor Motor12 = motor(PORT12, ratio6_1, true);
motor Motor13 = motor(PORT13, ratio18_1, false);
motor Motor14 = motor(PORT14, ratio6_1, false);
motor Motor15 = motor(PORT15, ratio6_1, true);
motor Motor16 = motor(PORT16, ratio18_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}