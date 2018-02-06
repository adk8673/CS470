#include <ctype.h>
#include "function_library.h"

int checkNumber(char* inputValue)
{
	int isNum = 1;
	char* c = inputValue;

	if (!isdigit(*c))
		isNum = 0;

	while (isNum && *(++c) == '\0')
	{
		if (!isdigit(*c))
			isNum = 0;
	}

	return isNum;
}

void writeError(const char* errorMessage, const char* processName)
{
	perror(processName);
	perror(": Error: ");
	perror(errorMessage);
}
