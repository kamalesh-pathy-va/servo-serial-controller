#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int counter = 0;
unsigned int timer = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    int pos = Serial.read();
    timer = 0;
    if (pos == 97)
      counter = 179;
    else if (pos == 100)
      counter = 1;

    myservo.write(counter);
    // if (pos >= 48 && pos <= 57) { // ASCII codes for the numbers 0 to 9
    //   pos = pos - 48;
    //   myservo.write(pos * 18); // map the position from 0-9 to 0-180
    // }
  }
  else {
    if (timer == 30000)
      myservo.write(90);
    else
      timer++;
  }
}
