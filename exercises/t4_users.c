/*
  exercise3.c
  prompts user for floating point input and computes
  the floor, rounded and ceiling of the value.
  By Richard(Han), Gao
  June 09, 2020
*/

#include <stdio.h>
#include <math.h>

void computeFloat(float value)
{
  // print the floor ceiling and rounding for the input val
  int val_ceil = (int) ceil(value);
  int val_floor = (int) floor(value);
  int val_round = (int) round(value);
  printf("Floor of the value: \t%d\nRounded to integer: \t%d\nCeiling of the value: \t%d\n", val_floor, val_round, val_ceil);
}

int main(void)
{
  double input_value = 0;
  printf("Enter a valid float point value. (In range of Double)\n=> "); // prompt for input
  int input_valid = scanf("%lf", &input_value);
  // input validation
  if (input_value == 0)
  {
    printf("Input invalid! Scanf error: (%d)\n", input_valid);
  }
  else
  {
    computeFloat(input_value);
  }

  return 0;
}
