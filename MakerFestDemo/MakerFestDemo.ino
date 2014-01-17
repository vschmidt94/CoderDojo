/* Blink without Delay
 
 Turns on and off a light emitting diode(LED) connected to a digital  
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.
 
 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 
 This example code is in the public domain.

 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int ledSlowBlinkPin =  13;      // the number of the LED pin for slow blink
const int ledFastBlinkPin = 12;      // Fast Blink LED
const int ledONPin = 11;  // Always ON LED
const int ledSFPin = 10;  // super fast blink
const int ledFadePin = 9;  // Fading LED

// Variables will change:
int ledStateSlowBlink = LOW;   // ledState used to set the LED
int ledStateFastBlink = LOW;   // ledState used to set the fast blink LED
int ledStateSFBlink = LOW;     // ledState for super fast blink
long previousMillis = 0;        // will store last time LED was updated
long previousFBMillis = 0;      // fast blink timer last update time
long previousSFMillis = 0;      // superfast blink timer
int brightness = 0;          // Brightness for fading LED pin
int fadeAmount = 1;   // how much fade on led per step

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledSlowBlinkPin, OUTPUT);   
  pinMode(ledFastBlinkPin, OUTPUT);
  pinMode(ledSFPin, OUTPUT);
  pinMode(ledONPin, OUTPUT);  
  pinMode(ledFadePin, OUTPUT);
  digitalWrite(ledONPin, HIGH);   // turn on constant LED pin
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  analogWrite(ledFadePin, brightness);
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount;
  }

  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledStateSlowBlink == LOW)
      ledStateSlowBlink = HIGH;
    else
      ledStateSlowBlink = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledSlowBlinkPin, ledStateSlowBlink);
  }
  
  if(currentMillis - previousFBMillis > interval/3) {
    // save the last time you blinked the LED 
    previousFBMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledStateFastBlink == LOW)
      ledStateFastBlink = HIGH;
    else
      ledStateFastBlink = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledFastBlinkPin, ledStateFastBlink);
  }
  
   if(currentMillis - previousSFMillis > interval / 12) {
    // save the last time you blinked the LED 
    previousSFMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledStateSFBlink == LOW)
      ledStateSFBlink = HIGH;
    else
      ledStateSFBlink = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledSFPin, ledStateSFBlink);
  }
  delay(10);
}

