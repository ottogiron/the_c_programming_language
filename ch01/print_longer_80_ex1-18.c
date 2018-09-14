#include <stdio.h>

#define MAX_LEN 3000

int getchar(char line[], int max);

int
main(){

}



int gettline(char line[], int max)
{
	int i, c;

	for (i = 0; i < max -1 && (c = getchar()) != EOF && c != '\n'; ++i ){
		if ( c != '\n' && c != '\t' && c != ' '){
			line[i] = c;
		}

		if (c == '\n'){
			line[c] = c;
			++i;
		}
	}
	printf("the line size is %d\n", i);
	return i;
}
