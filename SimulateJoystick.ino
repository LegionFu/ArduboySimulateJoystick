#include <Joystick.h>
#include "Arduboy.h"
//#include <Keyboard.h>
 
Arduboy arduboy;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  4, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering
  
void setup() {
  arduboy.begin();
  arduboy.clear();

  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
  
  Serial.begin(115200);
}
 
void loop() {
  
  if (!(arduboy.nextFrame()))
    return;
        
  if (arduboy.pressed(UP_BUTTON)) {
    Joystick.setYAxis(-1);
  }else
  if (arduboy.pressed(DOWN_BUTTON)) {
    Joystick.setYAxis(1);
  }else 
  {
    Joystick.setYAxis(0);
  }
  
  if (arduboy.pressed(LEFT_BUTTON)) {
    Joystick.setXAxis(-1);
  }else 
  if (arduboy.pressed(RIGHT_BUTTON)) {
    Joystick.setXAxis(1);
  }else 
  {
    Joystick.setXAxis(0);
  }

  if (arduboy.pressed(A_BUTTON) && arduboy.pressed(B_BUTTON))
  {
      Joystick.setButton(3, 1);
      Joystick.setButton(0, 0);
      Joystick.setButton(1, 0);
  }
  else
  {
      Joystick.setButton(3, 0);  

      if (arduboy.pressed(A_BUTTON)) {
        Joystick.setButton(0, 1);
      }else
      {
        Joystick.setButton(0, 0);
      }
    
      if (arduboy.pressed(B_BUTTON)) {
        Joystick.setButton(1, 1);
      }else
      {
        Joystick.setButton(1, 0);
      }
  }
} 
