
class RainbowProgram : public ButtonProgram
{
private:
  int i = 0;
  CRGB color;

public:
    RainbowProgram(ButtonLamp *l) : ButtonProgram(l) {
      }

    void setup() {
    }

    void loop() {
      for(int j = 0; j < 255; j++) {
        int pos = 3*(j+i) % (255*3);
        lamp->SetRings(pos, pos + 2, CHSV(j, 255, 255));
      }
      lamp->Show();
      lamp->Delay(100);
      i++;
      i %= 255;
    }
};
