#include <Keypad.h>


float v1 = 0;
float v2 = 0;
int a, b, c, d;
int bits[4];
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {A5, A4 , A3, A2};
byte colPins[COLS] = { A1, A0 , 2};
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(115200);
}


byte value = 0;
int i=0;
int var[4] = {0};

void loop() {
  char key = kpd.getKey();
  if (key != NO_KEY)
  {
    if ( (key >= '0') && (key <= '9') )
    {
      value = value * 10;
      value = value + key - '0';
      Serial.println(value);
    }
    if ( key == '#' )
    {
      //do stuff with value
      //for demonstration purposes, for now we'll just print it
      delay(1000);
      if (value <= 15) {
        Serial.print("The data is : ");
        Serial.println(value);
        var[i] = value;
        i = i+1;
       
        int data = value;
        for (int c = 3; c >= 0; c--)
        {
          int k = data >> c;

          if (k & 1) {
            bits[c] = 1;
            //Serial.println(bits[c]);
          }
          else {
            bits[c] = 0;
            //Serial.println(bits[c]);
          }
        }
     
         Serial.print("Bits sent to fpga board:");
        Serial.print(bits[3]);
         Serial.print(bits[2]);
          Serial.print(bits[1]);
           Serial.println(bits[0]);
      }
      else {
        Serial.println("Plaese enter a value less than 16!!");

      }

      value = 0; //Now reset ready for next input
    }
  }
  if(key == '*'){
    
  int a = var[0];
  digitalWrite(13, a%2);
  a = a>>1;
  digitalWrite(12, a%2);
  a = a>>1;
  digitalWrite(11, a%2);
  a = a>>1;
  digitalWrite(10, a%2);

  int b = var[1];
  digitalWrite(9, b%2);
  b = b>>1;
  digitalWrite(8, b%2);
  b = b>>1;
  digitalWrite(7, b%2);
  b = b>>1;
  digitalWrite(6, b%2);

  int z = var[2];
  digitalWrite(5, z);
  
  
  var[0] = 0;
  var[1] = 0;
  var[2] = 0;
  }
}
