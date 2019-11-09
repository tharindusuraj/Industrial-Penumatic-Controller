void next_button() {//selector button
  current_next = digitalRead(next);
  if (current_next == 0 && previous_next == 1 && (millis() - firstTime_next) > 200) {
    firstTime_next = millis();
  }
  millis_held_next = (millis() - firstTime_next);
  secs_held_next = millis_held_next / 1000;
  if (millis_held_next > 50) {
    if (current_next == 1 && previous_next == 0) {

      if (secs_held_next <= 0) {//short press

        switch (item) {
          case 1:
            if (!wrong) {
              if (pistons != 0 ) {
                lcd.clear();
                lcd.setCursor ( 0, 0 );
                lcd.print ("pistons selected");
                lcd.setCursor ( 0, 1 );
                lcd.print(pistons);
                delay(1500);
                break_menu = 1;
              }
              else {
                lcd.clear();
                lcd.setCursor ( 0, 0 );
                lcd.print (" Invalid entry");
                lcd.setCursor ( 0, 1 );
                lcd.print("Select a piston");
                delay(1500);
                lcd.clear();
              }
            }
            break;
          /* case 2:

             // confirmon sequence
             lcd.clear();
             lcd.setCursor ( 2, 0 );
             lcd.print ("ON sequence");
             lcd.setCursor ( 5, 1 );
             lcd.print ("saved!");
             delay(1500);
             break_menu = 1;
             break;*/
          case 3:

            // confirmon sequence
            lcd.clear();
            lcd.setCursor ( 1, 0 );
            lcd.print ("Retract order");
            lcd.setCursor ( 5, 1 );
            lcd.print ("saved!");
            delay(1500);
            break_menu = 1;
            break;
          case 4:

            // confirmon sequence
            if (run_time != 0) {
              lcd.clear();
              lcd.setCursor ( 1, 0 );
              lcd.print ("    Run time");
              lcd.setCursor ( 5, 1 );
              lcd.print ("saved!");
              delay(1500);
              break_menu = 1;
            }
            break;
          /* case 5:

             // confirmon sequence
             //  if (delay_time != 0) {
             lcd.clear();
             lcd.setCursor ( 1, 0 );
             lcd.print ("Delay time");
             lcd.setCursor ( 5, 1 );
             lcd.print ("saved!");
             delay(1500);
             break_menu = 1;

             // }
             break;*/
          case 6:

            // confirmon sequence
            //if (final_delay_time != 0) {
            lcd.clear();
            lcd.setCursor ( 1, 0 );
            lcd.print ("  Final Delay ");
            lcd.setCursor ( 5, 1 );
            lcd.print ("saved!");
            delay(1500);
            break_menu = 1;

            // }
            break;
          case 7:

            // confirmon sequence
            if (final_ == 0) {
              lcd.clear();
              lcd.setCursor ( 1, 0 );
              lcd.print ("  Proceed ");

              delay(500);
              break_menu = 1;

            }
            else if (final_ == 1) {
              reset_() ;
              break_menu = 1;
            }
            else if (final_ == 2 && p < 11) {
              //  p++;
              for (byte t = 1  ; t < 10; t++) {

                if ( saved_patterns[t - 1] == 0) {
                  p = t;
                  break;
                }
              }
              new_pattern();


              lcd.clear();
              lcd.setCursor ( 0, 0 );
              lcd.print("Pattern number");
              lcd.setCursor ( 5, 1 );
              lcd.print (p);
              lcd.setCursor ( 1, 2 );
              lcd.print ("saved!");
              delay(1500);
              lcd.clear();
            }
            break;

          case 8:
            if (first_ == 0) {
              reset_() ;
              pre_set_val = 1;
              break_menu = 1;
            }
            /* else if (first_ == 1) {
               //pre_set_val = 1;
               break_menu = 1;
               lcd.clear();
              }*/
            else if ((first_ == 2 || first_ == 1) && something_in_memory) {
              pre_set_val = 0;
              break_menu = 1;
              lcd.clear();
            }
            else if ((first_ == 2 || first_ == 1) && !something_in_memory) {
              lcd.clear();
              lcd.setCursor ( 1, 0 );
              lcd.print ("No Patterns!");
              delay(500);
              lcd.clear();
            }
            /*else if (first_ == 3) {
              pre_set_val = 0;
              break_menu = 1;
              lcd.clear();
              }*/
            break;

          case 9:
            if (!selection) {
              pre_set_val = 1;
              break_menu = 1;
              lcd.clear();
              lcd.setCursor ( 1, 0 );
              lcd.print ("  Proceed ");
              delay(500);

            }
            else {
              // reset_() ;
              pre_set_val = 1;
              break_menu = 1;
            }
            break;



          case 10:
            if (!selection) {
              run_saved_pattern();
            }
            else {
              pre_set_val = 1;
            }
             pre_set_val = 1;
            break_menu = 1;
            break;

          case 11:
            //saved_patterns[delete_pattern - 1] = 0;
            if (selection) {
              //  delete_saved_pattern();
              saved_patterns[show_val_delete - 1] = 0;

              EEPROM.update(show_val_delete - 1, 0 );
              /*for (byte t = show_val_delete  ; t < 10; t++) {

                if ( saved_patterns[t - 1] == 1) {

                  show_val_delete = t;

                  break;
                }
                }*/
              for (byte t = 1  ; t < 10; t++) {
                if ( saved_patterns[t - 1] == 1) {
                  p = t;
                  //123Serial.print( "p ");
                  //123Serial.println( p);

                  something_in_memory = 1;
                  break;
                }
                else  {
                something_in_memory = 0;
              }
            }
            lcd.clear();
              lcd.setCursor ( 1, 0 );
              lcd.print ("Pattern  ");
              lcd.setCursor ( 10, 0 );
              lcd.print (show_val_delete);
              lcd.setCursor ( 1, 0 );
              lcd.print ("deleted  ");
              delay(1000);
              lcd.clear();
              pre_set_val = 1;
              break_menu = 1;
            }
            else {
              pre_set_val = 1;
              break_menu = 1;
            }

            break;
        }
      }


      /* if (secs_held_next >= 1 && secs_held_next < 3) {



        }*/
      // Button held for 1-3 seconds, print out some info
      // if (secs_held_next >= 3) {

      //  }

    }
  }
  previous_next = current_next;
  prev_secs_held_next = secs_held_next;
}
// ===============================================================================

