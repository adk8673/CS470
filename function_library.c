#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
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

void createChildProcess(const char* targetProgram, const char* processName)
{
	pid_t forkedPid = fork();

	if (forkedPid == 0)
	{
		// If we get here, we are inside of child process, begin parsing and our target program
		// and args into a command line
		char** args;
		int numItems  = makeargv(targetProgram, " ", &args);
		execvp(args[0], args);
	}
	else if (forkedPid < 0)
	{
		writeError("Failed to fork process", processName);
	}
}

// Function taken from Robbins textbook
int makeargv(const char *s, const char *delimiters, char ***argvp)
{
	int error;
	int i;
	int numtokens;
	const char *snew;
	char* t;

	if ((s == NULL) || (delimiters == NULL) || (argvp == NULL))
	{
		errno = EINVAL;
		return -1;
	}
	
	*argvp = NULL;
	snew = s + strspn(s, delimiters);
	if ((t = malloc(strlen(snew) + 1 )) == NULL)
		return -1;
	strcpy(t, snew);
	numtokens = 0;
	if (strtok(t, delimiters) != NULL)
		for (numtokens = 1; strtok(NULL, delimiters) != NULL; numtokens++) ;

	if ((*argvp = malloc((numtokens + 1) * sizeof(char *))) == NULL)
	{
		error = errno;
		free(t);
		errno = error;
		return -1;
	}
	
	if (numtokens == 0)
		free(t);
	else 
	{
		strcpy(t, snew);
		**argvp = strtok(t, delimiters);
		for (i = 1; i < numtokens; i++)
			*((*argvp) + i) = strtok(NULL, delimiters);
	}

	*((*argvp) +  numtokens) = NULL;
	return numtokens;
}
