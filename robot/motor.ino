#include "MotorClass.h"

MotorClass motorL(4, 10, 9);
MotorClass motorR(11, 6, 5);

int motor_speed = 150;

void motor_begin() {
  motorL.begin();
  motorR.begin();
}

void go_forward() {
  motorL.rotate(3, motor_speed); motorR.rotate(3, motor_speed);
}

void go_backward() {
  motorL.rotate(2, motor_speed); motorR.rotate(2, motor_speed);
}

void turn_left() {
  motorL.rotate(2, motor_speed); motorR.rotate(3,motor_speed);
}

void turn_right() {
  motorL.rotate(3, motor_speed);motorR.rotate(2, motor_speed);
}

int getMotorState(double value) {
  if (value > 1) {
    // Rotate Clockwise
    return 3;
  } else if (value < -1) {
    // Rotate Counterclockwise
    return 2;
  }
  // Stop motors
  return 0;
}
