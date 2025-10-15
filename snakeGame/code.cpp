#include <Adafruit_ST7789.h>
#include <Adafruit_GFX.h>

#define TFT_CS 10
#define TFT_DC 8
#define TFT_RST 9
#define buttonPin 2

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TFT_RST, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  tft.init(240, 280);

  int snakeLenght[200];
  int snakeX[200];
  int snakeY[200];
    // ok now i need to hardcode startpos and lenght
  //a segment is going to be a 6x6 rect
  snakeX[0] = 100;
  snakeY[0] = 100;
  snakeX[1] = 107;
  snakeY[1] = 107;
  snakeX[2] = 113;
  snakeY[2] = 113;
  
}


int direction = 1;
int headX = 28;
int headY= 28;
void loop() {

  int state = digitalRead(buttonPin);
  if (state == LOW) {
    if (direction <= 3) {
      direction = direction + 1;
    }
    else {
      direction = 1;
    }
  }

  delay(200);
  if (direction == 1) {
    headY = headY + 6;
  }
  else if (direction == 2){
    headX = headX - 6;
  }
  else if (direction == 3){
    headY = headY - 6;
  }
  else {
    headX = headX + 6;
  }

  Serial.println(headX);
  Serial.println(headY);

  //DIE
  if (headX <= 10 || headX >= 229) {
    
  }
  else if(headY <= 10 || headY >= 269) {

  }

  


}


