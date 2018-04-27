#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* sum(void* arguments);

typedef struct s_arg
{
	int start;
	int end;
	int* array;
}arg;

int main()
{
	arg arguments[10];
	arg* address;
	int array1[1000];
	int sumr[10];
	int total=0;
	void* returnvalue;
	pthread_t p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
	
	for (int i=0; i<1000; i++)
		array1[i]=i+1;
	
	arguments[0].start=0;
	arguments[0].end=100;
	arguments[0].array=array1;
	address=&arguments[0];
	pthread_create(&p1,NULL,sum,(void*)address);
	
	arguments[1].start=100;
	arguments[1].end=200;
	arguments[1].array=array1;
	address=&arguments[1];
	pthread_create(&p2,NULL,sum,(void*)address);

	arguments[2].start=200;
	arguments[2].end=300;
	arguments[2].array=array1;
	address=&arguments[2];
	pthread_create(&p3,NULL,sum,(void*)address);

	arguments[3].start=300;
	arguments[3].end=400;
	arguments[3].array=array1;
	address=&arguments[3];
	pthread_create(&p4,NULL,sum,(void*)address);

	arguments[4].start=400;
	arguments[4].end=500;
	arguments[4].array=array1;
	address=&arguments[4];
	pthread_create(&p5,NULL,sum,(void*)address);

	arguments[5].start=500;
	arguments[5].end=600;
	arguments[5].array=array1;
	address=&arguments[5];
	pthread_create(&p6,NULL,sum,(void*)address);

	arguments[6].start=600;
	arguments[6].end=700;
	arguments[6].array=array1;
	address=&arguments[6];
	pthread_create(&p7,NULL,sum,(void*)address);

	arguments[7].start=700;
	arguments[7].end=800;
	arguments[7].array=array1;
	address=&arguments[7];
	pthread_create(&p8,NULL,sum,(void*)address);

	arguments[8].start=800;
	arguments[8].end=900;
	arguments[8].array=array1;
	address=&arguments[8];
	pthread_create(&p9,NULL,sum,(void*)address);

	arguments[9].start=900;
	arguments[9].end=1000;
	arguments[9].array=array1;
	address=&arguments[9];
	pthread_create(&p10,NULL,sum,(void*)address);	


	pthread_join(p1,(int*)&returnvalue);
	sumr[0]=(int)returnvalue;	
	
	pthread_join(p2,&returnvalue);
	sumr[1]=(int)returnvalue;

	pthread_join(p3,&returnvalue);
	sumr[2]=(int)returnvalue;

	pthread_join(p4,&returnvalue);
	sumr[3]=(int)returnvalue;

	pthread_join(p5,&returnvalue);
	sumr[4]=(int)returnvalue;

	pthread_join(p6,&returnvalue);
	sumr[5]=(int)returnvalue;

	pthread_join(p7,&returnvalue);
	sumr[6]=(int)returnvalue;

	pthread_join(p8,&returnvalue);
	sumr[7]=(int)returnvalue;

	pthread_join(p9,&returnvalue);
	sumr[8]=(int)returnvalue;

	pthread_join(p10,&returnvalue);
	sumr[9]=(int)returnvalue;
	
	printf("\n");

	for (int i=0; i<10; i++)
		total=total+sumr[i];

	printf("Total: %d \n",total);
	
	printf("Main executed\n");
	return 0;
}

void* sum(void* arguments)
{
	arg* temp = (arg*)arguments;
	int sum = 0;
	arg temp2;
	temp2.start=temp->start;
	temp2.end=temp->end;

	for (int i=temp2.start; i<temp2.end; i++)
		sum = temp->array[i]+sum;
	
	printf("%d to %d thread  ",temp2.start,temp2.end);
	printf("%d  \n",sum);
	return (void*)sum;
}
