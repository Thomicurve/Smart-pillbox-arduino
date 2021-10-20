#include <SoftwareSerial.h>
int BUZZER = 6;
int btTX = 2; int btRX = 3;
char deviceResponse = 0;

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
int counter = 0;

SoftwareSerial miBT(btTX, btRX);

int playSound(char isPlay){
  if(isPlay == '1'){
    tone(BUZZER,660,550);
    delay(500);
    tone(BUZZER, 550, 500);
    delay(500);
    tone(BUZZER, 550, 500);
    delay(1000);
  }else {
    noTone(BUZZER);
  }
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Listo");
  pinMode(BUZZER, OUTPUT);
  miBT.begin(9600);

}


void loop() {
  playSound(deviceResponse);
  if(miBT.available()){
    deviceResponse = miBT.read();
  }


}
