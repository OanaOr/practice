#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *squeeze(char *a, char *b)
{
int i;
	char *t = a;
	char *l = t;
	while (*a != '\0')
	{
		if (strchr(b, *a) == NULL)
		{
			*t = *a;
			t++;
			
		}
		a++;
		//printf("ana\n");
	}
	*t = '\0';
	//printf("%s", l);
	return l;

}


void main()
{

char word1[100];
fgets(word1, sizeof(word1), stdin);
//printf("%d\n", strlen(word1));
char word2[100];
fgets(word2, sizeof(word2), stdin);
char *p = squeeze(word1, word2);
//printf("ana");
printf("%s\n", p);


}



