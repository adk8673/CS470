// Alex Kane
// 2/7/2018
// CS 4760 Project 1
// testsim.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

// small test application for proc_fan
// takes two arguments from the command line that determine how long to sleep
// and how many times to iterate
int main(int argc, char* argv[])
{
	int sleepTime, repeatCount, i;
	
	sleepTime = atoi(argv[0]);
	repeatCount = atoi(argv[1]);

	for (i = 0; i < repeatCount; ++i)
		sleep(sleepTime);
	
	char message[1024];
	snprintf(message, sizeof(message), "Current process: %d", getpid());
	perror(message);
	return 0;
}
