// censor.c v2
// censor certain substring from stdin
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	// CONSTANTS
	char const IGNORE_CHAR = 30;
	char const CENSOR_PLACEHOLDER_CHAR = 127;

	// get argument lengths
	unsigned int argLengths[argc];
	for (size_t i = 1; i < argc; i++)
	{
		argLengths[i] = strlen(argv[i]);
	}
	
	// scan stdin
	char readstring [1000] = {0};
	char ch = 0;
	unsigned int ch_i = 0;
	while ((ch = getchar()) != EOF && ch_i < 1000)
	{
		readstring[ch_i] = ch;
		ch_i++;
	}
	
	// remove found substring
	for (size_t arg_i = 1; arg_i < argc; arg_i++)
	{
		char* matchPointer;
		while ((matchPointer = strstr(readstring, argv[arg_i])) != NULL)
		{
			matchPointer[0] = CENSOR_PLACEHOLDER_CHAR;
			for (size_t argCh_i = 1; argCh_i < argLengths[arg_i]; argCh_i++)
			{
				matchPointer[argCh_i] = IGNORE_CHAR;
			}
			
		}

	}
	
	// print edited string
	for (size_t read_i = 0; read_i < 1000; read_i++)
	{
		if (readstring[read_i] != 0 || readstring[read_i] != IGNORE_CHAR)
		{
			if (readstring[read_i] == CENSOR_PLACEHOLDER_CHAR)
			{
				printf("CENSORED");
			}
			else
			{
				printf("%c", readstring[read_i]);
			}
			
		}
		
	}
	
}
