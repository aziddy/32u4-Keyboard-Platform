#include <Arduino.h>
#include <EEPROM.h>
#include <Keyboard.h>

/* Related Code Documents:
 * https://www.arduino.cc/en/Reference/EEPROMObject
  */

#define number_of_keys 2

int key[127][4];

void setup() {

  initialize_serial();

  /* special key definitions can be founder here
   * https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h
   * (MAC) command ⌘ == KEY_LEFT_GUI
   */

   /*
    * Four, 8bit EEPROM spaces are allocated to each key to allow for shortcut combinations up to 4 keys
    */
 
  // 2 key layout
  key[0][0] = KEY_LEFT_CTRL;
    key[0][1] = KEY_LEFT_SHIFT;
    key[0][2] = 'M';
    key[0][3] = 0;
  key[1][0] = KEY_LEFT_CTRL;
    key[1][1] = KEY_LEFT_SHIFT;
    key[1][2] = 'D';
    key[1][3] = 0;
    
  // 4 key layout
  key[0][0] = 0xB0;
    key[0][1] = 0;
    key[0][2] = 0;
    key[0][3] = 0;
  key[1][0] = 0xEA;
    key[1][1] = 0;
    key[1][2] = 0;
    key[1][3] = 0;
  

  delay(10000);

  write_eeprom();
  serial_report_eeprom();
  
}





///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////





// DONT NEED TO EDIT CODE BELOW

void write_eeprom(){
  // First EEPROM index specifies how many keys the layout has
  EEPROM[0] = number_of_keys;

  for(int i = 0; i < number_of_keys; i++ ){
    EEPROM[1+(i*4)] = key[i][0];
    EEPROM[2+(i*4)] = key[i][1];
    EEPROM[3+(i*4)] = key[i][2];
    EEPROM[4+(i*4)] = key[i][3];
  }
}


void serial_report_eeprom(){
  Serial.print("Number of Keys");
  int numberOfKeys = EEPROM[0];
  Serial.println(numberOfKeys);
  
  Serial.println("");
  Serial.println("/////////////////");
  Serial.println("");

  for(int i = 0; i < numberOfKeys; i++ ){
    Serial.print("Key ");
    Serial.print(i);
    Serial.print(": ");
    
    Serial.print(EEPROM[1+(i*4)]);
    Serial.print(EEPROM[2+(i*4)]);
    Serial.print(EEPROM[3+(i*4)]);
    Serial.println(EEPROM[4+(i*4)]);
    
  }
}


void initialize_serial(){
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for Native USB only
  }
  Serial.println("Serial Initialized");
}

void loop(){
}
