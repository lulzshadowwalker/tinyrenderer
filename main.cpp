#include "tgaimage.h"

// white green red blue yellow
constexpr TGAColor white = {255, 255, 255, 255}; // bgra,
constexpr TGAColor green = {0, 255, 0, 255};
constexpr TGAColor red = {0, 0, 255, 255};
constexpr TGAColor blue = {255, 0, 0, 255};
constexpr TGAColor yellow = {255, 255, 0, 255};

int main() {
  // width and height of canvas
  constexpr int height = 64, width = 64;

  // three points as x, y coords
  constexpr int ax = 10, ay = 10;
  constexpr int bx = 20, by = 20;
  constexpr int cx = 30, cy = 30;

  // add three points to frame buffer
  TGAImage image(width, height, TGAImage::RGB);
  image.set(ax, ay, white);
  image.set(bx, by, blue);
  image.set(cx, cy, green);

  // write frame buffer onto the output file
  image.write_tga_file("framebuffer.tga", false, false);

  return 0;
}
