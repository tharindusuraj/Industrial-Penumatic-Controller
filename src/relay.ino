/*void select_relay_up(int number ) {

  state = 1;
  while (1) {
    unsigned long current_millis = millis();
    if (current_millis - prev_millis >= run_time) {
      prev_millis = current_millis;
      if (state ) {
        digitalWrite(relay_up[number], 1);
        lcd.setCursor ( number, 2 );
        lcd.print("1");
        state = 0;
      }
      else {
        digitalWrite(relay_up[number], 0);
        lcd.setCursor ( number, 2 );
        lcd.print(" ");

        break;
      }
    }

  }
  }

  void select_relay_down(int number ) {
  state = 1;
  while (1) {
    unsigned long current_millis = millis();
    if (current_millis - prev_millis >= run_time) {
      prev_millis = current_millis;
      if (state ) {
        digitalWrite(relay_down[number], 1);
        lcd.setCursor ( number, 2 );
        lcd.print(" ");
        state = 0;
      }
      else {

        break;
      }
    }

  }
  }
*/




void delay_(int z) {
  period = z;
  unsigned long  time_now = millis();
  while (millis() < time_now + period) {
    /* if (millis() >= timer + run_time) {
        digitalWrite(relay_up[selected_pistons[0]], 0);
      }*/
  }

}
void sw_1() {
  s1_pressed = 1;
}
void sw_2() {
  s2_pressed = 1;
}
void reset_() {
  for (byte f = 0; f < 12; f++) {
    selected_pistons[f] = 0;
  }
  for (byte f = 0; f < 12; f++) {
    delays[f] = 0;
  }
  show_val = 1;
  pistons = 0;
  i = 0;
  num_of_pistons = 1;
 // sequence_on = 0;
  sequence_off = 0;
 // run_time = 0;
  delay_time = 0;
  final_delay_time = 0;
  item = 1;
}

