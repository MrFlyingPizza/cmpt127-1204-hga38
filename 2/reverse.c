// reverse.c
// reverses arrays

void reverse( int arr[], unsigned int len ) {
  int temp = 0;
  int middle = len/2;
  for (unsigned int i = 0; i < middle; i++)
  {
    temp = arr[i]; // swap values
    arr[i] = arr[len-1-i];
    arr[len-1-i] = temp;
  }
  
}

