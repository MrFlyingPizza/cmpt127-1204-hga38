// contains.c
// check for substring in string
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char* true_str = "true";
  char* false_str = "false";
  if (strstr(argv[1], argv[2]) != NULL) {
    printf("%s\n", true_str);
  } else {
    printf("%s\n", false_str);
  }
  return 0;
}
