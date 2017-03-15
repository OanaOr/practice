#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* remove_spaces(char *source)
{	
	char *trimmed = source;
	char *fin = trimmed;
	while (*source != '\0')
	{
		if (*source != ' ')
		{
			*trimmed = *source;
			trimmed++;
			
		}
		source++;
		
	}
	*trimmed = '\0';
	printf("%s\n", trimmed);	
	return fin;
}
void main()
{

char orig[200] = "ana are mere multe";
char *final = remove_spaces(orig);
printf("%s\n", final);



}
