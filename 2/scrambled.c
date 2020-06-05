// scrambled.c
// check if two arrays have the same values
// #include <assert.h>
// #include <stdio.h>

int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ) {
  unsigned short same = 1;
  unsigned short exists = 0;
  unsigned int outter_i = 0;
  unsigned int inner_i = 0;
  unsigned int* ar1;
  unsigned int* ar2;
  for (unsigned short direction = 0; direction < 2; direction++) {

    if (direction) {
      ar1 = &arr2[0];
      ar2 = &arr1[0];
    } else {
      ar1 = &arr1[0];
      ar2 = &arr2[0];
    }

    while (outter_i < len && same == 1) {

      exists = 0;
      inner_i = 0;
      while (inner_i < len && exists == 0) {

        if (ar1[outter_i] == ar2[inner_i]) {
          exists = 1;
        }
        inner_i++;
      }
      if (exists == 0) {
        same = 0;
      }
      //printf("%hu", exists);
      //printf("%hu\n", same);
      outter_i++;
    }
  }
  return same;
}


// int main(void) {
//   unsigned int ar1[3] = {1,3,2};
//   unsigned int ar2[3] = {3,2,1};
//   int result1 = scrambled(ar1, ar2, 3);
//   assert(result1 == 1);
//
//   unsigned int ar3[3] = {1,3,0};
//   unsigned int ar4[3] = {3,2,1};
//   int result2 = scrambled(ar3, ar4, 3);
//   assert(result2 == 0);
//   return 0;
// }
