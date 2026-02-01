#include "MotorClass.h"

MotorClass motorL(11, 9, 10);
MotorClass motorR(3, 5, 6);

int motor_speed = 105;
double turn_45_duration = 575 / 105 * motor_speed;
double turn_90_duration = 800 / 105 * motor_speed;
double turn_180_duration = 1900 / 105 * motor_speed;

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
  motorL.rotate(3, motor_speed); motorR.rotate(2, motor_speed);
}

void turn_right() {
  motorL.rotate(2, motor_speed);motorR.rotate(3, motor_speed);
}

void stop() {
  motorL.rotate(0, 0); motorR.rotate(0, 0);
}

void stop_for_duration(double duration) {
  double start_time = millis();
  while ((millis() - start_time) < duration * 1000) {
    stop();
    delay(10);
  }
}

void go_forward_for_duration(double duration) {
  double start_time = millis();
  while ((millis() - start_time) < duration * 1000) {
    go_forward();
    delay(10);
  }

  //stop_for_duration(0.2);
}

void go_backward_for_duration(double duration) {
  double start_time = millis();
  while ((millis() - start_time) < duration * 1000) {
    go_backward();
    delay(10);
  }

  //stop_for_duration(0.2);
}

void rotate(int angle) {
  double start_time = millis();
  
  // Check which angle is set
  double turn_duration;
  if (abs(angle) == 45) {
    turn_duration = turn_45_duration;
  } else if (abs(angle) == 90) {
    turn_duration = turn_90_duration;
  } else if (abs(angle) == 180) {
    turn_duration = turn_180_duration;
  }

  // Keep rotating until time is passed
  while ((millis() - start_time) < turn_duration) {
    if (angle < 0) { // Negative - CW
      turn_right();
    } else {
      turn_left();
    }
    delay(10);
  }

  stop_for_duration(1);
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
