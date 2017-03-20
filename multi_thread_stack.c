#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/types.h>
#include <sys/syscall.h>


#define MAX_SIZE 10


typedef struct st {
	int array[MAX_SIZE];   /* stack's elements */
	int top;	       /* stack's top */

} stack;

pthread_mutex_t lock;
stack *st;
pthread_t t[2];



/* stack has reached MAX_SIZE, can't add any more elements */
int isFull()
{
	if (st->top >= MAX_SIZE)
	{
		return 1;
	}
	return 0;
}




/* no elements in the stack */
int isEmpty()
{
	if (st->top == 0)
		return 1;
	return 0;
}



/* elements are displayed in reverse order of their adding to the stack */
void see_stack()
{
	if (isEmpty())
	{
		printf("Nothing to see here folks.\n");
		return;
	}
	else
	{
		printf("\nYour stack is made of the following elements : ");
		int i;
		for (i = st->top - 1; i >= 0; i--)
		{
			printf("%d ", st->array[i]);
		}
		
	}
	printf("\n");
}








/* by the very definition of the stack, every element is added at the top */
void *push()
{
	


	pthread_mutex_lock(&lock);
	pid_t x = syscall(__NR_gettid);;
	printf("Here is thread %u\n",x);
	while (!isFull())
	{
		int a = rand()%100; 
		st->array[st->top] = a;
		st->top++;
		

		
	}
	see_stack();
	pthread_mutex_unlock(&lock);
	return; 
}


/* we can only pop the last element we've added */
void *pop()
{
	pthread_mutex_lock(&lock);
	 pid_t x = syscall(__NR_gettid);;
	printf("Here is thread %u\n",x);
	while (!isEmpty(st))
	{
		int a = st->array[st->top-1];
		st->top--;
	}
	see_stack();
	pthread_mutex_unlock(&lock);
	return;

}







void main()
{
    st = (stack*)malloc(sizeof(stack));
	st->top = 0; 
		
	
	int i;
	srand(time(NULL));
	if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Can't create mutex\n");
        return ;
    }


	
        int err = pthread_create(&(t[0]), NULL, push, NULL);
        if (err != 0)
            printf("Can't create thread\n");
        pthread_join(t[0], NULL);
       
      int err1 = pthread_create(&(t[1]), NULL, pop, NULL);
       if (err1 != 0)
            printf("Can't create thread\n");
       
        
    

	
    pthread_join(t[1], NULL);
    free(st);

	}


