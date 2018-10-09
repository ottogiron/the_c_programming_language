#include <stdio.h>

#define N  4
#define MAX_LEN 3000


int main()
{
	int c, j;

	while ((c = getchar()) != EOF)
	{
	   	if(c == '\t')
			for(j = 0; j< N; ++j)
			putchar(' ');
		else 
			putchar(c);
	}

	return 0;
}

