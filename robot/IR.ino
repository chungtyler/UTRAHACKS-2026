int IRL = 0;
int IRR = 0;

int IRL_threshold = 0;
int IRR_threshold = 0;

void IR_begin() {
  pinMode(IRL, INPUT);
  pinMode(IRR, INPUT);
}

void IR_read() {
  IRL_signal = analogRead(IRL);//digitalRead(IRL);
  IRL_signal = convert_to_binary(IRL_signal, IRL_threshold);
  IRR_signal = analogRead(IRR);//digitalRead(IRR);
  IRR_signal = convert_to_binary(IRR_signal, IRR_threshold);
}

int convert_to_binary(int signal, int threshold) {
  if (signal > threshold) {
    return 1;
  } else {
    return 0;
  }
}