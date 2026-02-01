// Color sensor pinout
int S0 = 13;
int S1 = 12;
int S2 = 8;
int S3 = 7;
int sensor_out = 2;

// Sensor readings
int red_frequency = 0;
int green_frequency = 0;
int blue_frequency = 0;

// Mapping values
int red_color = 0;
int green_color = 0;
int blue_color = 0;

int sensor_read_delay = 20;

// Calibration
int black_max = 700;
int white_min = 600;
// int red_min = 0;
// int red_max = 0;
// int green_min = 0;
// int green_max = 0;
// int blue_min = 0;
// int blue_max = 0;

void color_begin() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensor_out, INPUT);

  //Frequency Scaling
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH);
}

String get_colors() {
  color_read();
  if (red_color > black_max && blue_color > black_max && green_color > black_max) {
    return "black";
  } else if (red_color < white_min && blue_color < white_min && green_color < white_min) {
    return "white";
  } else {
    if (red_color < green_color && red_color < blue_color) {
      return "red";
    } else if (green_color < red_color && green_color < blue_color) {
      return "green";
    } else if (blue_color < red_color && blue_color < green_color) {
      return "blue";
    }
  }
  return "unknown";
}
// Get sensor readings
void color_read() {
  // Red filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  //delay(sensor_read_delay);

  red_frequency = pulseIn(sensor_out, LOW);
  red_color = red_frequency;//map(red_frequency, red_min, red_max, 255, 0);
  delay(sensor_read_delay);

  // Green filter
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  //delay(sensor_read_delay);

  green_frequency = pulseIn(sensor_out, LOW);
  green_color = green_frequency;//map(green_frequency, green_min, green_max, 255, 0);
  delay(sensor_read_delay);

  // Blue filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  //delay(sensor_read_delay);

  blue_frequency = pulseIn(sensor_out, LOW);
  blue_color = blue_frequency;//map(blue_frequency, blue_min, blue_max, 255, 0);
  delay(sensor_read_delay);
  //print_colors();

  //delay(100);
}

void print_colors() {
  Serial.print("Green: ");
  Serial.print(green_color);
  Serial.print(" Red: ");
  Serial.print(red_color);
  Serial.print(" Blue: ");
  Serial.println(blue_color);
}