#include <stdio.h>

#define MAX_LEN 3000
int gettline(char line[], int max);
#define STATE_NONE 0
#define STATE_FIRST_SLASH 1
#define STATE_IN_LINE_COMMENT 3
#define STATE_IN_ASTERISK_COMMENT 4
#define STATE_IN_SECOND_ASTERISK 5

int main(void) {
	int len, c, i;
	char line[MAX_LEN];
	int state;
	state = STATE_NONE;
	while ((len = gettline(line, MAX_LEN)) > 0) {
		for (i = 0; i < len; ++i) {
			c = line[i];
			if (c == '/') {
				if (state == STATE_NONE) {
					state = STATE_FIRST_SLASH;
				} else if (state == STATE_FIRST_SLASH) {
					state = STATE_IN_LINE_COMMENT;
				} else if (state == STATE_IN_SECOND_ASTERISK) {
					state = STATE_NONE;
				}
			} else if (c == '*') {
				if (state == STATE_FIRST_SLASH) {
					state = STATE_IN_ASTERISK_COMMENT;
				} else if (state == STATE_IN_ASTERISK_COMMENT) {
					state = STATE_IN_SECOND_ASTERISK;
				}
			} else if (c == '\n') {
				if (state == STATE_IN_LINE_COMMENT) {
					state = STATE_NONE;
				}
			} else {
				if (state == STATE_FIRST_SLASH) {
					state = STATE_NONE;
				} else if (state == STATE_IN_SECOND_ASTERISK) {
					state = STATE_IN_ASTERISK_COMMENT;
				} else if (state == STATE_NONE) {
					state = STATE_NONE;
				}
			}

			if (state == STATE_NONE && c != '/') {
				putchar(c);
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
