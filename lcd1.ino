#include<LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
lcd.begin(16, 2);
lcd.clear();
// Print a message to the LCD
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(13, INPUT); 


Serial.begin(115200);
int z0=digitalRead(2);
Serial.println(z0);
int z1=digitalRead(3);
Serial.println(z1);
int z2=digitalRead(4);
Serial.println(z2);
int z3=digitalRead(5);
Serial.println(z3);
int z4=digitalRead(6);
Serial.println(z4);
int z5=digitalRead(13);
Serial.println(z5);

int no =(z3<<3)+(z2<<2)+(z1<<1)+z0;
int no1=(z4<<4)+(z3<<3)+(z2<<2)+(z1<<1)+z0;

 if (z5==1 && z4==1) {
   Serial.println(-no);
   lcd.print(-no); }
 else {
   Serial.println(no1);
   lcd.print(no1); }

}
void loop(){
}
