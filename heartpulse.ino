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

// Pulse draw function
void drawPulse(uint8_t brightness) {

  for (int i = 0; i < 104; i++) {
    if (shades[i] == 1) {
      frame[i] = brightness;
    } else {
      frame[i] = 0;
    }
  }

  matrix.draw(frame);
}

void loop() {

  // Heartbeat brightness pattern
  uint8_t pulsePattern[] = {0, 3, 6, 7, 4, 7, 2, 0};
  uint8_t steps = sizeof(pulsePattern);

  for (int i = 0; i < steps; i++) {
    drawPulse(pulsePattern[i]);
    delay(90);
  }

  // Rest between beats
  delay(300);
}
