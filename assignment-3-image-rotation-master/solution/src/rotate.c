#include "../include/rotate.h"

#include <inttypes.h>

/* Image rotation on 90 degree angle function.
 * ARGUMENTS:
 *   - pointer to source image:
 *       struct image const *source;
 *   - pointer to destination image:
 *       struct image const *img;
 * RETURNS: None.
 */
void rotate90(struct image const* source, struct image* destination) {
	if (source->data && destination->data) {
		uint64_t i = 0, j = 0;

		for (i = 0; i < source->height; i++) {
			for (j = 0; j < source->width; j++) {
				destination->data[j * source->height + (source->height - i - 1)] = source->data[i * source->width + j];
			}
		}
	}
} /* end of 'rotate90' function */

/* Image rotation on 180 degree angle function.
 * ARGUMENTS:
 *   - pointer to source image:
 *       struct image const *source;
 *   - pointer to destination image:
 *       struct image const *img;
 * RETURNS: None.
 */
void rotate180(struct image const* source, struct image* destination) {
	if (source->data && destination->data) {
		uint64_t i, j;

		for (i = 0; i < source->height; i++) {
			for (j = 0; j < source->width; j++) {
				destination->data[source->height * source->width - i * source->width - j - 1] = source->data[i * source->width + j];
			}
		}
	}
} /* end of 'rotate180' function */

/* Image rotation on 270 degree angle function.
 * ARGUMENTS:
 *   - pointer to source image:
 *       struct image const *source;
 *   - pointer to destination image:
 *       struct image const *img;
 * RETURNS: None.
 */
void rotate270(struct image const* source, struct image* destination) {
	if (source->data && destination->data) {
		uint64_t i = 0, j = 0;

		for (i = 0; i < source->height; i++) {
			for (j = 0; j < source->width; j++) {
				destination->data[(source->width - j - 1) * source->height + i] = source->data[i * source->width + j];
			}
		}
	}
} /* end of 'rotate270' function */

/* Image rotation on angle function.
 * ARGUMENTS:
 *   - pointer to image to rotate:
 *       struct image const *img;
 *   - rotation angle:
 *       int16_t angle;
 * RETURNS:
 *   (struct image) rotated image.
 */
struct image rotate(struct image const* img, int16_t angle) {
	struct image rotated;;

	if (angle == 90 || angle == -270) {
		rotated = init(img->height, img->width);

		if (rotated.data) {
			rotate90(img, &rotated);
		}
	}
	else if (angle == 180 || angle == -180) {
		rotated = init(img->width, img->height);
		
		if (rotated.data) {
			rotate180(img, &rotated);
		}
	}
	else if (angle == 270 || angle == -90) {
		rotated = init(img->height, img->width);
		
		if (rotated.data) {
			rotate270(img, &rotated);
		}
	}
	else
		rotated = copy(img);

	return rotated;
} /* end of 'rotate' function */
