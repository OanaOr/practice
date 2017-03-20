#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>


#define MAX_SIZE 10


typedef struct st {
	int array[MAX_SIZE];   /* stack's elements */
	int top;	       /* stack's top */

} stack;

pthread_mutex_t lock;
int counter;
int pick;
pthread_t t[2];
/* no elements in the stack */
int isEmpty(stack *st)
{
	if (st->top == 0)
		return 1;
	return 0;
}


/* stack has reached MAX_SIZE, can't add any more elements */
int isFull(stack *st)
{
	if (st->top >= MAX_SIZE)
	{
		return 1;
	}
	return 0;
}


/* by the very definition of the stack, every element is added at the top */
int push(stack *st, int x)
{
	
	pthread_mutex_lock(&lock);
	pid_t a = syscall(__NR_gettid);;
	printf("Here is thread %u\n",a);
	if (!isFull(st))
	{
		st->array[st->top] = x;
		st->top++;
		pthread_mutex_unlock(&lock);

		return 1;
	}
	pthread_mutex_unlock(&lock);
	return 0; 
}


/* we can only pop the last element we've added */
void *pop(void *st1)
{
	stack *st = (stack*) st1;
	pthread_mutex_lock(&lock);
	pid_t x = syscall(__NR_gettid);;
	printf("\nHere is thread %u\n",x);
	if (!isEmpty(st))
	{
		int a = st->array[st->top-1];
		st->top--;
		pthread_mutex_unlock(&lock);
		return;
	}
	pthread_mutex_unlock(&lock);
	return;

}


/* elements are displayed in reverse order of their adding to the stack */
void see_stack(stack *st)
{
	if (isEmpty(st))
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



void *choice(void *st1)
{
	stack *st = (stack*) st1;
	
	counter++;
	printf("Thread %d started\n", counter);

	printf("To push an element, press 1.\nTo pop an element, press 2.\nTo see your elements, press 3.\nTo check the stack's state, press 4.\nTo exit, press 5.\nyour choice = ");
	scanf("%d", &pick);
	while (pick != 5)
	{
		if (pick == 1)
		{
				
			int x;
			printf("Insert an element : ");
			scanf("%d", &x);
			int res = push(st, x);
			if (res == 1)
				printf("The push was successful\n");
			else
				printf("The push was not successful\n");
		
		
		}
		else
		{
			if (pick == 2)
			{
	
				int err = pthread_create(&(t[1]), NULL, pop, (void*) st);
				if (err)
					printf("The popping was not succesful\n");
				else
					printf("The popping was succesful\n");
			}
			else
			{
				if (pick == 3)
				{
					see_stack(st);
				}
				else
				{
					if (pick == 4)
					{
						if (isEmpty(st))
						{
							printf("The stack is empty, you can add up to %d elements.\n", MAX_SIZE);
						}
						else
						{
							if (isFull(st))
							{
								printf("The stack is full, you can not add any more elements.\n");
							}
							else
							{
								printf("The stack is neither full, not empty, you can add more %d elements.\n", MAX_SIZE - st->top);
							}
						}
					}
					else
					{

						if (pick != 5)
						{
							printf("Invalid choice. Please try again.\n");
						
						}
					}
				}
				
			}
		}
		printf("your choice = ");
		scanf("%d", &pick);
		if(pick == 5)
		{
			
			pthread_join(t[0], NULL);
   			pthread_join(t[1], NULL);
			
		}
	}
	
}

void main()
{
	stack *st = (stack*)malloc(sizeof(stack));
	st->top = 0; 
	
	
	int i;

	if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Can't create mutex\n");
        return ;
    }


	for (i = 0; i < 1; i++)
    {
        int err = pthread_create(&(t[i]), NULL, choice, (void*) st);
        if (err != 0)
            printf("Can't create thread\n");
        i++;
        
    }

	pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    free(st);

	}


