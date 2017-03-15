#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int word_counter(FILE *f)
{

	int word_counter = 0;	
	char buff[200];
	while (fscanf(f,"%s", buff) != EOF)
	{	//printf("%s\n",buff);
		word_counter++;	
	}
	//printf("avem %d\n", word_counter);
	return word_counter;


}


void main()
{


FILE *f = fopen("ana.txt", "r");
char c;
int s = word_counter(f);
fclose(f);
f = fopen("ana.txt", "r");
int *lengths = (int*)malloc(s*sizeof(int));
int word_length = 0;
int i = 0;

do
{
	c = fgetc(f);
	//printf("%c\n", c);
	if ( c!=' ' && c != '\t' && c != '\n')
	{
		//printf("1");
		word_length++;
	}	
	else
	{
		//printf("asa");
		lengths[i] = word_length;
		i++;
		//printf("lengths[i] = %d\n", lengths[i]);
		word_length = 0;
		//printf("%d\n", i);
	}
}while (c != EOF);
fclose(f); 

for (i = 0; i < s; i++)
{
	printf("%d ", lengths[i]);

}



}


