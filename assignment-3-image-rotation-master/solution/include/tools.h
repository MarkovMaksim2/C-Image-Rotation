#ifndef TOOLS_H
#define TOOLS_H

#include <inttypes.h>
#include <stdbool.h>

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
bool is_in_string_array(const char* str, const char** array, const uint64_t array_length);

#endif /* TOOLS_H */
