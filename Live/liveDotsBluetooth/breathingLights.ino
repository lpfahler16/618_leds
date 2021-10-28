void breathingLeds() {
  CRGB ledColor = CHSV (CRGB (113, 0, 188), 0, brightness);
  setLeds(0, 300, ledColor);
  
  if (!goTime(100)) {
    return;
  }
  
  if (brightness <= 25 && !isGoingDown) {
    setLeds(0, 300, CHSV (CRGB (113, 0, 188), 0, brightness));
    brightness += 1;
    isGoingDown = false;
  }
  else {
    setLeds(0, 300, CHSV (CRGB (113, 0, 188), 0, brightness));
    brightness -= 1;
    isGoingDown = true;
  }
  
}
