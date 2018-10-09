#include <stdio.h>

#define TAB_SPACE_TOKENS  4

int main(void)
{
	int c, spaceCount; 
	
	spaceCount = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ') {
			if (spaceCount == TAB_SPACE_TOKENS) {
				putchar('\t');
				spaceCount = 0;
			} else {
				++spaceCount;
			}  
		} else {
			putchar(c);
			spaceCount = 0;
		}	
	}
	return 0;
}
