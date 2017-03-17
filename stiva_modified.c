#include <stdio.h>
:
#define MAX_SIZE 10


typedef struct st {
	int array[MAX_SIZE];   /* stack's elements */
	int top;	       /* stack's top */

} stack;

stack stack1;


/* no elements in the stack */
int isEmpty()
{
	if (stack1.top == 0)
		return 1;
	return 0;
}


/* stack has reached MAX_SIZE, can't add any more elements */
int isFull()
{
	if (stack1.top >= MAX_SIZE)
	{
		return 1;
	}
	return 0;
}


/* by the very definition of the stack, every element is added at the top */
void push(int x)
{
	
	stack1.array[stack1.top] = x;
	stack1.top++; 
}


/* we can only pop the last element we've added */
int pop()
{
	int a = stack1.array[stack1.top-1];
	stack1.top--;
	return a;

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
		for (i = stack1.top - 1; i >= 0; i--)
		{
			printf("%d ", stack1.array[i]);
		}
		
	}
}


void main()
{

	stack1.top = 0; 
	int pick;
	printf("To push an element, press 1.\nTo pop an element, press 2.\nTo see your elements, press 3.\nTo check the stack's state, press 4.\nTo exit, press 5.\nyour choice = ");
	scanf("%d", &pick);
	while (pick != 5)
	{
		if (pick == 1)
		{
			if (!isFull())
			{	
				int x;
				printf("Insert an element : ");
				scanf("%d", &x);
				push(x);
			}
			else
			{
				printf("Your stack has reached the maximum capacity of %d elements, please press 2 of you want to pop an element.\n", MAX_SIZE);
			}
		
		}
		else
		{
			if (pick == 2)
			{
				if (!isEmpty())
				{
					int c = pop();
					printf("The popped element was %d.\n", c);
				}
				else
				{
					printf("You're trying to pop an element from an empty stack, please press 1, so that you can push an element to the stack, before doing that.\n");
				}
			}
			else
			{
				if (pick == 3)
				{
					see_stack();
				}
				else
				{
					if (pick == 4)
					{
						if (isEmpty())
						{
							printf("The stack is empty, you can add up to %d elements.\n", MAX_SIZE);
						}
						else
						{
							if (isFull())
							{
								printf("The stack is full, you can not add any more elements.\n");
							}
							else
							{
								printf("The stack is neither full, not empty, you can add more %d elements.\n", MAX_SIZE - stack1.top);
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

