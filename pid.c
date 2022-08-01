#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main(void)
{
	pid_t pid;

	while(1)
	{
		printf("pid = %d\n", getpid());
		printf("ppod = %d\n", getppid());
		printf("hello world\n");
		sleep(1);
	}
	return 0;
}
