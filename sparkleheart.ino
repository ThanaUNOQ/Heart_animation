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
  randomSeed(analogRead(A0));
}

// Sparkle effect function
void drawSparkle(uint8_t maxBrightness) {

  for (int i = 0; i < 104; i++) {
    if (shades[i] == 1) {
      frame[i] = random(0, maxBrightness + 1);
    } else {
      frame[i] = 0;
    }
  }

  matrix.draw(frame);
}

void loop() {

  // Sparkle animation
  for (int i = 0; i < 25; i++) {
    drawSparkle(7);
    delay(120);
  }

  // Optional pause
  delay(400);
}
