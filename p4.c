#include <stdio.h>
#include <string.h>

void main()
{

char buff[200];
FILE *f = fopen("ana.txt", "r");
int n;
int line_counter = 0;
int max_line = 0;
char longest[200];
while (fgets(buff, 200, f) != NULL)
{	
	if (strlen(buff) > max_line)
	{
		max_line = strlen(buff);
		strcpy(longest, buff);
	} 	
}
fclose(f); 
printf("%s", longest);




}

