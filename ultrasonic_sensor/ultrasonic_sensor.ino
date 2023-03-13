
#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0_UltrasonicSensor.h"


/*
THE ULTRASONIC SENSOR
The ultrasonic sensor works by sending signals and measuring the time it takes for the signals that were sent to return to the sensor. Through some math, the distance from the sensor can be calculated
as we know the speed of the signals and the time it took for the signal to travel a certain distance. All of these calculations are done in the back end, on one of the driver files, all we have to do
is call the function and we get the distance (if you want to see and understand the function that calculates the distance let us know and we would be happy to show you).

DeviceDriverSet_UTLRASONIC Class - We must instantiate this in order to access the ultrasonic sensor

DeviceDriverSet_ULTRASONIC_Init() - Configures the pin numbers for the Ultrasonic sensor, allows the motherboard on the robot to talk to the sensor (call this in setup)
DeviceDriverSet_ULTRASONIC_Get() - Retrieves the data from Ultrasonic sensor, returns the distance of an obstacle that is in front of the Ultrasonic Sensor (in centimeters)

*/

DeviceDriverSet_ULTRASONIC myUltrasonic; // Instantiates an ultrasonic object, used to then call all the functions necessary to use the Ultrasonic sensor

void setup()
{
  Serial.begin(9600); // Establish a data transfer rate of 9600 bits/second
  myUltrasonic.DeviceDriverSet_ULTRASONIC_Init(); // Configuring the pin numbers for the Ultrasonic sensor, allows the motherboard on the robot to talk to the sensor
}

void loop()
{
  unsigned int x = myUltrasonic.DeviceDriverSet_ULTRASONIC_Get(); // Calling the Get function to get data from the Ultrasonic sensor, it returns and Unsigned int that we store inside variable x (An Unsigned int is just an integer that is positive, includes 0)

  /* Remember x only contains the distance of an obstacle from the robot, we would then need to use motion control functions to move the robot around the obstacle */

  Serial.print("ULTRASONIC="); // Printing the distance (x) to the serial monitor - to access the serial monitor, select the magnifying glass icon on the top right of the Arduino IDE
  Serial.print(x);
  Serial.println("cm");
}
