#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include"function_library.h"

#ifndef MAX_CANON
#define MAX_CANON 8195
#endif

void displayHelp(void);
int executeForks(const char *, const char *);

// Base code for this problem taken from the program 3.2
// on page 68 of Robbins 2003 textbook
int main(int argc, char *argv[]) {
	int returnCode = 0;
	pid_t childpid = 0;

	char* str_prLimit = NULL;

	int c;
	if ((c = getopt(argc, argv, "n:h")) != -1)
	{
		switch(c)
		{
		case 'n':
			str_prLimit = optarg;
			returnCode = executeForks(str_prLimit, argv[0]);
			break;
		case 'h':
			displayHelp();
			break;
		default:
			writeError("Missing or invalid command line arguments", argv[0]);
			break;
		}
	}
	else
	{
		writeError("Missing command line arguments", argv[0]);
	}	
/*	n = atoi(argv[1]);
	int i;
	for (i = 1; i < n; ++i)
		if ((childpid = fork()) <= 0)
			break;
	fprintf(stderr, "i:%d process ID: %ld parent ID: %ld child id:%ld\n",
			i, (long)getpid(), (long)getppid(), (long)childpid);
*/
	return returnCode;
}

void displayHelp()
{
	fprintf(stdout, "proc_fan Options:\n -n numProcesses (numProcess: Number of child processes to produce)\n");
}

int executeForks(const char* str_prLimit, const char* processName)
{
	// pr_Limit: maximum number of executing forks
	// pr_Count: currently execute number of child processes
	int pr_Limit, pr_Count = 0, returnCode = 0;

	if (checkNumber(str_prLimit))
	{
		pr_Limit = atoi(str_prLimit);
		char line[1024];
		pid_t* childProcesses = malloc(sizeof(pid_t) * pr_Limit);
		while (fgets(line, MAX_CANON, stdin) != NULL)
		{
		/*	if (pr_Count == pr_Limit)
			{
				int status;
				wait(&status);
				--pr_Count;
			}
			
			createChildProcess(line, processName);

			++pr_Count;
			
			pid_t childpid;
			int finishedCount = 0;
			while (childpid = waitpid(-1, NULL, WNOHANG))
			{
				if (childpid != -1 && errno != EINTR)
				{
					--pr_Count;
				}
				else
				{
					break;
				}
			}
		*/			
		}

	}
	else
	{
		writeError("Input argument was not a number", processName);
	}

	return returnCode;
}
