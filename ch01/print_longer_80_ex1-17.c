#include <stdio.h>
#define MAX_LEN 3000
int gettline(char line[], int max);






int main() 
{
  	int l;
	char line[MAX_LEN];

	while( (l = gettline(line, MAX_LEN)) > 0 ){
		/* line lenght must be greater than 80 */
		if ( l > 80 ){
			printf("%s len:%d", line, l);				
		}
	}				
	return 0;
}

int gettline(char line[], int max)
{
	int i, c;

	for (i = 0; i < max -1 && (c = getchar()) != EOF && c != '\n'; ++i ){
		line[i] = c;

		if (c == '\n'){
			line[c] = c;
			++i;
		}
	}
	printf("the line size is %d\n", i);
	return i;
}
