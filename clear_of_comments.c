#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *clear_of_bars(char *line)
{
	char *aux = strstr(line, "//");
	char *aux2 = (char*)malloc(sizeof(char)*200);
	strncpy(aux2,line, strlen(line) - strlen(aux));
	//aux2[ strlen(line) - strlen(aux)]='\n';
	return aux2;
}


char *clear_of_stars(char *line)
{
	char *aux = strstr(line, "/*");
	char *aux2 = (char*)malloc(sizeof(char)*200);
	strncpy(aux2,line, strlen(line) - strlen(aux));
	//aux2[ strlen(line) - strlen(aux)]='\n';
	return aux2;
}


char *trim_after_stars(char *line)
{
	char *aux = strstr(line, "*/");
	char *aux2 = (char*)malloc(sizeof(char)*200);
	if(strlen(aux+2)>0)
		strcpy(aux2,aux+2);
		//aux2[ strlen(line) - strlen(aux)]='\n';
	return aux2;
}



void main()
{

char buff[200];
FILE *f = fopen("ana.txt", "r");
int n, OK = 0;
int line_counter = 0;
char *final = (char*)malloc(2000*sizeof(char));
while (fgets(buff, 200, f) != NULL)
{	
	if (strstr(buff, "//"))
	{
		strcpy(final+strlen(final), clear_of_bars(buff));
		//final[strlen(final)+strlen(buff)] = '\0';
		
	
	}

	if (strstr(buff,"/*") && OK == 0)
	{
		strcpy(final+strlen(final), clear_of_stars(buff));
		OK = 1;
		
	}
	if (OK == 1);
	
	if (strstr(buff, "*/") && OK == 1)
	{
		OK = 0;
	}
	if (OK == 0 && strstr(buff, "*/") == NULL && strstr(buff, "//") ==NULL)
	{
		strcpy(final+strlen(final), buff);
	
	} 
		
}
printf("%s", final);
fclose(f); 





}


