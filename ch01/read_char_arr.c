/*
 * =====================================================================================
 *
 *       Filename:  read_char_arr.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/11/2018 22:32:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#define MAXLINE 1000

int gettline(char line[], int maxline);
void copy(char to[], char from[]);

/*  print longest input line */
int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = gettline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) printf("the longest line is%s", longest);
	return 0;
}

/* gettline: read a line into s, return length */
int gettline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy from into to; assume to is jjbig enough */
void copy(char to[], char from[]) {
	int i;
	i = 0;

	while ((to[i] = from[i]) != '\0') ++i;
}
