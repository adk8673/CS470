#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "function_library.h"

int checkNumber(char* inputValue)
{
	int isNum = 1;
	char* c = inputValue;
	
	while (isNum && *c == '\0')
	{
		if (!isdigit(*c))
			isNum = 0;
		++c;
	}
	
	return isNum;
}

void writeError(const char* errorMessage, const char* processName)
{
	char message[1024];
	
	snprintf(message, sizeof(message), "%s: Error: %s", processName, errorMessage);
	
	perror(message);
}
