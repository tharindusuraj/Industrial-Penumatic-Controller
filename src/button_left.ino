void button_left() {//left button
  current_left = digitalRead(left);
  if (current_left == 0 && previous_left == 1 && (millis() - firstTime_left) > 200) {
    firstTime_left = millis();
  }
  millis_held = (millis() - firstTime_left);
  secs_held_left = millis_held / 1000;
  if (millis_held > 50) {
    if (current_left == 1 && previous_left == 0) {

      if (secs_held_left <= 0) {
        switch (item) {
          case 1:
            side = 1;
            break;

          case 10:
            if (pattern_no > 1) {
              pattern_no--;
            }
            lcd.setCursor ( 12, 1 );
            lcd.print(" ");
            break;
          case 9:
            if (selection) {
              selection = 0;
            }
            break;
          case 11:
            /*  if (delete_pattern < 11) {
                delete_pattern ++;
                if (saved_patterns[delete_pattern - 1] == 0) {

                }
              }*/
            if (show_val_delete > 1 && selection) {
             
              // //123Serial.println(i);

              for (byte t = delete_pattern  ; t >= 0; t--) {
                if ( saved_patterns[delete_pattern - 1] == 1) {
                  show_val_delete = delete_pattern - 1;
                  // //123Serial.println(t);
                  break;
                }
              }
               delete_pattern--;
              lcd.setCursor (5, 1);
              lcd.print ("  ");
              lcd.setCursor (9, 2);
              lcd.print ("      ");
            }
            break;
        }


      }

      // If the button was held for 3-6 seconds blink LED 10 times
      if (secs_held_left >= 1 && secs_held_left < 3) {


      }
      // Button held for 1-3 seconds, print out some info
      /* if (secs_held_left >= 3) {

        }*/

    }
  }
  previous_left = current_left;
  prev_secs_held_left = secs_held_left;
}
// ===============================================================================

