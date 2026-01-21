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
uint8_t broken[104];   // 0 = intact, 1 = cracked

void setup() {
  matrix.begin();
  matrix.setGrayscaleBits(3);

  for (int i = 0; i < 104; i++) {
    broken[i] = 0;
  }
}

// Draw with cracked pixels held off
void drawCrack(uint8_t brightness) {

  for (int i = 0; i < 104; i++) {
    if (shades[i] == 1 && broken[i] == 0) {
      frame[i] = brightness;
    } else {
      frame[i] = 0;
    }
  }

  matrix.draw(frame);
}

void loop() {

  // Step 1: show full heart
  drawCrack(7);
  delay(600);

  // Step 2: crack gradually
  for (int step = 0; step < 20; step++) {

    // randomly crack some pixels
    for (int i = 0; i < 104; i++) {
      if (shades[i] == 1 && broken[i] == 0) {
        if (random(100) < 8) {
          broken[i] = 1;
        }
      }
    }

    drawCrack(7);
    delay(150);
  }

  // Step 3: hold the broken state
  delay(1200);

  // Reset for next loop
  for (int i = 0; i < 104; i++) {
    broken[i] = 0;
  }

  delay(500);
}
