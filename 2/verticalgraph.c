// verticalgraph.c
// graphs stdin values

#include <stdio.h>

int searchHighest(int* values, int len) { // find highest value
  int highest_value = 0;
  for (unsigned int len_i = 0; len_i < len; len_i++) {
    if (values[len_i] > highest_value) {
      highest_value = values[len_i];
    }
  }
  return highest_value;
}


int main(int argc, char const *argv[]) {
  int values[80] = {0};
  for (unsigned short values_i = 0; values_i < 80; values_i++) {
    values[values_i] = 0;
  }
  int scan_value;

  unsigned short scan_amount = 0;
  while (scanf("%d%*[ ]%*[\n]", &scan_value) != EOF && scan_amount < 80) { // scan values
    values[scan_amount] = scan_value;
    scan_amount++;
  }

  int highest_value = searchHighest(values, 80);
  int abs_highest = highest_value;
  //printf("%d", highest_value);
  char point;
  for (int range_i = 0; range_i < abs_highest; range_i++) {

    highest_value = searchHighest(values, 80);
    for (int domain_i = 0; domain_i < scan_amount; domain_i++) {
      if (values[domain_i] == highest_value) {
        point = '#';
        values[domain_i]--;
      } else {
        point = ' ';
      }
      printf("%c", point);
    }
    printf("\n");
  }

  return 0;
}
