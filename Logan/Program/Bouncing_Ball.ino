
class BouncingProgram : public ButtonProgram
{
public:
    BouncingProgram(ButtonLamp *l) : ButtonProgram(l) {}
    

    float GAP = 0.015;
    float pos = 0;
    
    float velocity;
    float gravity;
    float del;
    float cons_energy;
    float vmin;
    float vmax;
    
    void setup() {
      
      vmin = 2;
      vmax = 7;
      gravity = 9.81;
      del = 10;
      cons_energy = 0.8;
    }
    
    void loop() {
      velocity = randomVelocity();
      bounce();
    }
    
    void bounce() {
      while (!(pos == 0 && abs(velocity) < 0.75)) {
        lamp->SetLamp(CRGB(100, 100, 100));
        draw();
        lamp->Delay(del);
        pos += (velocity*del/1000)/GAP;
        velocity -= gravity*del/1000;
      
        if (pos < 0) {
          velocity = -1*velocity*cons_energy;
          pos = 0;
        }
      }
    }
    
    void draw() {
      float p_d = pos - floor(pos);
      lamp->SetRing(pos - 1, CHSV(255*(1 - p_d),0,0));
      lamp->SetRings(pos, pos + 2, CRGB(255,0,0));
      lamp->SetRing(pos + 2, CRGB(255*(p_d),0,0));
      lamp->Show();
    }
    
    float randomVelocity() {
      float v = (rand() % int((vmax - vmin) * 10) + (vmin * 10)) / 10.0;
      Serial.println(v);
      return v;
    }
};
