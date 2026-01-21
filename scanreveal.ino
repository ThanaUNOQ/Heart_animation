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

// Scan reveal function
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

  // Scan from top to bottom
  for (int r = 0; r < 8; r++) {
    drawScan(r, 7);
    delay(120);
  }

  // Hold full heart
  delay(600);

  // Clear screen
  drawScan(-1, 0);
  delay(400);
}
