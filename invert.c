#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int get_n_bits_inverted(int x, int p, int n)
{
	return ~(x >> (p-n+1) & ~(~0 << n)); 

}



void main()
{

unsigned int x, p, n, l;
scanf("%d", &x);
scanf("%d", &p);
scanf("%d", &n);


unsigned int t = get_n_bits_inverted(x, p, n);


printf("t = %d\n", t);


}
