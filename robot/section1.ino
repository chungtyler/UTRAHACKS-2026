// [Get To Target]
void section1_partA() {
   lift_fork();

  // Black line -> green line
  String color;
  while (true) {
    line_track();
    color = get_colors();
    if (color == "red") {
      rotate(-45);
      go_forward_for_duration(1);
      break;
    }
  }

  // Green line -> Blue Box
  while (true) {
    line_track();
    color = get_colors();
    if (color == "blue") {
      pick_up_box_sequence();
      delay(100);
      rotate(-180);
      drop_off_box_sequence();
      break;
    }
  }

  // Blue Box -> End of Black Ramp
  go_forward_for_duration(4);
  while (true) {
    line_track();
    color = get_colors();
    if (color == "blue") {
      break;
    }
  }

  // Target blue -> target black
  while (true) {
    go_forward();
    color = get_colors();
    if (color == "black") {
      break;
    }
  }
}

// [Get to Center and Ball to Wall]
void section1_partB() {
  rotate_to_wall();

  // Outer target -> Center line
  String color;
  bool at_black_box = false;
  double distance;
  while (true) {
    go_forward();
    color = get_colors();
    if (color == "black") {
      at_black_box = true;
      break;
    }
    distance = read_distance();
    if (distance < 42) {
      break;
    }
  }
  stop();
  delay(100);

  // Center line -> black box
  drop_fork();
  if (!at_black_box) {
    rotate(90);
    while (true) {
      go_forward();
      color = get_colors();
      if (color == "black") {
        go_forward_for_duration(0.25);
        rotate(-90); //rotate_to_wall();
      }
    }
  }

  // black box -> blue border
  while (true) {
    go_forward();
    color = get_colors();
    if (color == "blue") {
      stop();
      break;
    }
  }
}

// [Return To Start]
void section1_partC() {
  // Wall to ramp orientation
  go_backward_for_duration(1.5);
  rotate_to_wall();
  rotate(180);

  // Wall -> ramp
  String color;
  while (true) {
    go_forward();
    color = get_colors();
    if (color == "blue") {
      stop_for_duration(1);
      break;
    }
  }

  // Target -> ramp
  go_forward_for_duration(4);

  // ramp -> start
  while (true) {
    line_track();
    color = get_colors();
    if (color == "black") {
      stop_for_duration(1);
      break;
    }
  }

  rotate(180);
}