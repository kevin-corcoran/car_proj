#include "motor_h.h"

Motor::Motor(int control_pin) {
  pin_ = control_pin;
  speed_ = 0;
  max_volt_ = 255;

  pin_1_ = 0;
  pin_2_ = 0;
}

Motor::Motor(int control1, int control2) {
  pin_1_ = control1;
  pin_2_ = control2;
  speed_ = 0;
  max_volt_ = 255;

  pin_ = pin_1_; // start in one direction
}

void Motor::setup() {
  Serial.begin(9600);
  pinMode(pin_, OUTPUT);
  if (pin_1_ != pin_2_) // if they aren't both 0
    pinMode(pin_2_, OUTPUT);
}

void Motor::loop() {
  analogWrite(pin_, speedToVolt(speed_));
}

void Motor::toggleDirection() {
  int pin = pin_;
  if (pin_ == pin_1_) {
    pin_ = pin_2_;
    // change speed slowly
    setSpeed(speed_);
  } else {
    pin_ = pin_1_;
    // change speed slowly
    setSpeed(speed_);
  }
  analogWrite(pin, 0); // so the other pin can take over
}

/* "Getter" returns speed */
int Motor::getSpeed() {
  return speed_;
}

int Motor::getMaxVolt() {
  return max_volt_;
}

void Motor::setSpeed(int speed) {
  if (speed > speed_) {
    slowDown(speed);
  } else if (speed < speed_) {
    speedUp(speed);
  } // else do nothing
}

void Motor::setMaxVolt(int volt) {
  max_volt_ = volt;
}

int pin_;
int speed_;
// 255 might be too fast. Should be determined experimentally.
int max_volt_;
int pin_1_;
int pin_2_;

int Motor::speedToVolt(int speed) {
  return map(speed, 0, 9, 0, max_volt_);
}

void Motor::speedUp(int target_speed) {
  int volt = speedToVolt(speed_); // 0 - 255
  int target_volt = speedToVolt(target_speed);
  for (int v = volt; v < target_volt; v += 1) {
    analogWrite(pin_, v);
  }
  analogWrite(pin_, target_volt);
  speed_ = target_speed;
}

void Motor::slowDown(int target_speed) {
  int volt = speedToVolt(speed_); // 0 - 255
  int target_volt = speedToVolt(target_speed);
  for (int v = volt; v > target_volt; v -= 1) {
    analogWrite(pin_, v);
  }
  analogWrite(pin_, target_volt);
  speed_ = target_speed;
}

void Motor::stop() {
  slowDown(0);
}
