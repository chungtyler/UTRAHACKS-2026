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
int red_min = 0;
int red_max = 0;
int green_min = 0;
int green_max = 0;
int blue_min = 0;
int blue_max = 0;

void color_begin() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensor_out, INPUT);

  //Frequency Scaling
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

color_sensor detect_colors() {
  color_sensor colors = {0, 0, 0};
  if (red_color > green_color && red_color > blue_color) {
    colors.is_red = 1;
  }
  if (green_color > red_color && green_color > blue_color) {
    colors.is_green = 1;
  }
  if (blue_color > red_color && blue_color > green_color) {
    colors.is_blue = 1;
  }

  return colors;
}
// Get sensor readings
void color_read() {
  // Red filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  delay(sensor_read_delay);

  red_frequency = pulseIn(sensor_out, LOW, 25000);
  red_color = red_frequency;//map(red_frequency, red_min, red_max, 255, 0);

  // Green filter
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  delay(sensor_read_delay);

  green_frequency = pulseIn(sensor_out, LOW, 25000);
  green_color = green_frequency;//map(green_frequency, green_min, green_max, 255, 0);

  // Blue filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  delay(sensor_read_delay);

  blue_frequency = pulseIn(sensor_out, LOW, 25000);
  blue_color = blue_frequency;//map(blue_frequency, blue_min, blue_max, 255, 0);
}

void print_colors() {
  Serial.print("Green: ");
  Serial.print(green_color);
  Serial.print("Red: ");
  Serial.print(red_color);
  Serial.print("Blue: ");
  Serial.println(blue_color);
}