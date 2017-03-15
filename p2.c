#include <stdio.h>
#include <string.h>

void main()
{

char buff[200];
FILE *f = fopen("ana.txt", "r");
int n;
int word_counter = 0;
while (fscanf(f,"%s", buff) != EOF)
{	printf("%s\n",buff);
	word_counter++;	
}
fclose(f); 
printf("%d", word_counter);




}

