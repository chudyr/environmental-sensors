#ifndef __rc_ssd1309_H_
#define __rc_ssd1309_H_

#include "stm32f0xx_hal.h"


#define SSD1309_128_64

#define USE_CS		1
#define USE_RST		1

#define OLED_SPI_SCK_PIN        GPIO_PIN_5
#define OLED_SPI_MOSI_PIN       GPIO_PIN_7
#define OLED_SPI_RST_PIN		GPIO_PIN_3
#define OLED_SPI_DC_PIN       	GPIO_PIN_2
#define OLED_SPI_CS_PIN			GPIO_PIN_4

#define OLED_SPI_SCK_PORT       GPIOA
#define OLED_SPI_MOSI_PORT      GPIOA
#define OLED_SPI_RST_PORT		GPIOA
#define OLED_SPI_DC_PORT      	GPIOA
#define OLED_SPI_CS_PORT		GPIOA


#define OLED_SCK_LO						OLED_SPI_SCK_PORT ->BRR = (uint32_t)OLED_SPI_SCK_PIN
#define OLED_SCK_HI						OLED_SPI_SCK_PORT->BSRR = (uint32_t)OLED_SPI_SCK_PIN
#define OLED_MOSI_LO					OLED_SPI_MOSI_PORT ->BRR = (uint32_t)OLED_SPI_MOSI_PIN
#define OLED_MOSI_HI					OLED_SPI_MOSI_PORT->BSRR = (uint32_t)OLED_SPI_MOSI_PIN
#define OLED_RST_LO						OLED_SPI_RST_PORT ->BRR = (uint32_t)OLED_SPI_RST_PIN
#define OLED_RST_HI						OLED_SPI_RST_PORT->BSRR = (uint32_t)OLED_SPI_RST_PIN
#define OLED_DC_LO						OLED_SPI_DC_PORT ->BRR = (uint32_t)OLED_SPI_DC_PIN
#define OLED_DC_HI						OLED_SPI_DC_PORT->BSRR = (uint32_t)OLED_SPI_DC_PIN
#define OLED_CS_LO						OLED_SPI_CS_PORT ->BRR = (uint32_t)OLED_SPI_CS_PIN
#define OLED_CS_HI						OLED_SPI_CS_PORT->BSRR = (uint32_t)OLED_SPI_CS_PIN


#define SSD1306_SETLOWCOLUMN 0x00  ///< Not currently used
#define SSD1306_SETHIGHCOLUMN 0x10 ///< Not currently used
#define SSD1306_SETSTARTLINE 0x40  ///< See datasheet



#if defined SSD1309_128_64
	#define SSD1309_HEIGHT		64
	#define SSD1309_WIDTH		128
#endif
#if defined SSD1306_128_32
	#define SSD1306_HEIGHT		32
#endif

#define REFRESH_MIN		0x80
#define REFRESH_MID		0xB0
#define REFRESH_MAX		0xF0

void rc_ssd1306_init (void);

void rc_ssd1309_display(void);
void rc_ssd1309_display_clear(void);

void rc_ssd1309_setPixel(int x, int y, uint8_t bw);

#define swap(a,b) { int16_t t = a; a = b; b = t; }



#endif
