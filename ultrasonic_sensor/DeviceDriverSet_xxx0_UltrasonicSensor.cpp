/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-12 16:36:20
 * @LastEditors: Changhua
 * @Description: conqueror robot tank
 * @FilePath: 
 */
#include "DeviceDriverSet_xxx0_UltrasonicSensor.h"

/*ULTRASONIC*/
//#include <NewPing.h>
// NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
void DeviceDriverSet_ULTRASONIC::DeviceDriverSet_ULTRASONIC_Init(void)
{
  pinMode(ECHO_PIN, INPUT); //Ultrasonic module initialization
  pinMode(TRIG_PIN, OUTPUT);
}
/*
void DeviceDriverSet_ULTRASONIC::DeviceDriverSet_ULTRASONIC_Get(uint16_t *ULTRASONIC_Get out)
{
  unsigned int tempda_x = 0;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  tempda_x = ((unsigned int)pulseIn(ECHO_PIN, HIGH) / 58);
  *ULTRASONIC_Get = tempda_x;
  // sonar.ping() / US_ROUNDTRIP_CM; // Send ping, get ping time in microseconds (uS).
}
*/

unsigned int DeviceDriverSet_ULTRASONIC::DeviceDriverSet_ULTRASONIC_Get(void)
{

  unsigned int tempda = 0;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  tempda = ((unsigned int)pulseIn(ECHO_PIN, HIGH) / 58);

  // if (tempda_x > 50)
  // {
  //   tempda_x = 50;
  // }

  // // return tempda;
  // return tempda_x;

return tempda;

}

