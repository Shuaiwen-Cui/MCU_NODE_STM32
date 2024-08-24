#ifndef __FONT_H
#define __FONT_H
#include "stdint.h"
#include "string.h"

typedef struct ASCIIFont {
  uint8_t h;
  uint8_t w;
  uint8_t *chars;
} ASCIIFont;

extern const ASCIIFont afont8x6;
extern const ASCIIFont afont12x6;
extern const ASCIIFont afont16x8;
extern const ASCIIFont afont24x12;

/**
 * @brief Font structure
 * @note  The first 4 bytes of the font library store the UTF-8 encoding, the remaining bytes store the font data
 * @note  Font data can be generated using the Baud Dance LED Font Assistant (https://led.baud-dance.com)
 */
typedef struct Font {
  uint8_t h;              // Font height
  uint8_t w;              // Font width
  const uint8_t *chars;   // Font library: the first 4 bytes store the UTF-8 encoding, the remaining bytes store the font data
  uint8_t len;            // Length of the font library, change to uint16_t if it exceeds 256
  const ASCIIFont *ascii; // Default ASCII font, used when the corresponding character is not found in the font library and ASCII characters need to be displayed
} Font;

extern const Font font16x16;

/**
 * @brief Image structure
 * @note  Image data can be generated using the Baud Dance LED Font Assistant (https://led.baud-dance.com)
 */
typedef struct Image {
  uint8_t w;           // Image width
  uint8_t h;           // Image height
  const uint8_t *data; // Image data
} Image;

extern const Image bilibiliImg;

#endif /* __FONT_H */
