void boot_menu(int item_no) {

  while (!on_menu) {
    /*
       item_no
       1=slect pistons
       2=select on sequence
       3=select off sequence
       4=select run time
       5=select delay between two pistons
       6=select final delay(time to hold afte all pistons up)
       7= proceed or reset
    */
    switch (item_no) {
      case 1:
        lcd.clear();
        while (item_no == 1) {
          button();
          button_up();
          button_left();
          button_right();
          button_down();
          next_button();
          if ( break_menu) {
            item_no = 3;
            item = item_no;
            break_menu = 0;
            break;
          }

          lcd.setCursor ( 1, 0 );
          lcd.print("Select pistons");
          lcd.setCursor ( 2, 1 );
          lcd.print (numbers[num_of_pistons - 1]); // 1st selected piston second selected piston.....
          lcd.setCursor ( 7, 1 );
          lcd.print ("|");
          lcd.setCursor ( 7, 2 );
          lcd.print ("|");
          lcd.setCursor ( 7, 3 );
          lcd.print ("|");
          lcd.setCursor ( 9, 1 );
          lcd.print ("Delay");

          unsigned long current_millis = millis();
          if (current_millis - prev_millis >= interval) {
            prev_millis = current_millis;
            if (side) {
              lcd.setCursor (10, 2);
              if (e <= 1000) {
                lcd.print (delays[show_val - 1]) + lcd.print ("ms  ");
              }

              else {
                float l = e / 1000.00;
                lcd.print (l, 3) + lcd.print ("s  ");
              }
              if (state ) {
                lcd.setCursor (3, 2);
                lcd.print (show_val);// from the label of piston

                state = 0;
              }
              else {
                // lcd.clear();
                lcd.setCursor (3, 2);
                lcd.print ("   ");// from the label of piston

                state = 1;
              }
            }
            else {
              lcd.setCursor (3, 2);
              lcd.print (show_val);

              if (state ) {
                lcd.setCursor (9, 2);
                if (e <= 1000) {
                  lcd.print (delays[show_val - 1]) + lcd.print ("ms  ");
                }

                else {
                  float l = e / 1000.00;
                  lcd.print (l, 3) + lcd.print ("s  ");
                }
                //lcd.print (delays[show_val - 1]); // from the label of piston

                state = 0;
              }
              else {
                // lcd.clear();
                lcd.setCursor (9, 2);
                lcd.print ("      ");// from the label of piston

                state = 1;
              }
            }
          }
        }
        break;
      //= == == == == == == == == == == == == == == == == == == == == == == == == == == ==

      case 3:
        lcd.clear();
        while (item_no == 3) {
          if ( break_menu) {
            item_no = 6;
            item = item_no;
            break_menu = 0;
            break;
          }
          lcd.setCursor ( 0, 0 );
          lcd.print(" Retract order");
          button();
          button_up();
          button_down();
          next_button();

          unsigned long current_millis = millis();
          if (current_millis - prev_millis >= interval) {
            prev_millis = current_millis;
            lcd.setCursor ( 0, 1 );
            lcd.print (off_sequence[0]);
            lcd.setCursor ( 0, 2 );
            lcd.print (off_sequence[1]);
            lcd.setCursor ( 0, 3 );
            lcd.print (off_sequence[2]);

            if (state ) {
              lcd.setCursor ( 0, sequence_off + 1 );
              lcd.print (off_sequence[sequence_off]);// from the label of piston
              state = 0;
            }
            else {
              // lcd.clear();
              lcd.setCursor ( 0, sequence_off + 1 );
              lcd.print ("                ");// from the label of piston
              state = 1;
            }
          }
        }
        lcd.clear();
        break;

      case 6:
        lcd.clear();
        while (item_no == 6) {
          if ( break_menu) {
            item_no = 7;
            item = item_no;
            break_menu = 0;
            break;
          }
          // button();
          button_up();
          button_down();
          next_button();
          lcd.setCursor ( 0, 0 );
          lcd.print("Final delay:");
          unsigned long current_millis = millis();
          if (current_millis - prev_millis >= interval) {
            prev_millis = current_millis;
            if (state ) {
              lcd.setCursor ( 0, 1 );
              //  lcd.print (final_delay_time) + lcd.print ("ms");
              if (final_delay_time <= 1000) {
                lcd.print (final_delay_time) + lcd.print ("ms");
              }

              else {
                float l = final_delay_time / 1000.00;
                lcd.print (l, 3) + lcd.print ("s");
              }
              //lcd.setCursor ( 3, 1 );
              //lcd.print ("  ms");// from the label of piston
              state = 0;
            }
            else {
              // lcd.clear();
              lcd.setCursor ( 0, 1 );
              lcd.print ("                ");// from the label of piston
              state = 1;
            }
          }
        }
        break;
      case 7:
        lcd.clear();
        //        eeprom_update();
        EEPROM.update(27, pistons);
        while (item_no == 7) {
          if ( break_menu) {
            if (final_ == 0) {
              on_menu = 1;
            }
            if (final_ == 1) {
              item_no = 8;
              item = item_no;
            }

            break_menu = 0;
            break;
          }
          lcd.home ();
          lcd.print("Settings saved!");
          button();
          button_up();
          button_down();
          next_button();

          unsigned long current_millis = millis();
          if (current_millis - prev_millis >= interval) {
            prev_millis = current_millis;
            lcd.setCursor ( 0, 1 );
            lcd.print (finals[0]);
            lcd.setCursor ( 0, 2 );
            lcd.print (finals[1]);
            lcd.setCursor ( 0, 3 );
            lcd.print (finals[2]);

            if (state ) {
              lcd.setCursor ( 0, final_ + 1 );
              lcd.print (finals[final_]);// from the label of piston
              state = 0;
            }
            else {
              // lcd.clear();
              lcd.setCursor ( 0, final_ + 1 );
              lcd.print ("                ");// from the label of piston
              state = 1;
            }
          }

        }
        break;
      case 8:// == == == == == == == == == == == == == == == == == == == == = first menu
        lcd.clear();
        while (item_no == 8) {
          item = 8;
          if ( break_menu) {
            if (first_ == 0) {
              item_no = 1;
              item = item_no;
              lcd.clear();
              break_menu = 0;
              break;
            }
            if (first_ == 1) {
              item_no = 10;
              item = item_no;
              lcd.clear();
              break_menu = 0;
            }
            if (first_ == 2) {
              item_no = 11;
              item = item_no;
              lcd.clear();
              break_menu = 0;
            }
            /*  if (first_ == 3) {
                item_no = 11;
                item = item_no;
                lcd.clear();
                break_menu = 0;
              }*/
          }
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
            /* lcd.setCursor ( 0, 3 );
              lcd.print (first[3]);*/

            if (state ) {
              lcd.setCursor ( 0, first_  );
              lcd.print (first[first_]);// from the label of piston
              state = 0;
            }
            else {
              // lcd.clear();
              lcd.setCursor ( 0, first_  );
              lcd.print ("                  ");// from the label of piston
              state = 1;
            }
          }


        }
        break;
      /*case 9: //== == == == == == == == == == == == == == == == == = running last pattern


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

        while (item_no == 9) {
          item = 9;
          if ( break_menu) {
            if (selection == 1) {
              item_no = 8;
              item = item_no;
              break_menu = 0;
              lcd.clear();
              break;
            }
            else {

              on_menu = 1;
              break_menu = 0;
              break;
            }
          }

          //  while (1) {
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
        g = 0;

        break; */

      case 10:// == == == == == == == == == == =select from saved patterns= == == == == == == == == == == =
        lcd.clear();
        while (item_no == 10) {
          item = 10;
          button();
          button_up();
          button_down();
          next_button();
          button_left();
          button_right();
          if ( break_menu) {

            if (selection == 0) {

              item_no = 8;
              item = item_no;
              break_menu = 0;
              lcd.clear();
              break;
            }
            else {
              on_menu = 1;
              lcd.clear();
              break;
            }
          }
          lcd.home ();
          lcd.print("Select pattern");

          unsigned long current_millis = millis();
          if (!selection) {

            lcd.setCursor ( 0, 1 );
            lcd.print (saving_options[1]);
            lcd.setCursor ( 12, 1 );
            lcd.print("<");
            lcd.setCursor ( 13, 1 );
            lcd.print(pattern_no);
            lcd.setCursor ( 15, 1 );
            lcd.print(">");
          }
          else {
            lcd.setCursor ( 0, 2 );
            lcd.print (saving_options[0]);

          }
          if (current_millis - prev_millis >= interval) {
            prev_millis = current_millis;
            if (state ) {
              if (!selection) {
                lcd.setCursor ( 0, 2 );
                lcd.print (saving_options[0]);
              }
              else {
                lcd.setCursor ( 0, 1 );
                lcd.print (saving_options[1]);
                lcd.setCursor ( 12, 1 );
                lcd.print("<");
                lcd.setCursor ( 13, 1 );
                lcd.print(pattern_no);
                lcd.setCursor ( 15, 1 );
                lcd.print(">");
              }

              state = 0;
            }
            else {
              // lcd.clear();
              if (!selection) {
                lcd.setCursor ( 0  , 2 );
                lcd.print ("                ");
              }
              else {
                lcd.setCursor ( 0, 1 );
                lcd.print ("            ");
                lcd.setCursor ( 13, 1 );
                lcd.print ("  ");
              }
              state = 1;
            }
          }

        }
        break;

      case 11:
        while (item_no == 11) {
          item = 11;
          button();
          button_up();
          button_down();
          next_button();
          button_left();
          button_right();
          if ( break_menu) {
            // if (selection == 0) {

            item_no = 8;
            item = item_no;
            break_menu = 0;
            lcd.clear();
            break;
            /*  }
              else {
                // on_menu = 1;
                // lcd.clear();
                break;
              }*/
          }
          lcd.home ();
          lcd.print("Delete pattern");
          // lcd.setCursor ( 5, 1 );
          // lcd.print(show_val_delete);
          unsigned long current_millis = millis();
          if (!selection) {

            lcd.setCursor ( 0, 1 );
            lcd.print (deleting_options[1]);
            lcd.setCursor ( 12, 1 );
            lcd.print("<");
            lcd.setCursor ( 13, 1 );
            lcd.print(show_val_delete);
            lcd.setCursor ( 15, 1 );
            lcd.print(">");
          }
          else {
            lcd.setCursor ( 0, 2 );
            lcd.print (deleting_options[0]);

          }
          if (current_millis - prev_millis >= interval) {
            prev_millis = current_millis;
            if (state ) {
              if (!selection) {
                lcd.setCursor ( 0, 2 );
                lcd.print (deleting_options[0]);
              }
              else {
                lcd.setCursor ( 0, 1 );
                lcd.print (deleting_options[1]);
                lcd.setCursor ( 12, 1 );
                lcd.print("<");
                lcd.setCursor ( 13, 1 );
                lcd.print(show_val_delete);
                lcd.setCursor ( 15, 1 );
                lcd.print(">");
              }

              state = 0;
            }
            else {
              // lcd.clear();
              if (!selection) {
                lcd.setCursor ( 0, 2 );
                lcd.print ("                ");
              }
              else {
                lcd.setCursor ( 0, 1 );
                lcd.print ("            ");
                lcd.setCursor ( 13, 1 );
                lcd.print ("  ");
              }
              state = 1;
            }
          }
        }
        break;
    }
  }
}

