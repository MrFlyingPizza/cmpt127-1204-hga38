#include <stdio.h>
#include <math.h>

int main(void) {
  // changable scan value per line
  double scan_value = 0;
  int scan_valid = 0;
  // scan loop
  while (scan_valid != EOF) {
    scan_valid = scanf("%lf[^\n]%*c", &scan_value);
    if (scan_valid == 1) {
      int val_ceil = (int) ceil(scan_value);
      int val_floor = (int) floor(scan_value);
      int val_round = (int) round(scan_value);

      printf(
        "%d %d %d\n",
        val_floor,
        val_round,
        val_ceil);
    }
  }
  // print done when EOF reached
  printf("Done.\n");
  return 0;
}
