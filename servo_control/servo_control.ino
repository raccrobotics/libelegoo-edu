// These are the prerequisite classes and functions that servo control requires
#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0_ServoControl.h"

// We initialize the object for servo control
DeviceDriverSet_Servo AppServo;

/*
  FUNCTIONS FOR SERVO:
  The servo is the device that moves the camera and ultrasonic sensor on your robot. It is basically a motor with a limited degree of motion.

  The servo can only turn for 180 degrees. The 0 degree mark is facing your front right wheel, and the 180 degree mark is facing your front left wheel.
  Note that the default direction of movement is counterclockwise (left)

  Therefore, to move 10 degrees to the right you would subtract 10 from the current position (Current Position - 10).
  To move 10 degrees to the left you would use position add 10 to the current position (Current Position + 10).
  
  To set the position of the servo, use the following function:
  AppServo.DeviceDriverSet_Servo_Init(degreesPosition)

  Therefore, to set the servo facing forward, call the function as follows:
  AppServo.DeviceDriverSet_Servo_Init(90);
*/

// Set global position variable to track position of robot
int position = 90;

void setup()
{
  // Set the servo to the 90 degree position (facing forward)
  AppServo.DeviceDriverSet_Servo_Init(position);

  // For each iteration, move robot 10 degrees to the right until 0 degrees is reached (subtract 10 from the position)
  for (/*using global position variable*/; position >= 0; position -= 10) {
    AppServo.DeviceDriverSet_Servo_Init(position);
  }

  // For each iteration, move robot 10 degrees to the left until 180 degrees is reached (add 10 to the position)
  for (/*using global position variable*/; position <= 180; position += 10) {
    AppServo.DeviceDriverSet_Servo_Init(position);
  }

  // Set the servo to the 90 degree position (facing forward)
  position = 90;
  AppServo.DeviceDriverSet_Servo_Init(position);
}

void loop()
{

}
