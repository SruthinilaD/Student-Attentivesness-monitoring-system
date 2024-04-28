#include <LiquidCrystal.h>



LiquidCrystal lcd(2, 3, 4, 5, 6,7);
const int buzzer_Pin = 8;
const int led_Pin = 9;
const int motor_pin=13;
char sleep_status = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(motor_pin, OUTPUT);
  pinMode(led_Pin, OUTPUT);
 pinMode(buzzer_Pin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Student Attentiveness");
  lcd.setCursor(0,2);
  lcd.print("Detection SYSTEM");
  digitalWrite(buzzer_Pin, LOW); 
  digitalWrite(led_Pin, LOW);
  digitalWrite(motor_pin, HIGH);

}
void loop() 
 
{
    while (Serial.available() > 0) 
  {
    sleep_status = Serial.read();
    if(sleep_status == 'a')
    { 
        lcd.clear();
        lcd.print("Student Distracted");
        digitalWrite(buzzer_Pin, HIGH); 
        digitalWrite(led_Pin, HIGH);
        digitalWrite(motor_pin, LOW);
        delay(2000);
        digitalWrite(buzzer_Pin, LOW); 
        digitalWrite(led_Pin, LOW);
        digitalWrite(motor_pin, HIGH);
        
        delay(100);
    }
    else if(sleep_status == 'b')
    {
        lcd.clear();
        lcd.print("All Ok");
        lcd.setCursor(0,2);
        lcd.print("Student Attentive");
        digitalWrite(buzzer_Pin, LOW); 
        digitalWrite(led_Pin, LOW);
        digitalWrite(motor_pin, HIGH);
        delay(2000);
    }
    else
    {
    /* Do Nothing */
    }
  }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
