#ifndef DATA_MENAGER_H
	#define DATA_MENAGER_H

	#define DEFAULT_BUFFER_LIMIT 9216

	#include <stdio.h>

	#include <stdlib.h>

	#include <string.h>

	typedef struct {
		char* path;
		char* value;
	} DATA;

	void get_data_from(DATA* data) {
		if (data == NULL) {
			return;
		}

		if (data->path == NULL) {
			return;
		}

		FILE* f = fopen(path, "r");
		if (f == NULL) {
			return;
		}

		char* buffer = malloc(DEFAULT_BUFFER_LIMIT);
		if (buffer == NULL) {
			fclose(f);

			return;
		}

		if (fgets(buffer, DEFAULT_BUFFER_LIMIT, f) == NULL) {
			return;
		}
		buffer[strcspn(buffer, "\n")] = '\0';

		if (strlen(buffer) == 0) {
			fclose(f);

			free(buffer);

			return;
		} else {
			data->value = strdup(buffer);
			if (data->value == NULL) {
				fclose(f);

				free(buffer);

				return;
			}
		}

		return;
	}
#endif
