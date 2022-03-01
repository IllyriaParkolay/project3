 void GetButton()
 {
 
 // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

   // set the LED:
   digitalWrite(ledPin, ledState);
   Serial.println(ledState);
   if (ledState == LOW)
   {
      for(int i=0; i<NUMPIXELS; i++) 
        { // For each pixel...
    
        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using purple color:
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    
        pixels.show();   // Send the updated pixel colors to the hardware.
        }
   }
   if (ledState == HIGH)
   {
      // The first NeoPixel in a strand is #0, second is 1, all the way up
      // to the count of pixels minus one.
      for(int i=0; i<NUMPIXELS; i++) 
        { // For each pixel...
    
        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using purple color:
        pixels.setPixelColor(i, pixels.Color(Purple_Monkey, 0, Purple_Monkey));
    
        pixels.show();   // Send the updated pixel colors to the hardware.
        }
    }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
  }
