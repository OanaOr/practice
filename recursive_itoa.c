#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void turn_to_char (int x, char *t)
{
	if (x == 0)
		return;
	char s[1];
	s[0] = x%10+'0';
	x = x/10;
		
	turn_to_char(x, t);
	strcat(t, s);
		

}


void main()
{
int x;
printf("x = ");
scanf("%d", &x);

char *t = (char*)malloc(200*sizeof(char));
turn_to_char(x,t);

printf("x este acum %s\n", t);




}
