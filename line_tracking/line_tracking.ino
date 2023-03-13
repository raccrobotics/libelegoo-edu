// These are the prerequisite classes and functions that line tracking requires
#include "DeviceDriverSet_xxx0_LineTracking.h"

// We initialize the Line Tracking driver
DeviceDriverSet_ITR20001 AppITR20001;

/* 
  FUNCTIONS FOR ROBOT LINE TRACKING:
  The robot's line tracking modules are broken into three modules: left, middle, and right. Each tracks the amount of light the module receives.
  
  - AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_L() -> Returns the value of the Left Line Tracking Module
  - AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_M() -> Returns the value of the Middle Line Tracking Module
  - AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_R() -> Returns the value of the Right Line Tracking Module

  The larger the value of the line tracking sensor, the lighter the surface is. The smaller the value of the line tracking sensor, the darker the surface is.
*/

void setup() {
  Serial.begin(9600);  // Establish a data transfer rate
  AppITR20001.DeviceDriverSet_ITR20001_Init();  // Set the Line Tracking Module to its corresponding pins
}

void loop() {
    static unsigned long print_time = 0;
    if (millis() - print_time > 500)  // Read the line follower every 500 milliseconds (The millis() method is the uptime of the Arduino)
    {
      print_time = millis();
      // Value of the Left Line Tracking Module
      Serial.print("ITR20001_getAnaloguexxx_L=");
      Serial.println(AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_L());
      // Value of the Middle Line Tracking Module
      Serial.print("ITR20001_getAnaloguexxx_M=");
      Serial.println(AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_M());
      // Value of the Right Line Tracking Module
      Serial.print("ITR20001_getAnaloguexxx_R=");
      Serial.println(AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_R());
    }

}
