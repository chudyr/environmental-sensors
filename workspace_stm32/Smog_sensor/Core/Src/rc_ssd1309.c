#include "rc_ssd1309.h"

#define __SET_COL_START_ADDR() 	do { \
									rc_ssd1309_cmd(0x00); \
									rc_ssd1309_cmd(0x10); \
								} while(false)





void rc_ssd1308_drawBitmap(int x, int y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color);

uint8_t ssd1309_buf2[1024]={0};
uint8_t const bitmap[200]={		0xFF,0x01,0xC1,0x71,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0xF1,0x01,0x01,0xFF,
		0xFF,0xC0,0xCF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xCF,0xC8,0xC0,0xFF};


uint8_t  bitmap2[200]={			0xC0,0xFF,0xE1,0xED,0xE1,0xED,0xE1,0xED,0xE1,0xED,0xE1,0xED,0xE1,0xE1,0xFF,0xCC,
		0xCC,0xC0,0xC0,0xC0,0xC0,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xFF,0xC0,0xFF,
		0xC0,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xC1,0xFF,0xC0,0xC0,0xC0,
		0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xE1};


uint8_t ssd1309_buf[1024] =
{
		0x00,0x00,0x06,0x0A,0x12,0xFE,0x12,0x0A,0x06,0x80,0x00,0xC0,0x00,0xE0,0x00,0xF0,
			0x01,0x01,0x02,0x02,0x03,0x03,0x88,0x50,0xFE,0x22,0x54,0x88,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0x06,0x06,0xFE,0xFE,0x06,
			0x06,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF8,0x00,0x00,0x00,0x00,0x10,
			0x18,0x1C,0xFE,0xFE,0x1C,0x18,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0xFE,0x06,0xEE,0xDE,0xDE,0xEE,0x06,0xFE,0x06,0x76,0x76,0x8E,0xFE,
			0xF6,0xB6,0xB6,0x4E,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x08,0x0E,0x02,
			0xFA,0xFA,0xFA,0x02,0xFA,0xFA,0xFA,0x02,0xFA,0xFA,0xFA,0x02,0xFE,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x02,0x01,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x00,0x00,0x00,0x04,0x0C,0x1C,0x3F,0x3F,0x1C,0x0C,0x04,0x00,0x00,
			0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x0F,0x0C,0x0F,0x0F,0x0F,0x0F,0x0C,0x0F,0x0C,0x0F,0x0F,0x0F,0x0F,
			0x0D,0x0D,0x0D,0x0E,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x02,0x0E,0x08,
			0x0B,0x0B,0x0B,0x08,0x0B,0x0B,0x0B,0x08,0x0B,0x0B,0x0B,0x08,0x0F,0x00,0x00,0x00,
			0x00,0x00,0x1F,0x15,0x11,0x00,0x0E,0x11,0x01,0x2E,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x60,
			0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x04,0x04,0x04,0x04,0x78,0x00,0x00,0x78,0x84,
			0x84,0x84,0x84,0x00,0x00,0x00,0x00,0xF8,0xF8,0x18,0x38,0x78,0xF8,0xF8,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x60,0x60,0x60,0x00,0x00,0x66,0x66,0x66,
			0x66,0x66,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x66,0x66,
			0x66,0x66,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x10,0x10,0x10,0x10,0x0F,0x00,0x00,0x00,0x10,
			0x10,0x10,0x10,0x0F,0x00,0x00,0x00,0x3F,0x3F,0x30,0x38,0x3C,0x3E,0x3F,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x60,0x60,0x60,0x00,0x00,0x66,
			0x66,0x66,0x66,0x66,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x66,0x66,0x66,
			0x66,0x66,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x66,0x66,0x66,0x66,0x66,
			0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x60,0x60,0x60,0x60,0x60,0x00,0x00,
			0x60,0x60,0x60,0x60,0x60,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x66,0x66,
			0x66,0x66,0x66,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x60,0x60,0x60,0x60,
			0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x00,
			0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x80,0x80,
			0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0xFC,0xFF,0x83,0x83,0x83,0x83,0xFF,0xFC,0x00,0x00,0x03,0x03,0x03,
			0xFF,0xFF,0x03,0x03,0x03,0x00,0x00,0xFF,0xFF,0x0E,0x38,0xE0,0x80,0xFF,0xFF,0x00,
			0x00,0xFF,0xFF,0x63,0x63,0x63,0x03,0x03,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x1F,
			0x00,0x00,0x3F,0x20,0x20,0x20,0x00,0x00,0x3F,0x24,0x24,0x20,0x00,0x00,0x3F,0x20,
			0x20,0x20,0x1F,0x00,0x00,0x00,0xE0,0xE0,0x20,0x20,0x20,0xE0,0xC0,0x00,0x00,0xE0,
			0xE0,0x20,0x20,0x20,0x00,0x00,0xE0,0xE0,0xC0,0x80,0x00,0x80,0xC0,0xE0,0xE0,0x00,
			0x00,0xC0,0xE0,0x20,0x20,0x20,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x0F,0x0F,0x01,0x01,0x01,0x01,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,
			0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x03,0x0F,0x0F,0x00,
			0x00,0x0F,0x0F,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x0F,0x0F,0x0C,0x0C,0x0C,0x0C,
			0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x20,0x20,0x20,0x3F,0x1F,0x00,0x00,0x3F,
			0x3F,0x22,0x22,0x20,0x00,0x00,0x3F,0x3F,0x00,0x01,0x03,0x01,0x00,0x3F,0x3F,0x00,
			0x00,0x1F,0x3F,0x20,0x20,0x20,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

static void SPIwrite(uint8_t dat){

	uint8_t i;
	for(i = 0x80; i; i>>=1){
		OLED_SCK_LO;
		if(dat & i) OLED_MOSI_HI;
		else OLED_MOSI_LO;
		OLED_SCK_HI;
	}
}

void rc_ssd1309_cmd(uint8_t cmd){
	
	#if USE_CS == 1
	OLED_CS_HI;
	#endif
	
	OLED_DC_LO;
	
	#if USE_CS == 1
	OLED_CS_LO;
	#endif	
	
	SPIwrite(cmd);

	#if USE_CS == 1
	OLED_CS_HI;
	#endif		
}

void rc_ssd1309_data(uint8_t dat){
	
	#if USE_CS == 1
	OLED_CS_HI;
	#endif
	
	OLED_DC_HI;
	
	#if USE_CS == 1
	OLED_CS_LO;
	#endif
	
	SPIwrite(dat);

	#if USE_CS == 1
	OLED_CS_HI;
	#endif	
}












void rc_ssd1306_init (void){
	
	OLED_RST_HI;
	HAL_Delay(50);
	OLED_RST_LO;
	HAL_Delay(50);
	OLED_RST_HI;
		
	rc_ssd1309_cmd(0xAE);//--turn off oled panel
	rc_ssd1309_cmd(0x00);//---set low column address
	rc_ssd1309_cmd(0x10);//---set high column address
	rc_ssd1309_cmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	//rc_ssd1309_cmd(0x20);
	rc_ssd1309_cmd(0x81);//--set contrast control register
	rc_ssd1309_cmd(0x7F);// Set SEG Output Current Brightness  cf
	rc_ssd1309_cmd(0xA1);//--Set SEG/Column Mapping  A0
	rc_ssd1309_cmd(0xC8);//Set COM/Row Scan Direction  C0
	rc_ssd1309_cmd(0xA6);//--set normal display
	rc_ssd1309_cmd(0xA8);//--set multiplex ratio(1 to 64)
	rc_ssd1309_cmd(0x3F);//--1/64 duty
	rc_ssd1309_cmd(0xD3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	rc_ssd1309_cmd(0x00);//-not offset
	rc_ssd1309_cmd(0xD5);//--set display clock divide ratio/oscillator frequency
	rc_ssd1309_cmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	rc_ssd1309_cmd(0xD9);//--set pre-charge period
	rc_ssd1309_cmd(0xF1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock	
	rc_ssd1309_cmd(0xDA);//--set com pins hardware configuration
	rc_ssd1309_cmd(0x12);
	rc_ssd1309_cmd(0xDB);//--set vcomh
	rc_ssd1309_cmd(0x40);//Set VCOM Deselect Level
	rc_ssd1309_cmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
	rc_ssd1309_cmd(0x00);//02-default
	rc_ssd1309_cmd(0x8D);//--set Charge Pump enable/disable		
	rc_ssd1309_cmd(0x14);//--set(0x10) disable
	rc_ssd1309_cmd(0xA4);// Disable Entire Display On (0xa4/0xa5)
	rc_ssd1309_cmd(0xA6);// Disable Inverse Display On (0xa6/a7)
	rc_ssd1309_cmd(0xAF);//--turn on oled panel		
	

	rc_ssd1309_display_clear();


}

void rc_ssd1309_display(void){
	rc_ssd1309_cmd(SSD1306_SETLOWCOLUMN | 0x0);//--turn off oled panel
	rc_ssd1309_cmd(SSD1306_SETHIGHCOLUMN | 0x0);//---set low column address
	rc_ssd1309_cmd(SSD1306_SETSTARTLINE | 0x0);//---set high column address
	//rc_ssd1309_cmd(0x21);
	#if USE_CS == 1
	OLED_CS_HI;
	#endif

	OLED_DC_HI;

	#if USE_CS == 1
	OLED_CS_LO;
	#endif

	for(uint16_t i=0; i<(SSD1309_WIDTH*SSD1309_HEIGHT/8); i++)
	{
		SPIwrite(ssd1309_buf[i]);

	}

	#if USE_CS == 1
	OLED_CS_HI;
	#endif
}

void rc_ssd1309_display_clear(void){
	rc_ssd1309_cmd(SSD1306_SETLOWCOLUMN | 0x0);//--turn off oled panel
	rc_ssd1309_cmd(SSD1306_SETHIGHCOLUMN | 0x0);//---set low column address
	rc_ssd1309_cmd(SSD1306_SETSTARTLINE | 0x0);//---set high column address
	//rc_ssd1309_cmd(0x21);
	#if USE_CS == 1
	OLED_CS_HI;
	#endif

	OLED_DC_HI;

	#if USE_CS == 1
	OLED_CS_LO;
	#endif

	for(uint16_t i=0; i<(SSD1309_WIDTH*SSD1309_HEIGHT/8); i++)
	{
		ssd1309_buf[i]=0;
		//SPIwrite(ssd1309_buf2[i]);

	}

	#if USE_CS == 1
	OLED_CS_HI;
	#endif
}

void rc_ssd1309_setPixel(int x, int y, uint8_t bw){

	if(bw) ssd1309_buf[x + (y/8)*128] |= (1<<(y%8));
	else ssd1309_buf[x + (y/8)*128] &= ~(1<<(y%8));
}





















