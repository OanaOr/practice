#include <stdio.h>
#include <stdlib.h>
#include <math.h>


unsigned int setbits(unsigned int x,unsigned int p,unsigned int n, unsigned int y)
{
	int l;
	l = x & (x>>(p+1 - n)) & ~(~0<<n);
	return l;
}


int get_digits(unsigned int x)
{
	int i;
	for (i = 0; x > 0; x >>= 1)
		i++;
	return i;

}


unsigned int get_mask(unsigned int x, unsigned int p, unsigned int n)
{
	int i;
	int nr_digits = get_digits(x);
	int mask = 0;
	int power = 0;
	
       	printf("nr_digits = %d\n", nr_digits);
	for (i = 0; i < nr_digits; i++)
	{

		if (i > p || i <= (p-n) )
		{
			
			//printf("ana\n");	
			mask = mask+pow(2, power);
			//printf("masca este %d\n", mask);
		}
	
		power++;		
				 
			 
	}
	//printf("masca este %d\n", mask);
	return mask;
}


unsigned int get_mask2(unsigned int x, unsigned int p, unsigned int n)
{
	int i;
	int nr_digits = get_digits(x);
	int mask = 0;
	int power = 0;
	
       	printf("nr_digits = %d\n", nr_digits);
	for (i = 0; i < nr_digits; i++)
	{

		if (!(i > p || i <= (p-n)) )
		{
			
			//printf("ana\n");	
			mask = mask+pow(2, power);
			//printf("masca este %d\n", mask);
		}
	
		power++;		
				 
			 
	}
	//printf("masca este %d\n", mask);
	return mask;
}


void main()
{

unsigned int x, p, n, y, l;
scanf("%d", &x);
scanf("%d", &p);
scanf("%d", &n);
scanf("%d", &y);

unsigned int a = get_mask(x, p, n);
unsigned int b = get_mask2(y<<(p-n+1), p, n);
//printf("b = %d\n", b);
int t = ((x & a) + (y<<(p-n+1) & b));


printf("t = %d\n", t);


}
