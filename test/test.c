#include "lib/third-party/cJSON/cJSON.h"

int main(void) {
	cJSON* path = json_load("dummy.json");

	return 0;
}
