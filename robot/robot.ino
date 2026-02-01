#include "Servo.h"

// Initialize actuators
Servo servo1;

// Initialize sensor reading variables
int IRL_signal = 0;
int IRR_signal = 0;

struct color_sensor {
  int is_red;
  int is_green;
  int is_blue;
};

double distance = 0;
double alpha = 0.99;

void setup() {
  Serial.begin(9600);
  motor_begin();
  servo_begin();
  color_begin();
  ultrasonic_begin();
}

void loop() {
  line_track();
}

void line_track() {
  go_forward();

  IR_read();

  Serial.println(IRL_signal);
  Serial.println(IRR_signal);

  while (!(IRL_signal && IRR_signal)) {
    
    if (!IRL_signal) {
      turn_left();
    } else {
      turn_right();
    }

    delay(50);
    IR_read();
  }

}