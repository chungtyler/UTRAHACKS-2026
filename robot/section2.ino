void section2() {

  // Line -> Blue Box
  String color;
  while (true) {
    line_track();
    color = get_colors();
    Serial.println(color);
    if (color == "blue") {
      pick_up_box_sequence();
      break;
    }
  }

  // Obstacle Avoidance
  double distance;
  while (true) {
    line_track();
    distance = read_distance();
    if (distance < 16) {
      go_around();
      break;
    }
  }

  // Obstacle Avoidance
  while (true) {
    line_track();
    distance = read_distance();
    if (distance < 16) {
      go_around();
      break;
    }
  }

  // Obstacle -> Blue Square
  while (true) {
    line_track();
    color = get_colors();
    if (color == "blue") {
      drop_off_box_sequence();
      break;
    }
  }

  // red -> start
  while (true) {
    line_track();
    color = get_colors();
    if (color == "black") {
      stop_for_duration(2);
      break;
    }
  }

  rotate(180);
}

void go_around() {
  rotate(45);
  go_forward_for_duration(2.2);
  rotate(-45);
  //go_forward_for_duration(1.5);
  //rotate(-90);
  
  String color;
  while (true) {
    go_forward();
    color = get_colors();
    Serial.println(color);
    if (color != "white") {
      //stop_for_duration(1);
      //stop();
      break;
    }
  }
}
