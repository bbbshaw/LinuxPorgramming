#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	int count = 0;

	pid = fork();

	if(pid > 0)
	{
		while(1)
		{
			printf("Hello World, count = %d\n", count++);
			sleep(1);
		}
	}
	else if(pid == 0)
	{
		while(1)
		{
			printf("Good Morning, count = %d\n", count++);
			sleep(2);
		}
	}
	else 
		perror("Fork\n");

	return 0;
}

