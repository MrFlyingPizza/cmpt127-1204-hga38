#include <stdio.h>

int main(void) {
  // init scan results
  unsigned int scan_value;
  short scan_result;
  // scan while loop
  while (scan_result != EOF) {
    scan_result = scanf("%ul%*[ ]%*[\n]", &scan_value);
    if (scan_result == 1) {
      char hash_string[scan_value];
      for (unsigned int i = 0; i < scan_value; i++) {
        hash_string[i] = '#';
      }
      hash_string[scan_value] = '\0';
      printf("%s\n", hash_string);
    }
  }

  return 0;
}
