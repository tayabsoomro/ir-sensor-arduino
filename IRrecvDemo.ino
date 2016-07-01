#include <IRremote.h>

// led pins
int red = 13;
int green = 12;


// IR sensor
int RECV_PIN = 7;

bool on = false;


IRrecv irrecv(RECV_PIN); // connecting the irrecv to RECV_PIN

decode_results results; // results storage variable

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  digitalWrite(red,HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // print the HEX code value of the button pressed
    if(results.value == 0xE0E040BF && !on){ // if power button is pressed and light is not currently on
      digitalWrite(green,HIGH); 
      digitalWrite(red,LOW);
      on = true;
    }
    else{
      digitalWrite(green,LOW);  
      digitalWrite(red,HIGH);
      on = false;
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
