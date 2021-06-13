#ifndef __PA_OLED_DRV_H__
#define __PA_OLED_DRV_H__

#define SSD1306_I2C_ADDRESS 0x3c //oled地址

#define OLED_Delay_Ms(t) pa_delayMs(t)

inline void OLED_Write_IIC_Command(unsigned char IIC_Command);
inline void OLED_Write_IIC_Data(unsigned char IIC_Data);
inline void OLED_iicWriteLen(unsigned char iicId, unsigned char addr, unsigned char length, unsigned char *data_wr);
// void OLED_initSpiGpio();
// void OLED_setCS(char state);
// void OLED_setDC(char state);
// void OLED_setRST(char state);
#endif // __PA_OLED_DRV_H__