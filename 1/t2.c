#include <stdio.h>
#include <limits.h>

/*
Type specifier 	Minimum width (bits) 	Minimum value 	Maximum value
char 	8 	-127 	127
unsigned char 	8 	0 	255
int 	16 	-32,767 	32,767
unsigned int 	16 	0 	65,535
long 	32 	-2,147,483,647 	2,147,483,647
unsigned long 	32 	0 	4,294,967,295

Floating-point types Type specifiers 	Precision (decimal digits) 	Exponent range
Minimum 	IEEE 754 	Minimum 	IEEE 754
float 	6 	7.2 (24 bits) 	±37 	±38 (8 bits)
double 	10 	15.9 (53 bits) 	±37 	±307 (11 bits)
long double 	10 	34.0 (113 bits) 	±37 	±4931 (15 bits)
*/

int main(void) {
  // declare different type variables
  char char_byte;
  unsigned char uchar_byte;
  int int_byte;
  unsigned int uint_byte;
  long long_byte;
  unsigned long ulong_byte;
  float float_byte;
  double double_byte;
  long double ldouble_byte;

  // create array containing byte sizes
  long unsigned int sizes[] = {
    sizeof(char_byte),
    sizeof(uchar_byte),
    sizeof(int_byte),
    sizeof(uint_byte),
    sizeof(long_byte),
    sizeof(ulong_byte),
    sizeof(float_byte),
    sizeof(double_byte),
    sizeof(ldouble_byte)};

    // convert all bytes in array to bits sizes
    for (int i; i < sizeof(sizes)/sizeof(sizes[0]); i++) {
      sizes[i] *= 8;
      printf("%lu ", sizes[i]);
    }
  return 0;
}
