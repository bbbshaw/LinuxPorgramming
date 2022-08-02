#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pid1, pid2;

	pid1 = fork();
	pid2 = fork();

	/* 
	call the fork function to creat a child process,
	child process & parent process the run then same code in diff  memeory space
	the PID of child process is return ed in the parent, 0 is return in the child 
	*/
	printf("pid1 = %d  pid2 = %d\n", pid1, pid2);
	printf("Hello World\n");

	return 0;
}

