void button_up() {

  current_up = digitalRead(up);
  if (current_up == 0 && previous_up == 1 && (millis() - firstTime_up) > 200) {
    firstTime_up = millis();
  }
  millis_held = (millis() - firstTime_up);
  secs_held_up = millis_held / 1000;
  if (millis_held > 50) {
    if (current_up == 1 && previous_up == 0) {

      if (secs_held_up <= 0) {
        /* num_of_pistons++;
          selected_pistons[num_of_pistons] = i;
          previous_up_i = i;*/

        switch (item) {
          case 1:
            if (side) {
              if (i < 12) {
                i++;
                // //123Serial.println(i);

                for (byte t = i  ; t <= 11; t++) {
                  if ( all_pistons[t] != 0) {
                    show_val = all_pistons[t];
                    // //123Serial.println(t);
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
              e  += 10;
              delays[show_val - 1] = e;
            }
            /* if( all_pistons[i-1]==0{


              }*/
            break;
          /*case 2:

            if (!sequence_on) {
              sequence_on = 1;
            }
            break;*/
          case 3:
            if (sequence_off == 2) {
              sequence_off = 1;
            }
            else  {
              sequence_off = 0;
            }


            break;
          /* case 4:
             if (run_time < 10000) {
               run_time += 10;
             }
             break;*/
          /* case 5:
             if (delay_time < 10000) {
               delay_time += 10;
             }
             break;*/

          case 6:
            if (final_delay_time < 10000) {
              final_delay_time += 10;
            }
            break;
          case 7:
            if (final_ == 2) {
              final_ = 1;
            }
            else  {
              final_ = 0;
            }
            break;
          case 8:
            if (first_ == 2) {
              first_ = 1;
            }
            else {
              first_ = 0;
            }
            /* switch (first_) {
               case 1:
                 first_ = 0;
                 break;
               case 2:
                 first_ = 1;
                 break;
               case 3:
                 first_ = 2;
                 break;
              }*/

            break;
          case 10:
            if (!selection) {
              selection = 1;
            }

            break;
          case 11:

            if (!selection) {
              selection = 1;
            }

            break;


        }



      }

      // If the button was held for 3-6 seconds blink LED 10 times
      if (secs_held_up >= 1 && secs_held_up < 3) {
        switch (item) {
          case 1:
            if (!side) {
              while (digitalRead(up) && delay_time < 10000) {

                e += 10;
                delays[show_val - 1] = e;
                lcd.setCursor (9, 2);
                //lcd.print (delay_time) + lcd.print ("ms");
                if (e <= 1000) {
                  lcd.print (e) + lcd.print ("ms");
                }

                else {
                  float l = e / 1000.00;
                  lcd.print (l, 3) + lcd.print ("s");
                }

                delay(50);
              }

            }
            break;
          /* case 2:

             break;
            case 3:

             break;
            case 4:

             while (digitalRead(up) && run_time < 10000) {

               run_time += 10;
               lcd.setCursor ( 0, 1 );
               if (run_time <= 1000) {
                 lcd.print (run_time) + lcd.print ("ms");
               }

               else {
                 float l = run_time / 1000.00;
                 lcd.print (l, 3) + lcd.print ("s");
               }

               delay(50);
             }

             break;*/
          case 5:

            while (digitalRead(up) && delay_time < 10000) {

              delay_time += 10;
              lcd.setCursor ( 0, 1 );
              //lcd.print (delay_time) + lcd.print ("ms");
              if (delay_time <= 1000) {
                lcd.print (delay_time) + lcd.print ("ms");
              }

              else {
                float l = delay_time / 1000.00;
                lcd.print (l, 3) + lcd.print ("s");
              }

              delay(50);
            }

            break;
          case 6:

            while (digitalRead(up) && final_delay_time < 10000) {

              final_delay_time += 10;
              lcd.setCursor ( 0, 1 );
              //lcd.print (final_delay_time) + lcd.print ("ms");
              if (final_delay_time <= 1000) {
                lcd.print (final_delay_time) + lcd.print ("ms");
              }

              else {
                float l = final_delay_time / 1000.00;
                lcd.print (l, 3) + lcd.print ("s");
              }

              delay(50);
            }

            break;

        }

      }
      // Button held for 1-3 seconds, print out some info
      /*if (secs_held_up >= 3) {

        }*/

    }
  }
  previous_up = current_up;
  prev_secs_held_up = secs_held_up;
}
// ===============================================================================

