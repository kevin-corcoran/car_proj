#ifndef CAR_H
#define CAR_H

#include "motor_h.h"

class Car {
public:
  /* Constructor */
  Car(int lpin1, int lpin2, int rpin1, int rpin2);
  void setup();
  void loop();
  void setSpeed(int speed);
  void turnLeft();
  void turnRight();

private:
  Motor *Left_Motor_; // I'm not sure why this has to be a pointer
  Motor *Right_Motor_; // "                                      "
  int left_pin_1_;
  int left_pin_2_;
  int right_pin_1_;
  int right_pin_2_;

  int speed_;

};

#endif /* MOTOR_H */
