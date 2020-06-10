/*
 Author: Tam Doan
 Description: This code works with the HC-SR501 motion sensor. The code will work with 3 lights, each indicating a state that the code is in.
 There will be a 15 second delay before the sensor starts capturing movement. Note that the PIR pin is on "No Repeat" mode, which means it will only trigger once
 even when sensor is continued to be detected the first time. While waiting, the "waitLight" will be turned on. When it is ready to detect motion, the "readyLight" will be turned on.
 When detecting motion, the "detectLight" will be turned on.
 In the demonstration or in the picture.
 */
int waitLight = 13;
int detectLight = 11;
int readyLight = 12;
int motionCapturePin = 7; /* The pin used to take in the data of PIR motion sensor*/
int motionCapture = 0; /* The variable to take in the data of the PIR motion sensor*/

void setup() {
  Serial.begin(9600);
  pinMode(waitLight,OUTPUT);
  pinMode(detectLight,OUTPUT);
  pinMode(readyLight,OUTPUT);
  pinMode(motionCapturePin,INPUT);

  digitalWrite(waitLight,HIGH);
  digitalWrite(detectLight,LOW);
  digitalWrite(readyLight,LOW); 
  delay(15000); /* There needs to be a 15 second delay for the PIR motion sensor adjust to the surrounding environment*/

}

void loop() {

  
  motionCapture = digitalRead(motionCapturePin);
  if (motionCapture == 1) {
    digitalWrite(waitLight,LOW);
    digitalWrite(detectLight,HIGH);
    digitalWrite(readyLight,LOW);
    delay(1000);
    digitalWrite(waitLight,HIGH);
    digitalWrite(detectLight,LOW);
    digitalWrite(readyLight,LOW);
    delay(6000); /* The delay is right after detecting something, to stabalize the temperature again and make sure the next reading is accurate*/
    digitalWrite(waitLight,LOW);
    digitalWrite(detectLight,LOW);
    digitalWrite(readyLight,HIGH);
  } else {
    digitalWrite(waitLight,LOW);
    digitalWrite(detectLight,LOW);
    digitalWrite(readyLight,HIGH);
  }
  
}
