#include <Arduino_LED_Matrix.h>

Arduino_LED_Matrix matrix;

uint8_t shades[104] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,1,1,0,1,1,0,0,0,0,
  0,0,0,1,1,1,1,1,1,1,0,0,0,
  0,0,0,1,1,1,1,1,1,1,0,0,0,
  0,0,0,1,1,1,1,1,1,1,0,0,0,
  0,0,0,0,1,1,1,1,1,0,0,0,0,
  0,0,0,0,0,1,1,1,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0
};

uint8_t frame[104];


void setup() {
  matrix.begin();
  matrix.setGrayscaleBits(3);
  
}

void drawUP(uint8_t brighness){

  for (int i = 0; i < 104; i++){
    if (shades[i] == 1){
      frame[i] = brighness;
    }
    else {
      frame[i] = 0;
    }
  }
  matrix.draw(frame);
}

void loop() {
  // fade in (สว่างขึ้น)
  for (int b = 0; b <= 7; b++){
    drawUP(b);
    delay(75);
  }

  // fade out (ค่อย ๆ ดับ)
  for (int b = 7; b >= 0; b--){
    drawUP(b);
    delay(75);
  }
}