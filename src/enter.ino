void button() {//selector button
  current = digitalRead(enter);
  if (current == 0 && previous == 1 && (millis() - firstTime) > 200) {
    firstTime = millis();
  }
  millis_held = (millis() - firstTime);
  secs_held = millis_held / 1000;
  if (millis_held > 50) {
    if (current == 1 && previous == 0) {

      if (secs_held <= 0) {//short press

        switch (item) {
          case 1:

            if (i < 12) {
              e = 0;
              all_pistons[i] = 0;
              selected_pistons[num_of_pistons - 1 ] = i + 1;

              Serial.println(num_of_pistons - 1);
              for (byte t = i  ; t <= 11; t++) {
                if ( all_pistons[t] != 0) {
                  show_val = all_pistons[t];
                  //  Serial.println(t);
                  break;
                }
              }
              i++;
              if (i == 12) {
                i = 0;
                for (byte t = i  ; t <= 11; t++) {
                  if ( all_pistons[t] != 0) {
                    show_val = all_pistons[t];
                    //  Serial.println(t);
                    break;
                  }
                }
              }
            }
            if (pistons < 12) {
              pistons++;
            }

            /* for (int k = 0; k <= num_of_pistons; k++) {// preventing from entering same value
               if (selected_pistons[k] == i) {
                 wrong = 1;
                 break;
               } else {
                 wrong = 0;
               }
              }

              if (!wrong) {
               selected_pistons[num_of_pistons - 1] = i;
               pistons++;

               lcd.clear();
              }
              else {
               lcd.setCursor ( 10, 1 );
               lcd.print ("wrong");
              }*/
            if (num_of_pistons < 12 && wrong == 0) {
              num_of_pistons++;
            }
            break;
          /* case 2:
             lcd.setCursor ( 0, 1 );
             lcd.print (on_sequence[sequence_on]);
             delay(1500);
             break;*/
          case 3:
            lcd.setCursor ( 0, sequence_off + 1 );
            lcd.print (off_sequence[sequence_off]);
            delay(1500);
            break;
          case 4://run time
            lcd.setCursor ( 0, 1 );
            // lcd.print (run_time) + lcd.print ("ms");
            if (run_time <= 1000) {
              lcd.print (run_time) + lcd.print ("ms");
            }
            else {
              float l = run_time / 1000.00;
              lcd.print (l, 3) + lcd.print ("s");
            }
            delay(1500);
            break;
          /*case 5:// delay
            lcd.setCursor ( 0, 1 );
            // lcd.print (delay_time) + lcd.print ("ms");
            if (delay_time <= 1000) {
              lcd.print (delay_time) + lcd.print ("ms");
            }
            else {
              float l = delay_time / 1000.00;
              lcd.print (l, 3) + lcd.print ("s");
            }
            delay(1500);
            break;*/
          case 6:
            lcd.setCursor ( 0, 1 );
            // lcd.print (delay_time) + lcd.print ("ms");
            if (final_delay_time <= 1000) {
              lcd.print (final_delay_time) + lcd.print ("ms");
            }
            else {
              float l = final_delay_time / 1000.00;
              lcd.print (l, 3) + lcd.print ("s");
            }
            delay(1500);
            break;
        }
      }


      /*   if (secs_held >= 1 && secs_held < 3) {
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
      /* case 3:

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
           lcd.print ("Run time");
           lcd.setCursor ( 5, 1 );
           lcd.print ("saved!");
           delay(1500);
           break_menu = 1;
         }
         break;*/
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
         break;
        case 6:

        // confirmon sequence
        //if (final_delay_time != 0) {
        lcd.clear();
        lcd.setCursor ( 1, 0 );
        lcd.print ("   Final Delay ");
        lcd.setCursor ( 5, 1 );
        lcd.print ("saved!");
        delay(1500);
        break_menu = 1;

        // }
        break;
        case 7:

        // confirmon sequence
        if (!selection) {
          lcd.clear();
          lcd.setCursor ( 1, 0 );
          lcd.print ("  Proceed ");

          delay(500);
          break_menu = 1;

        }
        else {
          reset_() ;
          break_menu = 1;
        }
        break;
        case 8:
        if (!selection) {
          lcd.clear();
          lcd.setCursor ( 1, 0 );
          lcd.print ("  Proceed ");

          delay(500);
           pre_set_val=1;
           proceed_=1;

        }
        else {
          reset_() ;
          pre_set_val=1;
        }
        break;
        }


        }*/
      // Button held for 1-3 seconds, print out some info
      // if (secs_held >= 3) {

      //  }

    }
  }
  previous = current;
  prev_secs_held = secs_held;
}
// ===============================================================================

