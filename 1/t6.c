#include <stdio.h>
#include <math.h>

int main(void) {
  // changable scan value per line
  double scan_value = 0;
  double scan_value_sum = 0;
  int scan_valid = 0;
  int scan_valid_counter = 0;

  double max_val;
  double min_val;
  double mean_val;
  // scan loop
  while (scan_valid != EOF) {
    scan_valid = scanf("%lf[^\n]%*c", &scan_value);
    if (scan_valid == 1) {

      scan_valid_counter += 1;
      scan_value_sum += scan_value;
      // set first valid float to max and min
      if (scan_valid_counter == 1) {
        max_val = scan_value;
        min_val = scan_value;

      }

      // test max val
      if (scan_value > max_val) {
        max_val = scan_value;
      }

      // test min val
      if (scan_value < min_val) {
        min_val = scan_value;
      }

    }

  }
  // calc mean
  mean_val = scan_value_sum/scan_valid_counter;

  printf("%.2f %.2f %.2f\n", min_val, max_val, mean_val);

  return 0;
}
