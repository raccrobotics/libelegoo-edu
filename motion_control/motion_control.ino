// These are the prerequisite classes and functions that motor control requires
#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0_MotorControl.h"
#include "ApplicationFunctionSet_xxx0_MotorControl.cpp"

// We initialize the objects for motors and motion control
DeviceDriverSet_Motor AppMotor;
Application_xxx Application_SmartRobotCarxxx0;

/*
  FUNCTIONS FOR ROBOT MOTOR CONTROL:

  The value of Application_SmartRobotCarxxx0.Motion_Control determines the direction of motion.
  - If Application_SmartRobotCarxxx0.Motion_Control = 0 -> Forward
  - If Application_SmartRobotCarxxx0.Motion_Control = 1 -> Backward
  - If Application_SmartRobotCarxxx0.Motion_Control = 2 -> Left
  - If Application_SmartRobotCarxxx0.Motion_Control = 3 -> Right
  - If Application_SmartRobotCarxxx0.Motion_Control = 4 -> LeftForward
  - If Application_SmartRobotCarxxx0.Motion_Control = 5 -> LeftBackward
  - If Application_SmartRobotCarxxx0.Motion_Control = 6 -> RightForward
  - If Application_SmartRobotCarxxx0.Motion_Control = 7 -> RightBackward
  - If Application_SmartRobotCarxxx0.Motion_Control = 8 -> stop_it

  Speed values range from 0-255.

  The function to control direction and speed is as follows:
  ApplicationFunctionSet_SmartRobotCarMotionControl(direction, speed)

  The function takes in two parameters: one for direction, and one for speed.

  Therefore, to make the robot go forward with a speed of 255, we would call the function as follows:
  Application_SmartRobotCarxxx0.Motion_Control = 0;  // Motion Control Direction is set to Forward
  ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control, 255);  // First argument is the direction set in the previous line, second argument is the speed

  The function to maintain current state of motion by preventing code execution for a given period of time is the delay() function, which accepts a time argument (milliseconds) as follows:
  delay(time)

  Therefore, to make the car continue forward at full speed for two seconds, we can use the delay() function as follows:
  delay(2000);

  If we want to stop the car, we would call the function as follows:
  Application_SmartRobotCarxxx0.Motion_Control = 8;  // Motion Control Direction is set to Forward
  ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control, 0)  // First argument is the direction set in the previous line, second argument is the speed

  Overall, this would result in the following code:
  // Continue forward at full speed for 2 seconds
  Application_SmartRobotCarxxx0.Motion_Control = 0;
  ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control, 255);
  delay(2000);

  // Stop the car
  Application_SmartRobotCarxxx0.Motion_Control = 8;
  ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control, 0);
*/

void setup() {
  // put your setup code here, to run once:
  AppMotor.DeviceDriverSet_Motor_Init();  // Sets the motors to their corresponding ports on the microcontroller
}

void loop() {
  // put your main code here, to run repeatedly:

  // Robot goes forward at full speed for 2 seconds
  Application_SmartRobotCarxxx0.Motion_Control = 0;
  ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control, 255);
  delay(2000);

  // Robot goes backward at half speed for 2 seconds
  Application_SmartRobotCarxxx0.Motion_Control = 1;
  ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control, 127.5);
  delay(2000);

  // Robot stops
  Application_SmartRobotCarxxx0.Motion_Control = 8;
  ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control, 0);
}
