void button_down() {//down button
  current_down = digitalRead(down);
  if (current_down == 0 && previous_down == 1 && (millis() - firstTime_down) > 200) {
    firstTime_down = millis();
  }
  millis_held = (millis() - firstTime_down);
  secs_held_down = millis_held / 1000;
  if (millis_held > 50) {
    if (current_down == 1 && previous_down == 0) {

      if (secs_held_down <= 0) {
        /* num_of_pistons++;
          selected_pistons[num_of_pistons] = i;
          previous_down_i = i;*/
        switch (item) {

          case 1:
            if (side) {
              if (i > 0) {
                if (i == 12) {
                  i--;
                }
                i--;
                //123Serial.println(i);
                for (byte t = i  ; t >= 0; t--) {
                  if ( all_pistons[t] != 0) {
                    show_val = all_pistons[t];
                    //123Serial.println(t);
                    break;
                  }
                }
                lcd.setCursor (3, 2);
                lcd.print ("  ");
                lcd.setCursor (9, 2);
                lcd.print ("      ");
              }
            }
            else {
              if (e > 0) {
                e  -= 10;
              }
              delays[show_val - 1] = e;
            }
            break;

          /* case 2:
             if (sequence_on) {
               sequence_on = 0;
             }
             break;*/

          case 3:
            if (sequence_off == 0) {
              sequence_off = 1;
            }
            else  {
              sequence_off = 2;
            }
            break;

          /*  case 4:
              if (run_time > 0) {
                run_time -= 10;
              }
              break;*/
          /* case 5:
             if (delay_time > 0) {
               delay_time -= 10;
             }
             break;*/
          case 6:
            if (final_delay_time > 0) {
              final_delay_time -= 10;
            }
            break;

          case 7:
            if (final_ == 0) {
              final_ = 1;
            }
            else  {
              final_ = 2;
            }
            break;

          case 8:
            if (first_ == 0) {
              first_ = 1;
            }
            else {
              first_ = 2;
            }
          /* switch (first_) {
             case 0:
               first_ = 1;
               break;
             case 1:
               first_ = 2;
               break;
             case 2:
               first_ = 3;
               break;
            }
            break;*/

          case 10:

            if (selection) {
              selection = 0;
            }
            break;
          case 11:
            if (selection) {
              selection = 0;
            }
            break;

            /*case 11:
              if (delete_pattern > 1) {
                delete_pattern --;
              }
              break;*/
        }
      }

      // If the button was held for 3-6 seconds blink LED 10 times
      if (secs_held_down >= 1 && secs_held_down < 3) {
        switch (item) {

          case 1:
            if (!side) {
              while (digitalRead(down) && e > 0) {

                e -= 10;
                delays[show_val - 1] = e;
                lcd.setCursor (9, 2);
                //lcd.print (delay_time) + lcd.print ("ms");
                if (e <= 1000) {
                  lcd.print (e) + lcd.print ("ms ");
                }

                else {
                  float l = e / 1000.00;
                  lcd.print (l, 3) + lcd.print ("s   ");
                }

                delay(50);
              }

            }
            break;
          /* case 4:
             if (run_time > 0) {

               while (digitalRead(down) && run_time > 0) {

                 run_time -= 10;
                 lcd.setCursor ( 0, 1 );
                 //lcd.print (run_time) + lcd.print ("ms");
                 if (run_time <= 1000) {
                   lcd.print (run_time) + lcd.print ("ms");
                 }

                 else {
                   float l = run_time / 1000.00;
                   lcd.print (l, 3) + lcd.print ("s");
                 }

                 delay(50);
               }
             }

             break;*/
          case 5:
            if (delay_time > 0) {

              while (digitalRead(down) && delay_time > 0 ) {

                delay_time -= 10;
                lcd.setCursor ( 0, 1 );
                //lcd.print (delay_time) + lcd.print ("ms");
                if (delay_time <= 1000) {
                  lcd.print (delay_time) + lcd.print ("ms  ");
                }

                else {
                  float l = delay_time / 1000.00;
                  lcd.print (l, 3) + lcd.print ("s  ");
                }

                delay(50);
              }
            }

            break;
          case 6:
            if (final_delay_time > 0) {

              while (digitalRead(down) && final_delay_time > 0 ) {

                final_delay_time -= 10;
                lcd.setCursor ( 0, 1 );
                //  lcd.print (final_delay_time) + lcd.print ("ms");
                if (final_delay_time <= 1000) {
                  lcd.print (final_delay_time) + lcd.print ("ms  ");
                }

                else {
                  float l = final_delay_time / 1000.00;
                  lcd.print (l, 3) + lcd.print ("s  ");                }

                delay(50);
              }
            }

            break;


        }

      }
      // Button held for 1-3 seconds, print out some info
      /*  if (secs_held_down >= 3) {

        }*/

    }
  }
  previous_down = current_down;
  prev_secs_held_down = secs_held_down;
}
// ===============================================================================

