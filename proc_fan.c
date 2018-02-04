#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// Base code for this problem taken from the program 3.2
// on page 68 of Robbins 2003 textbook
int main(int argc, char *argv[]) {
	pid_t childpid = 0;

	char* str_prLimit = null;

	int c;
	if ((c = getopt(argc, argv, "nh") != -1)
	{
		switch(c)
		{
		case 'n':
			str_prLimit = optarg;
			executeForks(str_prLimit);
			break;
		case 'h':
			break;
		default:
			// output error, unknown argument
			break;
		}
	}
	else
		;// code to output error
	
/*	n = atoi(argv[1]);
	int i;
	for (i = 1; i < n; ++i)
		if ((childpid = fork()) <= 0)
			break;
	fprintf(stderr, "i:%d process ID: %ld parent ID: %ld child id:%ld\n",
*/			i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}

void displayHelp()
{
	//display options
}

int executeForks(const char* str_prLimit)
{
	// pr_Limit: maximum number of executing forks
	// pr_Count: currently execute number of child processes
	int pr_Limit, pr_Count = 0, returnCode = 0;
	
	if ()
		;

	return returnCode;
}
