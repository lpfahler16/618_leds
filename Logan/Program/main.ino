
ButtonLamp *lamp = new ButtonLamp();
ProgramController *controller = new ProgramController(lamp);


void setup() {
  Serial.begin(9600);
  StartProgram *start = new StartProgram(lamp);
  TestProgram *p = new TestProgram(lamp, CRGB(255, 0, 0));
  TestProgram *p2 = new TestProgram(lamp, CRGB(0, 255, 0));
  TestProgram *p3 = new TestProgram(lamp, CRGB(0, 0, 255));
  RainbowProgram *p4 = new RainbowProgram(lamp);
  BouncingProgram *p5 = new BouncingProgram(lamp);
  controller->AddProgram(start);
  controller->AddProgram(p);
  controller->AddProgram(p2);
  controller->AddProgram(p3);
  controller->AddProgram(p4);
  controller->AddProgram(p5);
  controller->AddProgram(p2);
  controller->AddProgram(p3);
  controller->AddProgram(p4);
  controller->AddProgram(p5);
  controller->AddProgram(p2);
  controller->AddProgram(p3);
  controller->AddProgram(p4);
  controller->AddProgram(p5);
  controller->AddProgram(p2);
  controller->AddProgram(p3);
  controller->AddProgram(p4);
  controller->AddProgram(p5);
}

void loop() {
  controller->Run();
}
