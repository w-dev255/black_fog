#include "lib/IO/IO.h"
/*#include "lib/game/game.h"*/

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		return 1;
	}

	long int begining = 185403245329964;

	if (strcmp(argv[1], "--hacker") == 0) {
		ONELINE* oneline = calloc(1, sizeof(ONELINE));
		if (oneline == NULL) {
			return 1;
		}

		while (1) {
			fflush(stdout);

			printf("\n\n|-------------------------------------------|\n|                   MENU                    |\n|-------------------------------------------|\n\n");

			printf("	0. Start\n	1. Load\n	2.Quit\n\n");

			printf("user: ");
			oneline_input(oneline);

			if (strlen(oneline->buffer) == 0) {
				continue;
			} else if (strcmp(oneline->buffer, "0") == 0 || strcmp(oneline->buffer, "Start") == 0) {
					printf("Placeholder\n");
				}
			} else if (strcmp(oneline->buffer, "1") == 0 || strcmp(oneline->buffer, "Load") == 0) {
				printf("Placeholder\n");
			} else if (strcmp(oneline->buffer, "2") == 0 || strcmp(oneline->buffer, "Quit") == 0) {
				destroy_buffer(oneline);

				destroy_oneline(oneline);

				return 0;
			}
		}
	}

	return 0;
}
