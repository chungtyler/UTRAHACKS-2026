int trigger_pin = 0;
int echo_pin = 1;

double previous_distance = 0;

void ultrasonic_begin() {
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

double filtered_distance(double alpha) {
  double distance = read_distance();
  double filtered_distance = alpha * previous_distance + (1-alpha) * distance;
  previous_distance = filtered_distance;
  return filtered_distance;
}

double read_distance() {
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  double duration = pulseIn(echo_pin, HIGH, 30000);
  if (duration == 0) {
    return 0;
  }

  double distance = (duration * 0.0343) / 2.0;
  return distance;
}