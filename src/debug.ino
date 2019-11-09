void debug() {
  lcd.home ();
  lcd.print("Debug:");

  for (int k = 0; k < pistons; k++) {
    Serial.print("piston ") ;
    Serial.print(k + 1) ;
    Serial.print("   >>  ") ;
    Serial.println(selected_pistons[k] );
  }
  for (int k = 0; k < pistons; k++) {
    Serial.print("delays ") ;
    Serial.print(k + 1) ;
    Serial.print("   >>  ") ;
    Serial.println(delays[k] );
  }
  
  Serial.print("retract order ") ;
  Serial.println(off_sequence[sequence_off]);
  Serial.print("run time  ") ;
  Serial.println(run_time);
  Serial.print("delay time  ") ;
  Serial.println(delay_time);
  Serial.print("final delay time  ") ;
  Serial.println(final_delay_time);
    Serial.print("pistons ") ;
  Serial.println(pistons);
  delay(5000);
}

