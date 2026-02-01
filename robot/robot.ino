#include <Servo.h>

// Initialize actuators
Servo servo1;
Servo servo2;

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
  IR_begin();
  color_begin();
  ultrasonic_begin();
}

void loop() {
  // Read IR and color sensor data
  //IR_read();
  //color_read();
  //print_colors();
  
  // Robot Logic
  //color_sensor colors = detect_colors();
  //distance = filtered_distance(alpha);
  
  //follow_line();
  sweep();
}
int pos =0;
void sweep() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    servo2.write(pos);  
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    servo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void follow_line() {
  if (IRL_signal == HIGH && IRR_signal == HIGH) {
    go_forward();
  } else if (IRL_signal == HIGH && IRR_signal == LOW) {
    turn_right();
  } else if (IRL_signal == LOW && IRR_signal == HIGH) {
    turn_left();
  } else {
    go_forward();
  }
}

void detect_and_pickup_box() {

}