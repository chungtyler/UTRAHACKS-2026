// double distance = 0;

// void section1() {
//   // Follow green line
//   // Go straight up ramp
//   // Once blue detected keep going until black detected
// }

// void balls_to_the_walls() {
//   double dist = 99999999;
//   int counter = 0;

//   while (true) {
//     turn_right();
//     delay(10);
//     double new_dist = filtered_distance();

//     if (new_dist < dist) {
//       dist = new_dist;
//     } else {
//       break;
//     }
//   }

//   while(true) {
//     go_forward();
//     color_read();
//     String cs = get_colors();

//     if (cs=="black") {
//       break;
//     }

//     double new_dist = filtered_distance();

//     if (new_dist <45) {
//       break;
//     }
//   }

//   turn_left();

//   delay(750);

//    while(true) {
//     go_forward();
//     color_read();
//     String cs = get_colors();

//     if (cs=="black") {
//       break;
//     }

//     }

//   turn_right();
//   delay(750);

//   while(true) {
//     go_forward();
//     color_read();
//     String cs = get_colors();

//     if (cs == "blue") {
//       break;
//     }
//   }

//   turn_right();
//   delay(1500);

//   go_forward();

//   while(true) {
//     go_forward();
//     color_read();
//     String cs = get_colors();

//     if (cs == "red") {
//       break;
//     }
//   } 
// }

// // while(true) {
//   //   color_read();
//   //   String cs = get_colors();

//   //   turn_right();

//   //   delay(20);

//   //   color_read();
//   //   String ct = get_colors();

//   //   if (ct != cs)  {
//   //     break;
//   //   }
//   // }
  
//   // int time1 = millis();

//   // while (true) {
//   //   color_read();
//   //   String cs = get_colors();

//   //   turn_left();

//   //   delay(20);

//   //   color_read();
//   //   String ct = get_colors();

//   //   if (ct != cs)  {
//   //     break;
//   //   }
//   // }

//   // int time2 = millis();

//   // turn_right();
//   // delay((time2-time1)/2);
  
//   // go_forward();


//   // while(true) {
//   //   color_read();
//   //   String cs = get_colors();

//   //   if (cs == "black") {
//   //     break;
//   //   }
//   // }