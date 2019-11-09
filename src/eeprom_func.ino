void eeprom_read() {
  for (byte t = 0; t < 27; t++) {
    value = EEPROM.read(t);
   //123Serial.print(t);
   //123Serial.print("\t");
   //123Serial.print(value);
   //123Serial.println();

  }
}
void eeprom_read_for_saved() {
  for (byte t = 0; t < 10; t++) {
    saved_patterns[t] = EEPROM.read(t); 
   //123Serial.print(t);
   //123Serial.print("   ");
   //123Serial.println( EEPROM.read(t));

  }
}
void eeprom_clear() {
  for (byte t = 0; t < 10; t++) {
    saved_patterns[t] = EEPROM.read(t);
   //123Serial.print("ut");
   //123Serial.println( EEPROM.read(t));

  }
}
/*void eeprom_update() {
  // EEPROM.update(address, val);
  for ( byte r = 0; r < 12; r++) {
    EEPROM.update(r, selected_pistons[r]);
  }
  for ( byte w = 12; w < 24; w++) {
    EEPROM.update(w, delays[w - 12]);
  }

  EEPROM.update(24, sequence_off);
  //EEPROM.update(25, run_time);
  EEPROM.update(26, final_delay_time);
  EEPROM.update(27, pistons);


  }*/
void new_pattern() {
  saved_patterns[p - 1 ] = 1;
  something_in_memory=1;
  EEPROM.update(p - 1, 1 );
  for ( byte r = 30 * p; r < (30 * p) + 12; r++) {
    EEPROM.update(r, selected_pistons[r - (30 * p) ]);
   //123Serial.print(r);
    //123Serial.print( "   " );
   //123Serial.println(r - (30 * p));
  }
  for ( byte w = (30 * p) + 12; w < (30 * p) + 24; w++) {

    EEPROM.update(w, delays[w - ((30 * p) + 12)]);
   //123Serial.print(w - ((30 * p) + 12));
   //123Serial.print( "   " );
   //123Serial.println(w);

  }
  EEPROM.update((30 * p) + 25, sequence_off);
  // EEPROM.update((30 * p) + 26, run_time);
  EEPROM.update((30 * p) + 27, final_delay_time);
  EEPROM.update((30 * p) + 28, pistons);
  EEPROM.update(29, 0);
 //123Serial.println(p);

}
void run_saved_pattern() {

  for ( byte r = 30 * pattern_no; r < (30 * pattern_no) + 12; r++) {
    selected_pistons[r - (30 * pattern_no) ] =  EEPROM.read(r);
  }
  for ( byte w = (30 * pattern_no) + 12; w < (30 * pattern_no) + 24; w++) {
    delays[w - ((30 * pattern_no) + 12)] = EEPROM.read(w);

  }
  sequence_off = EEPROM.read((30 * pattern_no) + 25 );
  // run_time = EEPROM.read((30 * pattern_no) + 26 );
  final_delay_time = EEPROM.read((30 * pattern_no) + 27 );
  pistons = EEPROM.read  ((30 * pattern_no) + 28 );

}



