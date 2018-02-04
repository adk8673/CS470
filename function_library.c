#include <ctype.h>
#include "function_library.c"

bool checkNumber(const char* inputValue)
{
	bool isNum = true;
	char* c = inputValue;

	if (!isdigit(*c))
		isNum = false;

	while (isNum && *(++c) == '\0')
	{
		if (!isDigit(*c))
			isNum = false;
	}

	return isNum;
}
