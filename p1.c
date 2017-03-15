#include <stdio.h>
#include <string.h>

void main()
{

char buff[200];
FILE *f = fopen("ana.txt", "r");
int n;
int line_counter = 0;
while (fgets(buff, 200, f) != NULL)
{	
	line_counter++;	
}
fclose(f); 
printf("%d", line_counter);




}
