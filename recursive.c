#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *word, char *word1)
{
	//printf("word_original = %s\n", word);
	if (*word == '\0')
		return;
	reverse(word+1, word1);
	char s[1];
	s[0] = *word;
	strcat(word1, s);
}


void main()
{

char *word = (char*)malloc(200*sizeof(char));
char *word1 = (char*)malloc(200*sizeof(char));

fgets(word, 200, stdin);

reverse(word, word1);

printf("word reversed = %s\n", word1); 


}
