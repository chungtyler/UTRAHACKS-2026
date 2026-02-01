#include "Servo.h"
#include <string.h>

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


int color = 0;
// color_read();

void loop() {
  // // line_track();
  balls_to_the_walls();


  // color_sensor colors = get_colors();
  // Serial.print("Red: ");
  // Serial.print(colors.is_red);
  // Serial.print(" Green: ");
  // Serial.print(colors.is_green);
  // Serial.print(" Blue ");
  // Serial.println(colors.is_blue);
  
}


void line_track() {
  go_forward();
  
  delay(150);

  IR_read();

  Serial.println(IRL_signal);
  Serial.println(IRR_signal);

  while (!(IRL_signal && IRR_signal)) {
    
    if (!IRL_signal) {
      turn_right();
    } else if (!IRR_signal) {
      turn_left();
    }

    delay(50);
    IR_read();
  }

}


void balls_to_the_walls() {
  double dist = 1000000000000;
  int counter = 0;

  while (true) {
    turn_right();
    delay(10);
    double new_dist = filtered_distance(0.99);

    Serial.print("NEW: ");
    Serial.println(new_dist);
    Serial.print("OLD: ");
    Serial.println(dist);

    if ((new_dist < dist)) {
      dist = new_dist;
    } else {
      Serial.print("WERE BROKE");
      break;
      // counter++;  

      // if (counter >= 3) {
      //   break;
      // }
    }
  }

  while(true) {
    go_forward();
    color_read();
    String cs = get_colors();

    if (cs=="black") {
      break;
    }

    double new_dist = filtered_distance(0.99);

    if (new_dist <45) {
      break;
    }
  }

  turn_left();

  delay(750);

   while(true) {
    go_forward();
    color_read();
    String cs = get_colors();

    if (cs=="black") {
      break;
    }

    }

  turn_right();
  delay(750);

  while(true) {
    go_forward();
    color_read();
    String cs = get_colors();

    if (cs == "blue") {
      break;
    }
  }

  turn_right();
  delay(1500);

  go_forward();

  while(true) {
    go_forward();
    color_read();
    String cs = get_colors();

    if (cs == "red") {
      break;
    }
  } 

  
  
  // while(true) {
  //   color_read();
  //   String cs = get_colors();

  //   turn_right();

  //   delay(20);

  //   color_read();
  //   String ct = get_colors();

  //   if (ct != cs)  {
  //     break;
  //   }
  // }
  
  // int time1 = millis();

  // while (true) {
  //   color_read();
  //   String cs = get_colors();

  //   turn_left();

  //   delay(20);

  //   color_read();
  //   String ct = get_colors();

  //   if (ct != cs)  {
  //     break;
  //   }
  // }

  // int time2 = millis();

  // turn_right();
  // delay((time2-time1)/2);
  
  // go_forward();


  // while(true) {
  //   color_read();
  //   String cs = get_colors();

  //   if (cs == "black") {
  //     break;
  //   }
  // }
}