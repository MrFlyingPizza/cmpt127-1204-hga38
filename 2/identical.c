// identical.c

int identical( int arr1[], int arr2[], unsigned int len ) {
  short same = 1;
  for (unsigned int i = 0; i < len; i++) {
    if (arr1[i] != arr2[i]) {
      same = 0;
    }
  }
  return same;
}
