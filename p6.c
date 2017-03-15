#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* reverse(char *source)
{	
	int i; 
	for (i = 0; i < strlen(source)/2; i++)
	{
		char aux = source[i];
		source[i] = source[strlen(source) - i - 1];
		source[strlen(source) - i - 1] = aux;
	}
	//printf("%s\n", source);		
	return source;
}
void main()
{

char orig[200] = "ana are mere multe";
char *final = reverse(orig);
printf("%s\n", final);

}
