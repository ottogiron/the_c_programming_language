#include <stdio.h>

int main(int argc, char const *argv[]) {
	int c, bl, tb, nl;

	while ((c = getchar()) != EOF) {
		if (c == '\t') ++tb;
		if (c == ' ') ++bl;
		if (c == '\n') ++nl;
	}
	printf("blanks:%d tabs:%d newlines:%d", bl, tb, nl);
	return 0;
}
