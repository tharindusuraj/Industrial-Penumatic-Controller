/*void first_menu() {
  item = 9;
  while (item == 9) {
    button();
    button_up();
    button_down();
    next_button();


    unsigned long current_millis = millis();
    if (current_millis - prev_millis >= interval) {
      prev_millis = current_millis;
      lcd.setCursor ( 0, 0 );
      lcd.print (first[0]);
      lcd.setCursor ( 0, 1 );
      lcd.print (first[1]);
      lcd.setCursor ( 0, 2 );
      lcd.print (first[2]);

      if (state ) {
        lcd.setCursor ( 0, first_  );
        lcd.print (first[first_]);// from the label of piston
        state = 0;
      }
      else {
        // lcd.clear();
        lcd.setCursor ( 0, first_  );
        lcd.print ("                ");// from the label of piston
        state = 1;
      }
    }

  }
  }*/

/*void pre_settings() {
  item = 8;
  for (byte t = 0; t < 12; t++) {
    selected_pistons[t] = EEPROM.read(t);
  }
  for (byte t = 12; t < 24; t++) {
    delays[t] = EEPROM.read(t);
  }

  sequence_off = EEPROM.read(24);
  run_time = EEPROM.read(25);
  final_delay_time = EEPROM.read(26);
  pistons = EEPROM.read(27);
 
  for ( byte a = 0; a < pistons; a++) {

    lcd.setCursor ( g, 2 + m );
    lcd.print(selected_pistons[a]) + lcd.print (" ");
    if (selected_pistons[a] > 9) {
      g += 3;
    } else {
      g += 2;
    }
    if (g > 10) {
      m = 1;
      g = 0;
    }
  }

  while (1) {
    button_left();
    button_right();
    next_button();
    if (pre_set_val) {
      break;
    }

    lcd.home ();
    lcd.print("  Pre Settings");
    unsigned long current_millis = millis();
    if (!selection) {

      lcd.setCursor ( 10, 1 );
      lcd.print (final_slection[1]);
    }
    else {
      lcd.setCursor ( 0, 1 );
      lcd.print (final_slection[0]);

    }
    if (current_millis - prev_millis >= interval) {
      prev_millis = current_millis;
      if (state ) {
        if (!selection) {
          lcd.setCursor ( 0, 1 );
          lcd.print (final_slection[0]);
        }
        else {
          lcd.setCursor ( 10, 1 );
          lcd.print (final_slection[1]);
        }

        state = 0;
      }
      else {
        // lcd.clear();
        if (!selection) {
          lcd.setCursor ( 0, 1 );
          lcd.print ("       ");
        }
        else {
          lcd.setCursor ( 10, 1 );
          lcd.print ("     ");
        }
        state = 1;
      }
    }

  }
}*/
/*
   while (1) {
        unsigned long current_millis = millis();
        if (current_millis - prev_millis >= delays[val]) {
          prev_millis = current_millis;
          if (run_once ) {
           // select_relay_up(selected_pistons[val]);
            unsigned long current_millis1 = millis();
            if (current_millis1 - prev_millis1 >= run_time) {
              prev_millis1 = current_millis1;
              if (state ) {
                digitalWrite(relay_up[selected_pistons[val]], 1);
               // lcd.setCursor ( selected_pistons[val], 2 );
               // lcd.print("1");
                state = 0;
              }
              else {
                digitalWrite(relay_up[selected_pistons[val]], 0);
                //lcd.setCursor ( selected_pistons[val], 2 );
               // lcd.print(" ");

              //  break;
              }
            }
            run_once = 0;
          }
          else {
            //state = 1;
            break;
          }
        }
      }
   /
  /*
    while (1) {
        unsigned long current_millis = millis();
        if (current_millis - prev_millis >= delays[val]) {
          prev_millis = current_millis;
          if (run_once ) {

            if (sequence_off == 0) {
              select_relay_down(selected_pistons[val]);
            }
            else if (sequence_off == 1) {
              select_relay_down(selected_pistons[(pistons - 1) - val]);
            }
            else if (sequence_off == 2) {
              for (byte q = 0; q < pistons; q++) {
                digitalWrite(selected_pistons[q], 1);
              }
              break;
            }
            run_once = 0;
          }
          else {
            //state = 1;
            break;
          }
        }
      }
*/




/*
  while (1) {
            button_left();
            button_right();
            next_button();
            if (pre_set_val) {
              break;
            }

            lcd.home ();
            lcd.print("  Pre Settings");
            unsigned long current_millis = millis();
            if (!selection) {

              lcd.setCursor ( 10, 1 );
              lcd.print (final_slection[1]);
            }
            else {
              lcd.setCursor ( 0, 1 );
              lcd.print (final_slection[0]);

            }
            if (current_millis - prev_millis >= interval) {
              prev_millis = current_millis;
              if (state ) {
                if (!selection) {
                  lcd.setCursor ( 0, 1 );
                  lcd.print (final_slection[0]);
                }
                else {
                  lcd.setCursor ( 10, 1 );
                  lcd.print (final_slection[1]);
                }

                state = 0;
              }
              else {
                // lcd.clear();
                if (!selection) {
                  lcd.setCursor ( 0, 1 );
                  lcd.print ("       ");
                }
                else {
                  lcd.setCursor ( 10, 1 );
                  lcd.print ("     ");
                }
                state = 1;
              }
            }

          }
*/

