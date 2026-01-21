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

// Basic draw (used by Pulse and Fade)
void drawFrame(uint8_t brightness) {
  for (int i = 0; i < 104; i++) {
    if (shades[i] == 1) {
      frame[i] = brightness;
    } else {
      frame[i] = 0;
    }
  }
  matrix.draw(frame);
}

// Scan reveal draw
void drawScan(int8_t scanRow, uint8_t brightness) {
  for (int i = 0; i < 104; i++) {
    int row = i / 13;
    if (shades[i] == 1 && row <= scanRow) {
      frame[i] = brightness;
    } else {
      frame[i] = 0;
    }
  }
  matrix.draw(frame);
}

void loop() {

  // --------------------
  // 1) Pulse Effect
  // --------------------
  uint8_t pulsePattern[] = {0, 3, 6, 7, 4, 7, 2, 0};
  uint8_t steps = sizeof(pulsePattern);

  for (int beat = 0; beat < 3; beat++) {
    for (int i = 0; i < steps; i++) {
      drawFrame(pulsePattern[i]);
      delay(90);
    }
    delay(250);
  }

  // --------------------
  // 2) Fade Out
  // --------------------
  for (int b = 7; b >= 0; b--) {
    drawFrame(b);
    delay(80);
  }

  delay(300);

  // --------------------
  // 3) Scan Reveal
  // --------------------
  for (int r = 0; r < 8; r++) {
    drawScan(r, 7);
    delay(120);
  }

  delay(700);

  // Clear before looping again
  drawFrame(0);
  delay(500);
}
