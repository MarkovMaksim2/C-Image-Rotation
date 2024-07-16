#ifndef ROTATE_H
#define ROTATE_H

#include "image.h"
#include <inttypes.h>

/* Image rotation on angle function.
 * ARGUMENTS:
 *   - pointer to image to rotate:
 *       struct image const *img;
 *   - rotation angle:
 *       int16_t angle;
 * RETURNS:
 *   (struct image) rotated image.
 */
struct image rotate(struct image const* img, int16_t angle);

#endif /* ROTATE_H */
