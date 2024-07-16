#include "../include/bmp_handle.h"
#include "../include/rotate.h"
#include "../include/tools.h"
#include <stdio.h>
#include <stdlib.h>

/* Calculating int value by string function.
 * ARGUMENTS:
 *   - number of arguments:
 *       int argc;
 *   - arguments array:
 *       char **array
 * RETURNS:
 *   (int) program code.
 */
int main( int argc, char** argv ) {
    FILE* in, *out;
    struct image img, img1;
    enum read_status rst;
    enum write_status wst;
    const char* rotation_angles[] = {
        "0", "90", "-90", "180", "270", "-270", "-180"
    };
    const uint8_t rotation_angles_size = 7;

    /* checking arguments */
    if (argc != 4) {
        fprintf(stderr, "There must be 3 arguments, you have %d arguments\n", argc);
        return 0;
    }

    if (!is_in_string_array(argv[3], rotation_angles, rotation_angles_size)) {
        fprintf(stderr, "Wrong angle: %s\n", argv[3]);
        return 0;
    }

    /* reading data from file */
    if ((in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return 0;
    }

    rst = from_bmp(in, &img);
    fclose(in);

    print_read_status(rst);
    if (rst != READ_OK) {
        return 0;
    }

    /* Rotating image */
    img1 = rotate(&img, (int16_t)atoi(argv[3]));
    destructor(&img);

    if (!img1.data) {
        fprintf(stderr, "Memory allocation error\n");
        return 0;
    }

    /* Writing data in file */
    if ((out = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", argv[2]);
        destructor(&img1);
        return 0;
    }

    wst = to_bmp(out, &img1);
    fclose(out);

    print_write_status(wst);
    destructor(&img1);

    return 0;
} /* end of 'main' function */
