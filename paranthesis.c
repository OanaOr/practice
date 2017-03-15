#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void main()
{


FILE *f = fopen("p2.c", "r");
int open_p_counter = 0;
int closed_p_counter = 0;
int i;

char c;
do
{
	c = fgetc(f);
	if (c == '(')
		open_p_counter++;
	if (c == ')')
		closed_p_counter++;
	

}
while (c!=EOF);
if (open_p_counter == closed_p_counter)
	printf("all is good\n");
else
	if (open_p_counter > closed_p_counter)
		for (i = 1; i <= open_p_counter - closed_p_counter; i++)
			printf("paranteza nr %d nu se inchide\n", i);
	else
		printf("ultimele %d paranteze sunt inutile\n", closed_p_counter - open_p_counter);
fclose(f); 





}


