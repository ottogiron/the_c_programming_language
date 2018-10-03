#include <stdio.h>

#define N  4
#define MAX_LEN 3000

int gettline(char line[], int max);
void detab(char line[]);

int main()
{
	char  line[MAX_LEN];	

	return 0;
}

//getline requires a MAX variable because the STDIN doesn provide a null character to stop :'(
int gettline(char line[], int max)
{
	int i, c;

	for (i = 0; i < max -1 && (c = getchar()) != EOF && c != '\n'; ++i ){
		line[i] = c;

	}

	if (c == '\n'){

		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}



