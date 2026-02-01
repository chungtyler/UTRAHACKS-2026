#include "Servo.h"

// Initialize actuators
Servo servo;

int servo_pin = 4;

void servo_begin() {
  servo.attach(servo_pin);
}

void drop_fork() {
  for (int pos = 0; pos <= 95; pos += 5) {
    servo.write(pos);
    delay(15);
  }
}

void lift_fork() {
  for (int pos = 95; pos >= 0; pos -= 5) {
    servo.write(pos);
    delay(15);
  }
}