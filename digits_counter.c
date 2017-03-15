#include <stdio.h>

void main()
{

int counter[9];
int i;
char buff;
for (i = 0; i < 10; i++)
{
	counter[i] = 0;
}
FILE *f = fopen("ana2.txt", "r");
int c;

do 
{
	c = fgetc(f);

	if (c >= '0' && c <= '9' ) 
		counter[c-'0']++;	
}while (c!=EOF);
fclose(f); 

for (i = 0; i < 10; i++)
	printf("%d apare de %d\n", i, counter[i]);

}
