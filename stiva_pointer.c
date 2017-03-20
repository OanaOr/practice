#include <stdio.h>
#include <stdlib.h>



#define MAX_SIZE 10


typedef struct st {
	int array[MAX_SIZE];   /* stack's elements */
	int top;	       /* stack's top */

} stack;



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
	if (!isFull(st))
	{
		st->array[st->top] = x;
		st->top++;
		return 1;
	}
	return 0; 
}


/* we can only pop the last element we've added */
int pop(stack *st)
{
	if (!isEmpty(st))
	{
		int a = st->array[st->top-1];
		st->top--;
		return 1;
	}
	return 0;

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


void main()
{
	stack *st = (stack*)malloc(sizeof(stack));

	st->top = 0; 
	int pick;
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
	
				int res = pop(st);
				if (res == 1)
					printf("The popping was succesful\n");
				else
					printf("The popping was not succesful\n");
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

	}
}

