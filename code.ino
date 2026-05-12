#include <Servo.h>

Servo escFB1;
Servo escFB2;
Servo escUD1;
Servo escUD2;
Servo escUD3;
Servo escUD4; 

const int ESC_STOP = 1000;
const int ESC_MAX  = 2000;

int spd_FB1 = 2000;
int spd_FB2 = 2000;
int spd_UD1 = 2000;
int spd_UD2 = 2000;
int spd_UD3 = 2000;
int spd_UD4 = 2000;

void setup() {
  Serial.begin(9600);

  escFB1.attach(6,  1000, 2000);
  escFB2.attach(9,  1000, 2000);
  escUD1.attach(10, 1000, 2000);
  escUD2.attach(11, 1000, 2000);
  escUD3.attach(3,  1000, 2000);
  escUD4.attach(5,  1000, 2000);  // D5 back

  Serial.println("=== Calibrating Motor 6 (D5) individually ===");
  escUD4.writeMicroseconds(ESC_MAX);   // MAX to Motor 6 only
  delay(3000);                          // Wait for ESC beeps
  escUD4.writeMicroseconds(ESC_STOP);  // MIN to Motor 6
  delay(3000);                          // Wait for arm beep
  Serial.println("=== Motor 6 Calibrated! ===");

  Serial.println("=== Arming all ESCs - Sending MAX ===");
  escFB1.writeMicroseconds(ESC_MAX);
  escFB2.writeMicroseconds(ESC_MAX);
  escUD1.writeMicroseconds(ESC_MAX);
  escUD2.writeMicroseconds(ESC_MAX);
  escUD3.writeMicroseconds(ESC_MAX);
  escUD4.writeMicroseconds(ESC_MAX);
  delay(2000);

  Serial.println("=== Sending MIN to arm all ===");
  stopAll();
  delay(3000);

  Serial.println("=== ALL ESCs ARMED AND READY! ===");
  Serial.println("");
  Serial.println("COMMANDS : f=Forward | b=Backward | u=Up | d=Down | s=Stop");
  Serial.println("TEST     : 1=D6 | 2=D9 | 3=D10 | 4=D11 | 5=D3 | 6=D5");
  Serial.println("TUNE M6  : + = increase speed | - = decrease speed");
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == '\n' || cmd == '\r') return;

    switch (cmd) {

      case 'f': case 'F':
        stopAll();
        escFB1.writeMicroseconds(spd_FB1);
        escFB2.writeMicroseconds(spd_FB2);
        Serial.println(">> FORWARD - Motor1(D6) + Motor2(D9)");
        break;

      case 'b': case 'B':
        stopAll();
        escFB1.writeMicroseconds(1450);
        escFB2.writeMicroseconds(1450);
        Serial.println(">> BACKWARD - Motor1(D6) + Motor2(D9)");
        break;

      case 'u': case 'U':
        stopAll();
        escUD1.writeMicroseconds(spd_UD1);
        escUD2.writeMicroseconds(spd_UD2);
        escUD3.writeMicroseconds(spd_UD3);
        escUD4.writeMicroseconds(spd_UD4);
        Serial.print(">> UPWARD - All 4 motors | Motor6 speed: ");
        Serial.println(spd_UD4);
        break;

      case 'd': case 'D':
        stopAll();
        escUD1.writeMicroseconds(1450);
        escUD2.writeMicroseconds(1450);
        escUD3.writeMicroseconds(1450);
        escUD4.writeMicroseconds(spd_UD4);
        Serial.print(">> DOWNWARD - All 4 motors | Motor6 speed: ");
        Serial.println(spd_UD4);
        break;

      case 's': case 'S':
        stopAll();
        Serial.println(">> ALL STOPPED");
        break;

      case '+':
        spd_UD4 += 25;
        if (spd_UD4 > ESC_MAX) spd_UD4 = ESC_MAX;
        escUD4.writeMicroseconds(spd_UD4);
        Serial.print(">> Motor6 speed UP: ");
        Serial.println(spd_UD4);
        break;

      case '-':
        spd_UD4 -= 25;
        if (spd_UD4 < ESC_STOP) spd_UD4 = ESC_STOP;
        escUD4.writeMicroseconds(spd_UD4);
        Serial.print(">> Motor6 speed DOWN: ");
        Serial.println(spd_UD4);
        break;

      case '1':
        stopAll();
        escFB1.writeMicroseconds(spd_FB1);
        Serial.println(">> TEST: Motor1 (D6) - 2 sec...");
        delay(2000); stopAll();
        Serial.println(">> TEST: Motor1 STOPPED");
        break;

      case '2':
        stopAll();
        escFB2.writeMicroseconds(spd_FB2);
        Serial.println(">> TEST: Motor2 (D9) - 2 sec...");
        delay(2000); stopAll();
        Serial.println(">> TEST: Motor2 STOPPED");
        break;

      case '3':
        stopAll();
        escUD1.writeMicroseconds(spd_UD1);
        Serial.println(">> TEST: Motor3 (D10) - 2 sec...");
        delay(2000); stopAll();
        Serial.println(">> TEST: Motor3 STOPPED");
        break;

      case '4':
        stopAll();
        escUD2.writeMicroseconds(spd_UD2);
        Serial.println(">> TEST: Motor4 (D11) - 2 sec...");
        delay(2000); stopAll();
        Serial.println(">> TEST: Motor4 STOPPED");
        break;

      case '5':
        stopAll();
        escUD3.writeMicroseconds(spd_UD3);
        Serial.println(">> TEST: Motor5 (D3) - 2 sec...");
        delay(2000); stopAll();
        Serial.println(">> TEST: Motor5 STOPPED");
        break;

      case '6':
        stopAll();
        escUD4.writeMicroseconds(spd_UD4);
        Serial.print(">> TEST: Motor6 (D5) - 2 sec at speed: ");
        Serial.println(spd_UD4);
        delay(2000); stopAll();
        Serial.println(">> TEST: Motor6 STOPPED");
        break;

      default:
        Serial.print(">> Unknown: ");
        Serial.println(cmd);
        break;
    }
  }
}

void stopAll() {
  escFB1.writeMicroseconds(ESC_STOP);
  escFB2.writeMicroseconds(ESC_STOP);
  escUD1.writeMicroseconds(ESC_STOP);
  escUD2.writeMicroseconds(ESC_STOP);
  escUD3.writeMicroseconds(ESC_STOP);
  escUD4.writeMicroseconds(ESC_STOP);
}
