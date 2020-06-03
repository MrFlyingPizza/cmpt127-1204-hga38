// test driver
#include "funcs.h"
#include <stdio.h>

void test_identical() {
  int ar1[2] = {1,2};
  int ar2[2] = {1,2};
  short test1 = identical(ar1, ar2, 2);
  printf("%d\n", test1);
  if (test1 == 1) {
    printf("test 1 success\n");
  }

  int ar3[2] = {1,2};
  int ar4[2] = {0,1};
  short test2 = identical(ar3, ar4, 2);
  printf("%d\n", test2);
  if (test2 == 0) {
    printf("test 2 success\n");
  }
}

int main(void) {
  test_identical();
}
