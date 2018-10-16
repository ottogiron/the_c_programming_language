#include <stdio.h>

int main(int argc, char const *argv[]) {
	int c, b;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			while ((b = getchar()) == ' ')
				;
		putchar(c);
	}
	return 0;
}
