#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
  Motor(int control_pin);

  Motor(int control1, int control2);

  void setup();

  void loop();

  void toggleDirection();

  /* "Getter" returns speed */
  int getSpeed();

  int getMaxVolt();

  void setSpeed(int speed);

  void setMaxVolt(int volt);


private:
  int pin_;
  int speed_;
  // 255 might be too fast. Should be determined experimentally.
  int max_volt_;
  int pin_1_;
  int pin_2_;

  int speedToVolt(int speed);

  void speedUp(int target_speed);

  void slowDown(int target_speed);

  void stop();
};

#endif /* MOTOR_H */
