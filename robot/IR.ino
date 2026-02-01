int IRL = A1;
int IRR = A0;

int IRL_threshold = 512;
int IRR_threshold = 512;

void IR_read() {
  IRL_signal = analogRead(IRL);//digitalRead(IRL);
  Serial.print("Left: ");
  //Serial.print(IRL_signal);
  IRL_signal = convert_to_binary(IRL_signal, IRL_threshold);
  Serial.print(IRL_signal);
  IRR_signal = analogRead(IRR);//digitalRead(IRR);
  Serial.print(" Right: ");
  //Serial.println(IRR_signal);
  IRR_signal = convert_to_binary(IRR_signal, IRR_threshold);
  Serial.println(IRR_signal);
}

int convert_to_binary(int signal, int threshold) {
  if (signal > threshold) {
    return 1;
  } else {
    return 0;
  }
}