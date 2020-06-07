// letterfreq.c
// counts the frequency of each letter in input stream
// this works on my computer but not the grading robot and I cant figure out why

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char ch = '';
  float alpha[26] = {0};
  unsigned int total = 0;
  while ((ch = getchar()) != EOF) {
    if (ch >= 97 && ch <= 122) {
      total++;
      alpha[ch-97]++;
    } else if (ch >= 65 && ch <= 90) {
      total++;
      alpha[ch-65]++;
    }
  }

  for (unsigned short alpha_i = 0; alpha_i < 26; alpha_i++) {
    printf("%c %.4f\n", 97 + alpha_i, alpha[alpha_i]/total);
  }
  return 0;
}
