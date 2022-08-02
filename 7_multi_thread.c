#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count = 0;

void* thread1_function(void* arg);
void* thread2_function(void* arg);

int main(void)
{
	pthread_t pthread1, pthread2;
	int ret1, ret2;

	ret1 = pthread_create(&pthread1, NULL, thread1_function, NULL);
	if(ret1 != 0)
	{
		perror("pthread_create.\n");
		exit(1);
	}
	ret2 = pthread_create(&pthread2, NULL, thread2_function, NULL);
	if(ret2 !=0)
	{
		perror("pthread_creat.\n");
		exit(1);
	}
	pthread_join(pthread1, NULL);
	pthread_join(pthread2, NULL);
	printf("Thread ended, process ended after.\n");

	return 0;
}

void* thread1_function(void* arg)
{
	printf("Thread begins running \n");
	while(1)
	{
		printf("Thread1 count = %d.\n", count++);
		sleep(1);
	}
	return NULL;
}

void* thread2_function(void* arg)
{
	printf("Thread2 begins running.\n");
	while(1)
	{
		printf("Thread2 cout = %d.\n", count++);
		sleep(1);
	}
	return NULL;
}

