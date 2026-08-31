#include "lib/IO/IO.h"
#include "lib/game/game.h"

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		return 1;
	}

	const char* begining = "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e";

	if (strcmp(argv[1], "--hacker") == 0) {
		ONELINE oneline = {0};

		while (1) {
			fflush(stdout);

			printf("\n\n|-------------------------------------------|\n|                   MENU                    |\n|-------------------------------------------|\n\n");

			printf("	0. quit\n\n");

			printf("user: ");
			oneline_input(&oneline);

			if (strlen(oneline.buffer) == 0) {
				continue;
			} else {
				if (strcmp(oneline.buffer, "0") == 0 || strcmp(oneline.buffer, "quit") == 0) {
					destroy_buffer(&oneline);

					return 0;
				}
			}
		}
		destroy_buffer(&oneline);
	}

	return 0;
}
