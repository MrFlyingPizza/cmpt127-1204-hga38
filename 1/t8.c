#include <stdio.h>



int main(void) {
  // init values
  short scan_result = 1;
  unsigned short scan_value;
  unsigned short dimensions[3];
  // loop 3 times to get 3 positive values
  for (unsigned short i = 0; i < 3; i++) {
    if (scan_result == 1) {
      scan_result = scanf("%hu%*[ ]%*[\n]", &scan_value);
      dimensions[i] = scan_value;
    } else {
      printf("Failed");
      return 1;
    }
  }




  // 2D array construction
  unsigned short length = dimensions[1];
  unsigned short width = dimensions[0];
  // unsigned short height = dimensions[2];
  unsigned short length_i_final = length - 1;
  unsigned short width_i_final = width - 1;
  char building_block;

  // construction loops
  for (unsigned short length_i = 0; length_i < length; length_i++) { // length construction

    for (unsigned short width_i = 0; width_i < width; width_i++) { // width construction
      // if statement to check for first width and last width
      if (length_i == 0 ||
        length_i == length_i_final ||
         width_i == 0 ||
         width_i == width_i_final
       ) {
        building_block = '#';
      } else {
        building_block = '.';
      }
      // print each char
      printf("%c", building_block);
    }
    printf("\n");
  }
}
