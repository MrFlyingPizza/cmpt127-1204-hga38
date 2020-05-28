#include <stdio.h>
#include <math.h>


int main(void) {
  // gather input
  unsigned short dimensions[3];
  short scan_result;
  for (short i = 0; i < 3; i++) {
    scan_result = scanf("%hu%*[ ]%*[\n]", &dimensions[i]);
  }

  // computations and casts
  double width = (double) dimensions[0];
  double length = (double) dimensions[1];
  double height = (double) dimensions[2];

  double base_left = width/2;
  double base_right = width - base_left;

  double side_ratio_left = base_left/height;
  double side_ratio_right = base_right/height;
  short side_pos_left;
  short side_pos_right;

  char building_block;

  // construction
  for (unsigned short height_i = 1; height_i <= height; height_i++) {//top->bottom

    side_pos_left = floor(base_left - height_i*side_ratio_left); //left edge
    side_pos_right = ceil(base_left + height_i*side_ratio_right)-1; // right edge

    for (unsigned short width_i = 0; width_i < width; width_i++) {//triangle construction
      if (width_i < side_pos_left ||
        width_i > side_pos_right) {// set empty

        building_block = ' ';

      } else if (width_i == side_pos_left || width_i == side_pos_right ||
        height_i == 1 || height_i == height) {// set edge block

        building_block = '#';

      } else if (width_i > side_pos_left ||
        width_i < side_pos_right) {// set inner filler

        building_block = '.';

      }
      printf("%c", building_block); // add building_block
    }
    printf("\n"); // add layer end line break
  }
}
