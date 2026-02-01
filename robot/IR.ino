int IRL = A1;
int IRR = A0;

int IRL_threshold = 512;
int IRR_threshold = 512;

// Initialize sensor reading variables
int IRL_signal = 0;
int IRR_signal = 0;

void IR_read() {
  IRL_signal = analogRead(IRL);
  // Serial.print("IRL: ");
  // Serial.print(IRL_signal);
  IRL_signal = convert_to_binary(IRL_signal, IRL_threshold);
  IRR_signal = analogRead(IRR);
  // Serial.print(" IRR: ");
  // Serial.println(IRR_signal);
  IRR_signal = convert_to_binary(IRR_signal, IRR_threshold);
}

int convert_to_binary(int signal, int threshold) {
  if (signal < threshold) {
    return 1;
  } else {
    return 0;
  }
}

void line_track() {
  go_forward();
  delay(150);
  IR_read();

  //Serial.println(IRL_signal);
  //Serial.println(IRR_signal);

  while (!(IRL_signal && IRR_signal)) {
    if (!IRL_signal) {
      turn_left();
    } else if (!IRR_signal) {
      turn_right();
    }

    delay(50);
    IR_read();
  }
}