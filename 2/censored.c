// censored.c
// censor given argument words from stdin
#include <stdio.h>
#include <string.h>

// this works on my computer but not the grading robot I cant figure out why

int main(int argc, char const *argv[])
{
  // print parameters
  // for (int argarg = 0; argarg < argc; argarg++) {
  //   printf("%s\n", argv[argarg]);
  // }

  // calc argument lengths
  unsigned int argLengths[argc];
  for (unsigned int argLen_i; argLen_i < argc; argLen_i++)
  {
    argLengths[argLen_i] = strlen(argv[argLen_i]);
  }

  // censor substrings
  char ch = ' ';
  char buffer[128] = {0};

  unsigned int arg_i = 0;
  unsigned short found = 0;

  unsigned int argCh_i = 0;
  unsigned short argMatch = 1;

  while ((ch = getchar()) != EOF)
  {
    //printf("Current ch: %c\n", ch);
    arg_i = 0;
    found = 0;
    while (arg_i < argc && found == 0 && ch != EOF)
    { //
      //printf("arg_i: %u\n", arg_i);
      argMatch = 1;
      argCh_i = 0;
      while (argMatch == 1 && argCh_i < argLengths[arg_i] && ch != EOF)
      {

        if (ch == argv[arg_i][argCh_i])
        {
          buffer[argCh_i] = ch;
          ch = getchar();
          argCh_i++;
        }
        else
        {
          argMatch = 0;
          for (unsigned short buffer_i = 0; buffer_i < argCh_i; buffer_i++)
          {
            printf("%c", buffer[buffer_i]);
          }

        }

      }

      if (argMatch == 1)
      {
        found = 1;
      }

      arg_i++;
    }

    if (found == 1)
    {
      printf("CENSORED");
    }
    printf("%c", ch);

  }
  return 0;
}
