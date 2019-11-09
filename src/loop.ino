void loop() {
  ////123Serial.println(selected_pistons[12]);
  // debug();
  while (s1_pressed && s2_pressed) {//extracting
    for (byte k = 0; k < pistons; k++) {
      digitalWrite(relay_up[selected_pistons[k - 1]], 1);
      //Serial.println(selected_pistons[k-1]);
      lcd.setCursor ( 1, 0 );
      lcd.print(selected_pistons[k - 1]);
      delay_(delays[k]);
      lcd.clear();
    }
    delay_(final_delay_time);//final delay
    for (byte k = 0; k < 12; k++) {//turn off all extracted relays
      digitalWrite(relay_up[k], 0);
    }

    switch (sequence_off + 1) { //retracting
      case 1://ascending
        for (byte k = 0; k < pistons; k++) {
          digitalWrite(relay_down[selected_pistons[k - 1]], 1);
          delay_(retract_const_delay);
        }
        break;
      case 2://descending
        for (byte k = 0; k < pistons; k++) {
          digitalWrite(relay_down[selected_pistons[(pistons - 1) - k - 1]], 1);
          delay_(retract_const_delay);
        }
        break;
      case 3://together
        for (byte k = 0; k < pistons; k++) {
          digitalWrite(relay_down[selected_pistons[k - 1]], 1);
        }
        break;

    }
    delay_(5000);
    for (byte k = 0; k < 12; k++) {
      digitalWrite(relay_down[k], 0);
    }
  //  s1_pressed = 0;  s2_pressed = 0;//release switches
    break;

  }
}

