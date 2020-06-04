// count.c
// counts lines, chars, words

#include <stdio.h>

int main() {
  unsigned int len = 10090;
  char read_string[len];
  char ch;
  unsigned short new_word = 0;
  unsigned long int charcount = 0, wordcount = 0, linecount = 0;
  while (charcount < len && (ch = getchar()) != EOF) {
    if (ch == '\n') {
      linecount++;
    }

    if ((ch == 39) || (ch >= 65 && ch <= 90) || (ch >= 61 && ch <= 122)) {
      if (new_word == 0) {
        wordcount++;
        new_word = 1;
      }
    } else {
      new_word = 0;
    }

    read_string[charcount] = ch;
    charcount++;
  }
  //printf("%s\n", read_string);
  printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
  return 0;
}
