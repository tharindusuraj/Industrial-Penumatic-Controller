void button_right() {//right button
  current_right = digitalRead(right);
  if (current_right == 0 && previous_right == 1 && (millis() - firstTime_right) > 200) {
    firstTime_right = millis();
  }
  millis_held = (millis() - firstTime_right);
  secs_held_right = millis_held / 1000;
  if (millis_held > 50) {
    if (current_right == 1 && previous_right == 0) {

      if (secs_held_right <= 0) {

        switch (item) {
          case 1:
            side = 0;
            break;

          case 10:
            if (pattern_no < p) {
              pattern_no++;
            }

            lcd.setCursor ( 15, 1 );
            lcd.print(" ");
            break;
          case 9:
            if (!selection) {
              selection = 1;
            }
            break;
          case 11:
            /*  if (delete_pattern < 11) {
                delete_pattern ++;
                if (saved_patterns[delete_pattern - 1] == 0) {

                }
              }*/
            if (delete_pattern < 11 && selection) {
             
              // //123Serial.println(i);

              for (byte t = delete_pattern  ; t < 10; t++) {
                ////123Serial.print("delete_pattern");
                ////123Serial.println(t);
                if ( saved_patterns[t - 1] == 1) {
                 // //123Serial.println(saved_patterns[t - 1]);
                  show_val_delete = t;
                  // //123Serial.println(t);
                  break;
                }
              }
               delete_pattern++;
              lcd.setCursor (5, 1);
              lcd.print ("  ");
              lcd.setCursor (9, 2);
              lcd.print ("      ");
            }
            break;
        }
      }

      // If the button was held for 3-6 seconds blink LED 10 times
      /*   if (secs_held_right >= 1 && secs_held_right < 3) {


         }
         // Button held for 1-3 seconds, print out some info
         if (secs_held_right >= 3) {

         }*/

    }
  }
  previous_right = current_right;
  prev_secs_held_right = secs_held_right;
}
// ===============================================================================

