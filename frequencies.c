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
int freq[256], i;
f = fopen("ana.txt", "r");

for (i = 0; i < 256; i++)
{
	freq[i] = 0;

}


do
{
	c = fgetc(f);
	if (c == EOF) break;
	//printf("%c", c);
	freq[(int)c]++;
	//printf("char %c apare de %d\n", c, freq[(int) c]);
	
}while (c != EOF);
fclose(f); 

for (i = 0; i < 256; i++)
{
	printf("char %c apare de %d\n", (char) i, freq[i]);

}



}


