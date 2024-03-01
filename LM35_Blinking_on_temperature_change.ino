#include <TimerOne.h>

const int lm35_pin = A0; // LM35 analog pin
int sensorAnalogValue=0; // variable to store the analog value

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Timer1.initialize(250000); // setting the default blinking period to be 250ms
  Timer1.attachInterrupt(blinkLED); // function to be called when the timer hits the set period
}

void loop() {
  sensorAnalogValue = analogRead(lm35_pin); // getting sensor raw analog value
  float milliVolt = sensorAnalogValue*(5000/1024.0); // mapping the analog value to its respective millivolt value
  float celsius = milliVolt/10; // getting the final celcius value, for every 10mv there is a change of 1 *C
  
  if(celsius < 30){
    Timer1.setPeriod(250000); // if temeperature is less than 30 *C then it will set the blinking period to be 250ms
  }else{
    Timer1.setPeriod(500000); // if temeperature is greater than 30 *C then it will set the blinking period to be 500ms
  }
}

void blinkLED(){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // here we are reading the state of the led pin first and then we alter the value we have read
                                                        // like if the read value is HIGH then toggel it to LOW and set led OFF,
                                                        //if it reads LOW then toggel it to HIGH and that sets the LED to ON.
}