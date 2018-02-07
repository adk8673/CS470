#include<stdio.h>
#include<stdlib.h>
// Alex Kane
// 2/7/2018
// CS 4760 Project 1
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
	
	return returnCode;
}

// output what program does
void displayHelp()
{
	fprintf(stdout, "proc_fan Options:\n -n numProcesses (numProcess: Number of child processes to produce)\n");
}

// using the limit passed and the name of the progress, execute a forks based on the input from stdin
// which will be tested by 
int executeForks(const char* str_prLimit, const char* processName)
{
	// pr_Limit: maximum number of executing forks
	// pr_Count: currently execute number of child processes
	int pr_Limit, pr_Count = 0, returnCode = 0, status;

	// verify a number was passed as an option, otherwise write error
	if (checkNumber(str_prLimit))
	{
		pr_Limit = atoi(str_prLimit);
		char line[1024];
		while (fgets(line, MAX_CANON, stdin) != NULL)
		{
			if (pr_Count == pr_Limit)
			{
				wait(&status);
				--pr_Count;
			}
			
			// create child process using input from file
			createChildProcess(line, processName);
			++pr_Count;
			
			// check to see if any children have finished and, if so
			// decrement our count
			pid_t childpid;
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
		}
		
		// wait for all children to finish
		pid_t childpid;
		while ((childpid = wait(&status)) > 0);	
	}
	else
	{
		writeError("Input argument was not a number", processName);
	}

	return returnCode;
}
