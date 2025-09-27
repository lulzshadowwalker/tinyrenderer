#include "tgaimage.h"
#include <cmath>

// white green red blue yellow
constexpr TGAColor white = {255, 255, 255, 255}; // bgra,
constexpr TGAColor green = {0, 255, 0, 255};
constexpr TGAColor red = {0, 0, 255, 255};
constexpr TGAColor blue = {255, 0, 0, 255};
constexpr TGAColor yellow = {255, 255, 0, 255};

void line(int ax, int ay, int bx, int by, TGAImage &buffer, TGAColor color) {
  bool steep = std::abs(bx - ax) < std::abs(by - ay);
  if (steep) {
    std::swap(ax, ay);
    std::swap(bx, by);
  }

  if (ax > bx) {
    std::swap(ax, bx);
    std::swap(ay, by);
  }

  for (int x = ax; x <= bx; ++x) {
    float t = (x - ax) / static_cast<float>(bx - ax);
    int y = std::round(ay + (by - ay) * t);

    if (steep) {
      buffer.set(y, x, color);
      continue;
    }

    buffer.set(x, y, color);
  }
}

int main() {
  // width and height of canvas
  constexpr int height = 64, width = 64;

  // three points as x, y coords
  constexpr int ax = 7, ay = 3;
  constexpr int bx = 12, by = 37;
  constexpr int cx = 62, cy = 53;

  // add three points to frame buffer
  TGAImage buffer(width, height, TGAImage::RGB);

  line(ax, ay, bx, by, buffer, blue);
  line(cx, cy, bx, by, buffer, green);
  line(cx, cy, ax, ay, buffer, yellow);
  line(ax, ay, cx, cy, buffer, red);

  buffer.set(ax, ay, white);
  buffer.set(bx, by, white);
  buffer.set(cx, cy, white);

  // write frame buffer onto the output file
  buffer.write_tga_file("framebuffer.tga", false, false);

  return 0;
}
