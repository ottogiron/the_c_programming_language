#include <stdio.h>

#define MAX_LEN 3000
int gettline(char line[], int max);

int main(void) {
	int len, c, i, in_comment;
	int first_slash, second_slash;
	int first_asterisk, second_asterisk, second_slash_asterisk;
	int in_line_comment, in_asterisk_comment;
	char line[MAX_LEN];
	in_comment = 0;
	first_slash = 0;
	first_asterisk = 0, second_asterisk = 0;
	in_line_comment = 0, in_asterisk_comment = 0;
	while ((len = gettline(line, MAX_LEN)) > 0) {
		for (i = 0; i < len; ++i) {
			c = line[i];
			if (c == '/') {
				if (!first_slash)
					first_slash = 1;
				else if (first_slash)
					in_line_comment = 1;
				else if (second_asterisk) {
					first_slash = 0;
					in_asterisk_comment = 0;
					second_asterisk = 0;
				}

			} else if (c == '*') {
				if (first_slash)
					in_asterisk_comment = 1;
				else if (in_asterisk_comment)
					second_asterisk = 1;
			} else if (c == '\n') {
				if (in_line_comment) {
					first_slash = 0;
					in_line_comment = 0;
				}
				if (!in_asterisk_comment) putchar('\n');
			} else {
				if (first_slash) first_slash = 0;
				if (!in_line_comment &&
				    !in_asterisk_comment) {  // not in comment
					putchar(c);
				}
			}
		}
	}
	return 0;
}

int gettline(char line[], int max) {
	int i, c;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
