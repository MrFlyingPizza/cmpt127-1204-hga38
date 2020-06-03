// reverse.c
// reverses arrays
//#include <stdio.h>

void reverse( int arr[], unsigned int len ) {
  int reverse_array[len];
  unsigned int reverse_i;
  for (unsigned int i = 0; i < len; i++) {
    reverse_i = len - i - 1;
    //printf("%d %d\n", i, reverse_i);
    reverse_array[reverse_i] = arr[i];
  }
  for (unsigned int i = 0; i < len; i++) {
    arr[i] = reverse_array[i];
  }
}

/*
int main() {
  int ar1[2] = {1,2};
  int ar2[2] = {2,1};
  reverse(ar1 ,2);
  for (int i = 0; i < 2; i++) {
    if (ar1[i] == ar2[i]) {
      printf("true\n");
    }
  }
}
*/
