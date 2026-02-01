void setup() {
  Serial.begin(9600);
  motor_begin();
  servo_begin();
  color_begin();
  ultrasonic_begin();

  //lift_fork();
  // Call code once
  //section1();
  //section2();
  //delay(500);
  //rotate(180);
  delay(500);
  rotate_to_wall();
}

void loop() {
  //IR_read();
  //delay(100);
  // String color = get_colors();
  // Serial.println(color);
  // delay(100);
}