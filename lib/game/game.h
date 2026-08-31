#ifndef GAME_H
	#define GAME_H

	#include <stdio.h>

	#include <stdlib.h>

	#include <string.h>

	typedef struct {
		char* name;
		char* last_name;
		int age;
		char* gender;
		char** inventory;
		int inventory_size;
	} PLAYER_PROFILE;

	typedef struct {
		char* gang_name;
		char** gang_inventory;
		int inventory_size;
	} GANG;

	typedef struct {
		int karma;
	} PLAYER_STATUS;

	typedef struct {
		char* mission_id;
		char* save_point_id;
		char* data_path;
	} MISSION;

	typedef struct {
		char* state;
		char* city;
		char* house_adress;
		char* location;
	} MAP;

	typedef struct {
		PLAYER_PROFILE* player_profile;
		GANG* gang;
		PLAYER_STATUS* player_status;
		MISSION* mission;
		MAP* map;
	} PLAYER;

	char* fetch(char* id) {
		static const char* mission = "data/mission/id.txt";

		static const char* begining = "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e";

		FILE* f = fopen(mission, "r");
		if (f == NULL) {
			return NULL;
		}

		int buffer_size = 500;
		char* buffer = malloc(buffer_size);
		if (buffer == NULL) {
			fclose(f);

			return NULL;
		}

		char* start = NULL;
		char* end = NULL;
		char* out = NULL;
		int len = 0;

		if (strcmp(id, begining) == 0) {
			while (fgets(buffer, buffer_size, f) != NULL) {
				buffer[strcspn(buffer, "\n")] = '\0';

				if (strlen(buffer) == 0) {
					continue;
				} else {
					start = buffer;
					end = buffer;

					while (*start == ' ' || *start == '\t') {
						start++;
					}

					while (*start != '"') {
						start++;
					}

					while (*start == '"') {
						start++;
					}

					while (*end == ' ' || *end == '\t') {
						end++;
					}

					while (*end != '"') {
						end++;
					}

					while (*end == '"') {
						end++;
					}

					while (*end != '"') {
						end++;
					}

					while (*end == '"') {
						end--;
					}

					len = (end - start) + 1;

					if (out == NULL) {
						out = malloc(len + 1);
						if (out == NULL) {
							free(buffer);

							fclose(f);

							return NULL;
						}
					} else {
						out = realloc(out, (len + 1));
						if (out == NULL) {
							free(buffer);

							fclose(f);

							return NULL;
						}
					}

					memmove(out, start, len);
					out[len] = '\0';

					if (strcmp(id, out) == 0) {
						while (*start != '"') {
							start++;
						}

						while (*start == '=') {
							start++;
						}

						while (*start != '"') {
							start++;
						}

						while (*start == '"') {
							start++;
						}

						while (*end != '"') {
							end++;
						}

						while (*end == '"') {
							end++;
						}

						while (*end != '"') {
							end++;
						}

						while (*end == '"') {
							end--;
						}

						len = (end - start) + 1;

						out = realloc(out, (len + 1));
						if (out == NULL) {
							free(buffer);

							fclose(f);

							return NULL;
						}

						memmove(out, start, len);

						out[len] = '\0';

						free(buffer);

						fclose(f);

						return out;
					}
				}
			}
		}

		free(out);

		free(buffer);

		fclose(f);

		return NULL;
	}

	void save(PLAYER* player) {
		if (player == NULL) {
			return;
		}

		if (player->mission == NULL) {
			return;
		}

		if (player->mission->mission_id == NULL) {
			return;
		}

		char* path = fetch(player->mission->mission_id);
		if (path == NULL) {
			return;
		}

		FILE* f = fopen(path, "w");
		if (f == NULL) {
			return;
		}

		if (player->player_profile == NULL) {
			return;
		}

		if (player->player_profile->name == NULL) {
			return;
		}

		if (player->player_profile->last_name == NULL) {
			return;
		}

		if (player->player_profile->age <= 0) {
			return;
		}

		if (player->player_profile->gender == NULL) {
			return;
		}

		fprintf(f, "name:%s\n", player->player_profile->name);

		fprintf(f, "last_name:%s\n", player->player_profile->last_name);

		fprintf(f, "age:%d\n",  player->player_profile->age);

		fprintf(f, "gender:%s\n", player->player_profile->gender);

		if (player->player_profile->inventory_size <= 0) {
			return NULL;
		} else {
			fprintf(f, "inventory:[");
			for (int i = 0; i < player->player_profile->inventory_size; i++) {
				fprintf(f, "\"%s\",", player->player_profile->inventory[i]);
			}
			fprintf(f, "]\n");
		}

		free(path);

		return;
	}
#endif
