#include <stdio.h>
#define MAX_LEN 3000

int gettline(char line[], int max);
int  trimRight(char line[], int size);

int main() 
{
	int l, t;

	char line[MAX_LEN];

	while ( (l = gettline(line, MAX_LEN)) > 0 ) {
		t = trimRight(line, l);
		printf("%s trimmed:%d\n", line, t);
	}
	return 0;
}

int gettline(char line[], int max)
{
	int i, c;

	for (i = 0; i < max -1 && (c = getchar()) != EOF && c != '\n'; ++i ){
		line[i] = c;

	}
		if (c == '\n'){
			line[c] = c;
			++i;
		}
	return i;
}

int  trimRight(char line[], int size)
{
	if (size ==  0) {
		return 0;	
	}
	int i, t;
	t = 0;

	for ( i = size - 1; (line[i] == ' ' || line[i] == '\t') && i >= 0; i --)
		++t;		

	if (i > 0) {
		line[++i] = '\n';
		line[++i] = '\0';
	}
	return t;
}
