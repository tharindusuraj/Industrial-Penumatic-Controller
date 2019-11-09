/*
  SA2_concepts
  2k19

*/

#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);
//byte address = 0;
int value;

//============================buttons=================
const byte up = 8;
const byte down = 7;
const byte left = 5;
const byte right = 4;
const byte switch_2 = 99;
const byte switch_1 = 99;
const int retract_const_delay = 1000;

const byte next = 9;
const byte enter = 6;
//====================================================
byte p;
//byte pattern_save_flag;
int period ;
unsigned long time_now = 0;
int selected_pistons[12];//selected pistons by user
byte pistons;
//bool sequence_on;// on sequence variable
byte sequence_off;//off sequence variable
byte final_;//final selection
byte show_val_delete = 1;
byte first_;
bool selection ;
byte delete_pattern = 1;
int delays[12];// = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte all_pistons[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
String numbers[12] = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th"};
//String main_menu[8] = {"1.Select pistons", "2", "3", "4", "5.Delay time", "6.Final Delay", "7.Proceed", "8.Reset"};

String off_sequence[3] = {"1.Ascending", "2.Descending", "3.Together"};
String first[3] = {"1.New pattern", "2.Saved patterns", "3.Delete patterns"};
String final_slection[2] = {"Proceed", "Back "};
String saving_options[2] = {"Back", "Pattern No"};
String deleting_options[2] = {"Back ", "Pattern No" };
String finals[3] = {"1.Proceed", "2.Back", "3.Save pattern"};
byte saved_patterns[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte relay_up[12] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44};
byte relay_down[12] = {23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45};
byte num_of_pistons = 1;
//============================================== blinking variables====================
byte current;
byte current_up;
byte current_left;
byte current_right;
byte current_down;
byte current_next;
byte i ;
long millis_held;
long secs_held;
long prev_secs_held;
bool previous = 1;
unsigned long firstTime;
//= == == == == == == == == == =
long millis_held_up;
long secs_held_up;
long prev_secs_held_up;
bool previous_up = 1;
unsigned long firstTime_up;
//= == == == == == == == == == =
long millis_held_left;
long secs_held_left;
long prev_secs_held_left;
bool previous_left = 1;
unsigned long firstTime_left;
//= == == == == == == == == == =
long millis_held_down;
long secs_held_down;
long prev_secs_held_down;
bool previous_down = 1;
unsigned long firstTime_down;
//= == == == == == == == == == =
long millis_held_right;
long secs_held_right;
long prev_secs_held_right;
bool previous_right = 1;
unsigned long firstTime_right;
//= == == == == == == == == == =
long millis_held_next;
long secs_held_next;
long prev_secs_held_next;
bool previous_next = 1;
unsigned long firstTime_next;
//= == == == == == == == == == =
bool state = 1;
unsigned long prev_millis = 0;
int interval = 250;
//=========================================================================
byte q = 0;
int e;
int g = 0;
byte m = 0;
bool break_menu;
bool wrong;
byte item = 1;
int run_time = 10;
int delay_time;
int final_delay_time;
bool on_menu;
//bool run_once = 1;
byte show_val = 1;
bool side;
bool s1_pressed , s2_pressed;
long current_millis1 , prev_millis1;
bool pre_set_val;
bool proceed_;
bool something_in_memory;
//unsigned long timer ;
//unsigned long prev_timer ;

byte pattern_no = 1;
void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.begin(20, 4);              // initialize the lcd
  lcd.backlight();
  for (int pin = 0; pin < 12; pin++) {
    pinMode(relay_up[pin], OUTPUT);
    pinMode(relay_down[pin], OUTPUT);
  }
   pinMode(13, OUTPUT);
  /*  for (int pin = 0; pin < 12; pin++) {
      digitalWrite(relay_up[pin], 1);
      delay(200);
      digitalWrite(relay_up[pin], 0);
      delay(200);
     }
     for (int pin = 0; pin < 12; pin++) {
      digitalWrite(relay_down[pin], 1);
      delay(200);
      digitalWrite(relay_down[pin], 0);
      delay(200);
     }*/

  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(switch_1, INPUT_PULLUP);
  pinMode(switch_2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(switch_1), sw_1, FALLING);
  attachInterrupt(digitalPinToInterrupt(switch_2), sw_2, FALLING);
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);
  pinMode(next, INPUT_PULLUP);
  //starting();//things need to print @ starting
  lcd.clear();
  // p = EEPROM.read(29);
  eeprom_read_for_saved();
  for (byte t = 1  ; t < 10; t++) {
    if ( saved_patterns[t - 1] == 1) {
      p = t;
      //123Serial.print( "p ");
      //123Serial.println( p);

      something_in_memory = 1;
      break;
    }
  }
  digitalWrite(13, 0);
  // p = 0;
  //eeprom_read();
  //  digitalWrite(relay_up[0], 1);
  /* if ( EEPROM.read(27) != 0) {
     // pre_setings();
     first_menu();
    }
    lcd.clear();
    pre_setings();
    lcd.clear();*/
  if (!proceed_) {
    boot_menu(8);
  }
  lcd.clear();
  s1_pressed = 1;
  s2_pressed = 1;


}


