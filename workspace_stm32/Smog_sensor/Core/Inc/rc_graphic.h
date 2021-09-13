/*
 * rc_graphic.h
 *
 *  Created on: 7 mar 2021
 *      Author: Programista
 */

#ifndef INC_RC_GRAPHIC_H_
#define INC_RC_GRAPHIC_H_


void rc_ssd1309_drawchar(int x, int y, char c, uint8_t color, uint8_t bg );


void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void rc_ssd1309_puts(int x, int y, char *str, uint8_t color, uint8_t bg);

#endif /* INC_RC_GRAPHIC_H_ */
