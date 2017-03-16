#include <stdio.h>



#define MAX_SIZE 10


typedef struct st {
	int array[MAX_SIZE];   /* stack's elements */
	int top;	       /* stack's top */

} stack;

stack stack1;



int isEmpty()
{
	if (stack1.top == 0)
		return 1;
	return 0;
}

int isFull()
{
	if (stack1.top >= MAX_SIZE)
		return 1;
	return 0;
}


void push(int x)
{
	
	stack1.array[stack1.top] = x;
	stack1.top++; 
}


int pop()
{
	int a = stack1.array[stack1.top-1];
	stack1.top--;
	return a;


}

void see_stack()
{
	if (isEmpty())
	{
		printf("Empty stack\n");
		return;
	}
	else
	{
		printf("\nYour stack is made of ");
		int i;
		for (i = stack1.top - 1; i >= 0; i--)
		{
			printf("%d ", stack1.array[i]);
		}
		printf("\n");
	}

}

void main()
{

	stack1.top = 0; 
	int pick;
	printf("To push an element, press 1\nTo pop an element press 2\nTo see your elements press 3\nTo exit press 4\nyour choice = ");
	scanf("%d", &pick);
	while (pick != 4)
	{
		if (pick == 1 && !isFull())
		{	
			int x;
			printf("Insert an element : ");
			scanf("%d", &x);
			push(x);
		
		}
		else
		{
			if (pick == 2 && !isEmpty())
			{
				int c = pop();
				printf("The popped element was %d\n", c);
			}
			else
			{
				if (pick == 3)
				{
					see_stack();
				}
				
			}
		}
		printf("your choice = ");
		scanf("%d", &pick);

	}
}

