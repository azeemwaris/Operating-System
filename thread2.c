#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* sum(void* arguments);
void* parent(void* args);

int sumv = 0;
int array[10000];

typedef struct s_arg
{
	int start;
	int end;
}arg;

int main()
{
	pthread_t p;

	for(int i = 0; i<10000; i++)
	{
		array[i] = i;
	}

	pthread_create(&p,NULL,parent,NULL);
	
	pthread_join(p,NULL);

	printf("\n");
	printf("Total sum: %d \n",sumv);
	
	printf("Main executed\n");
	return 0;
}

void* parent(void* argv)
{
	
	arg arguments;
	arg* address;
	pthread_t p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
	
	
	arguments.start=0;
	arguments.end=1000;
	
	address=&arguments;
	pthread_create(&p1,NULL,sum,(void*)address);
	
	
	arguments.start=1000;
	arguments.end=2000;
	
	address=&arguments;
	pthread_create(&p2,NULL,sum,(void*)address);

	
	arguments.start=2000;
	arguments.end=3000;
	
	address=&arguments;
	pthread_create(&p3,NULL,sum,(void*)address);

	
	arguments.start=3000;
	arguments.end=4000;
	
	address=&arguments;
	pthread_create(&p4,NULL,sum,(void*)address);

	
	arguments.start=4000;
	arguments.end=5000;
	
	address=&arguments;
	pthread_create(&p5,NULL,sum,(void*)address);

	
	arguments.start=5000;
	arguments.end=6000;
	
	address=&arguments;
	pthread_create(&p6,NULL,sum,(void*)address);

	
	arguments.start=6000;
	arguments.end=7000;
	
	address=&arguments;
	pthread_create(&p7,NULL,sum,(void*)address);

	
	arguments.start=7000;
	arguments.end=8000;
	
	address=&arguments;
	pthread_create(&p8,NULL,sum,(void*)address);

	
	arguments.start=8000;
	arguments.end=9000;
	
	address=&arguments;
	pthread_create(&p9,NULL,sum,(void*)address);

	
	arguments.start=9000;
	arguments.end=10000;
	
	address=&arguments;
	pthread_create(&p10,NULL,sum,(void*)address);	
	
	

	pthread_join(p1,NULL);
		
	
	pthread_join(p2,NULL);
	

	pthread_join(p3,NULL);
	

	pthread_join(p4,NULL);
	

	pthread_join(p5,NULL);
	

	pthread_join(p6,NULL);
	

	pthread_join(p7,NULL);
	

	pthread_join(p8,NULL);
	

	pthread_join(p9,NULL);
	

	pthread_join(p10,NULL);
	
	
	
	return NULL;	
}


void* sum(void* arguments)
{
	arg *temp = (arg*)arguments;

	for (int i=temp->start; i<temp->end; i++)
		sumv = array[i]+sumv+1;

	printf("%d to %d thread  ",temp->start,temp->end);
	printf("%d  \n",sumv);
	return NULL;
}
