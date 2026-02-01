void section2() {

  // Line -> Blue Box
  String color;
  int counter = 0;
  while (true) {
    line_track();
    color = get_colors();
    Serial.println(color);
    if (color == "red") {
      pick_up_box_sequence();
      break;
    }
  }

  // Obstacle Avoidance
  double distance;
  while (true) {
    line_track();
    distance = read_distance();
    if (distance < 11) {
      go_around();
      break;
    }
  }

  // Obstacle Avoidance
  while (true) {
    line_track();
    distance = read_distance();
    if (distance < 11) {
      go_around();
      break;
    }
  }

  // Obstacle -> Blue Square
  while (true) {
    line_track();
    color = get_colors();
    if (color == "red") {
      drop_off_box_sequence();
      break;
    }
  }

//   // ramp -> start
//   while (true) {
//     line_track();
//     color = get_colors();
//     if (color == "black") {
//       stop_for_duration(1);
//       break;
//     }
//   }

//   rotate(180);
// }

void go_around() {
  rotate(90);
  go_forward_for_duration(1.7);
  rotate(-90);
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
