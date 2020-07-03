// reverse.c
// reverses arrays
//#include <stdio.h>

void reverse( int arr[], unsigned int len ) {
  int temp = 0;
  int middle = len/2;
  for (unsigned int i = 0; i < middle; i++)
  {
    temp = arr[i];
    arr[i] = arr[len-1-i];
    arr[len-1-i] = temp;
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
