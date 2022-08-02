#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void* thread_function(void* arg);

int main(void)
{
	pthread_t pthread;
	int ret;
	int count = 5;

	ret = pthread_create(&pthread, NULL, thread_function, &count);
	if(ret != 0)
	{
		perror("pthread_create.\n");
		exit(0);
	}
	pthread_join(pthread, NULL);
	printf("Thread ended, process ended after.\n");

	return 0;
}

void* thread_function(void* arg)
{
	int i;
	printf("Thread begins running \n");
	for(i = 0; i < *(int *)arg; i++)
	{
		printf("Hello World.\n");
		sleep(1);
	}
	return NULL;
}

