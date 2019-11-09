/*void pre_setings() {
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
