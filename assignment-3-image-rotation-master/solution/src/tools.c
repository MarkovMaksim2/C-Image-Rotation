#include "../include/tools.h"
#include <string.h>

/* Checking is string in strings array function.
 * ARGUMENTS:
 *   - pointer to string:
 *       const char *str;
 *   - array pointer:
 *       const char** array;
 *   - array length:
 *       const uint64_t array_length;
 * RETURNS:
 *   (bool) true if string is in array.
 */
bool is_in_string_array(const char* str, const char** array, const uint64_t array_length) {
	size_t i;

	for (i = 0; i < array_length; i++) {
		if (strcmp(str, array[i]) == 0) {
			return true;
		}
	}
	return false;
} /* end of 'is_in_string_array' function */
