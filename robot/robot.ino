void setup() {
  Serial.begin(9600);
  motor_begin();
  servo_begin();
  color_begin();
  ultrasonic_begin();

  lift_fork();
  //section1();
  section2();
}

void loop() {
}