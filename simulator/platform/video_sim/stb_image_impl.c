/* stb_image implementation unit — compiled exactly once.
 *
 * Restrict the parser surface to only the formats actually used by
 * --qr-image (PNG and JPEG). stb_image has a long history of integer
 * overflow CVEs in its less-common decoders, so disabling them removes
 * unreachable attack surface. */
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#define STBI_ONLY_JPEG
#define STBI_NO_FAILURE_STRINGS
#include "stb_image.h"
