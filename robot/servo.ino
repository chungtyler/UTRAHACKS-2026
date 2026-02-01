int servo1_pin = 3;
int servo2_pin = 0;

void servo_begin() {
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
}