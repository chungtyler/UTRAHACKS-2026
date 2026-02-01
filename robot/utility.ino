void pick_up_box_sequence() {
  // Position robot
  //go_forward_for_duration(0.25);
  rotate(-90);
  //go_backward_for_duration(0.2);

  // pick up box
  drop_fork();
  go_forward_for_duration(1);
  lift_fork();

  // return to position
  go_backward_for_duration(1.3);
  delay(100);
  rotate(90);
}

void drop_off_box_sequence() {
  // Position robot
  rotate(90);
  go_forward_for_duration(1);

  // drop off box
  drop_fork();
  go_backward_for_duration(1.5);
  delay(100);
  lift_fork();

  // return to position
  //go_forward_for_duration(2);
  rotate(-90);
}

void rotate_to_wall() {
  double previous_distance2 = 999999999;
  double distance;
  previous_distance = 0;
  int counter;

  while (true) {
    turn_right();
    delay(10);
    distance = max(60, filtered_distance());

    if ((distance < previous_distance2) && (abs(distance - previous_distance2) < 0.1)) {
      previous_distance2 = distance;
    } else {
      counter++;
      if (counter > 4) {
        stop_for_duration(1);
        break;
      }
    }
  }
}