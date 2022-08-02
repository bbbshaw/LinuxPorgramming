#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//run model:  ./a.out 10 5 15   after xx time, terminated
int main(int argc, char* argv[])
{
	pid_t child_pid;
	int i,numDead;

	for (i = 1; i < argc; i++)
	{
		switch(fork())
		{
			case -1: 
				perror("fork()");
				exit(0);
			case 0:
				printf("Child %d started = %d, sleeping %s seconds\n", i, getpid(), argv[i]);
				sleep(atoi(argv[i]));
				exit(0);
			default:
				break;
		}
	}
	
	numDead = 0;
	while(1)
	{
		child_pid = wait(NULL);
		numDead++;
		if(child_pid == -1)
		{
			printf("No more child process\n");
			exit(0);
		}
		printf("wait() return child PID : %d (numDead = %d)\n",child_pid, numDead);
	}
	return 0;
}
