// censored.c
// censor given argument words from stdin
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  unsigned int len = 10090;
  char read_string[len];
  char ch;
  unsigned long int ch_i = 0;
  unsigned int argstrlens[argc];

  // compute string lengths of each censor substring argument
  for (unsigned int lencalc_i = 1; lencalc_i < argc; lencalc_i++) {
    argstrlens[lencalc_i] = strlen(argv[lencalc_i]);
  }

  // construct censored string
  while (ch_i < len && (ch = getchar()) != EOF) {

    do { // repeat until at either none or least one matching word is found
      unsigned int arg_i = 0;
      unsigned short ch_matching = 0;

      do {  //repeat until all matching characters are searched
        arg_i++;

      } while(ch_matching && arg_i < argstrlens[argv_i]);

    } while();

    read_string[ch_i] = ch;

  }
  return 0;
}
