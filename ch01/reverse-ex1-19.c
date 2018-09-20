#include <stdio.h>
#define MAX_LEN 3000

int gettline(char line[], int max);
void reverse(char line[]);

int 
main()
{

 int l;
 char line[MAX_LEN];
 while ((l = gettline(line, MAX_LEN)) > 0){
	reverse(line);
	printf("reversed:%s\n", line);
 }

 return 0;
}

void reverse(char line[])
{
  int l,i, c, temp;
  l = 0;
  for ( l = 0; (c = line[l]) != '\n'; ++l)
	;
  --l;
  
  for (i = 0; i <= l; ++i){
	temp = line[i];
	line[i] = line[l];
	line[l] = temp;
	--l;
  }
}

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


