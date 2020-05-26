#include <stdio.h>
#include <math.h>

void computeFloat(float val) {
  // print the floor ceiling and rounding for the input val
  int val_ceil = (int) ceil(val);
  int val_floor = (int) floor(val);
  int val_round = (int) round(val);
  printf("%d %d %d\n", val_floor, val_round, val_ceil);
}

int main(void) {
  double input_val = 0;
  int input_valid = scanf("%lf", &input_val);
  // input validation
  if (input_val == 0) {
    printf("scanf error: (%d)\n", input_valid);
  } else {
    computeFloat(input_val);
  }

  return 0;
}
