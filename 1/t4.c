#include <stdio.h>
#include <math.h>

void computeFloat(float value)
{
  // print the floor ceiling and rounding for the input val
  int val_ceil = (int) ceil(value);
  int val_floor = (int) floor(value);
  int val_round = (int) round(value);
  printf("%d %d %d\n", val_floor, val_round, val_ceil);
}

int main(void)
{
  double input_value = 0;
  int input_valid = scanf("%lf", &input_value);
  // input validation
  if (input_value == 0)
  {
    printf("scanf error: (%d)\n", input_valid);
  }
  else
  {
    computeFloat(input_value);
  }

  return 0;
}
