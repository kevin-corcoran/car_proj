#include "car.h"

/* Constructor */
Car::Car(int lpin1, int lpin2, int rpin1, int rpin2) {
  left_pin_1_ = lpin1; left_pin_2_ = lpin2;
  right_pin_1_ = rpin1; right_pin_2_ = rpin2;
  Left_Motor_ = new Motor(left_pin_1_, left_pin_2_);
  Right_Motor_ = new Motor(right_pin_1_, right_pin_2_);
}

void Car::setup() {
  Left_Motor_->setup();
  Right_Motor_->setup();
}

void Car::loop() {

}

void Car::setSpeed(int speed) {

}

void Car::turnLeft() {

}

void Car::turnRight() {

}
