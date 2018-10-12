#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 3000

int gettline(char line[], int max);

void fold(char line[], int size, int n);


int main(int argc,char *argv[] )
{
	if (argc > 2) {
		printf("the number of arguments is invalid %d", argc -1);
		return -1;
	}

	if (argc < 2) {
		printf("usage: %s <n>",argv[0]);
		return -1;
	}


	int l, n;
	char line[MAX_LEN];
	n = atoi(argv[1]);
	while ((l = gettline(line, MAX_LEN)) > 0) {
		if (l > n) { // only fold if line > n
			fold(line,l, n);	
		}	
	}
	return 0;
}


void fold(char line[], int size, int n) {
	int i, curcolpos, j , c;
	int stop, mergespace;
	
	i = 0;
	j = i + n;
	if(j > size)
		j = size;
	
	curcolpos = j;
	while(i < (size -1)) {
	   
	    stop = 0;
	    //remove wite spaces from the right from the new fold line
	    while (j>i && stop == 0){
		    c = line[j];
		    if ((c == '\t' || c ==' ')) {//if line from the position of the column is space, ignore it and don't print it
			--j;	
		    } else {
			stop = 1;
		    }
	    }

	    //With merge spaces, if there's more than one space, that is tracked. When a non space character is found a single character is written (merge of all the previous)
	    mergespace = 0;
	    while (i <= j){
		    c = line[i];
		    if (c == ' ')
			    mergespace = 1;
		    else {
			    if (mergespace == 1){
				    mergespace  = 0;
				     putchar(' ');
			    }
		     	putchar(c);
		    }
		    ++i;
	    }

	    putchar('\n'); //actually fold
	 	
	    i = curcolpos + 1; 
	    //ignore spaces at the begining of the line
	    while((c = line[i]) == ' '){
		    ++i;
	    }

	    j = curcolpos + n;//j should continue on the current "real" right position, ignoring posible white spaces ignored moving backward.
	    if (j > size)
		    j = size;
	    curcolpos = j;
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

