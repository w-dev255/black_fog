#ifndef IO_H
	#define IO_H

	#define DEFAULT_BUFFER 9216

	#include <stdio.h>

	#include <stdlib.h>

	#include <string.h>

	typedef struct {
		char* buffer;
		size_t buffer_size;
	} ONELINE;

	void oneline_input(ONELINE* oneline) {
		if (oneline == NULL) {
			return;
		}

		if (oneline->buffer_size == 0) {
			oneline->buffer_size = DEFAULT_BUFFER;
		}

		if (oneline->buffer == NULL) {
			oneline->buffer = malloc(oneline->buffer_size);

			if (oneline->buffer == NULL) {
				return;
			}
		}

		if (fgets(oneline->buffer, oneline->buffer_size, stdin) == NULL) {
			return;
		}
		oneline->buffer[strcspn(oneline->buffer, "\n")] = '\0';

		return;
	}

	void destroy_buffer(ONELINE* oneline) {
		if (oneline == NULL) {
			return;
		}

		if (oneline->buffer != NULL) {
			free(oneline->buffer);
			oneline->buffer = NULL;
		}

		if (oneline->buffer_size != 0) {
			oneline->buffer_size = 0;
		}

		return;
	}

	void destroy_oneline(ONELINE* oneline) {
		if (oneline == NULL) {
			return;
		}

		if (oneline->buffer != NULL) {
			free(oneline->buffer);
			oneline->buffer = NULL;
		}

		if (oneline->buffer_size != 0) {
			oneline->buffer_size = 0;
		}

		free(oneline);

		return;
	}
#endif
