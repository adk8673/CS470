#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

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
