#ifndef __PA_OLED_DRV_H__
#define __PA_OLED_DRV_H__
#include "paCoreHead/paIIC.h"
#include "pa_oled_drv.h"

namespace SSD1306
{
    extern char protocalId;
}

#define SSD1306_I2C_ADDRESS 0x3c //oled地址
////////////////////////////////////////////////////////////////////////////////
inline void OLED_Write_IIC_Command(unsigned char cmd)
{
    char data[2];
    data[0] = 0x00;
    data[1] = cmd;
    _G_paIIC.writeLen(SSD1306::protocalId, SSD1306_I2C_ADDRESS, 2, data);
}
/**********************************************
// IIC Write Data
**********************************************/
inline void OLED_Write_IIC_Data(unsigned char cmd)
{
    char data[2];
    data[0] = 0x40;
    data[1] = cmd;
    _G_paIIC.writeLen(SSD1306::protocalId, SSD1306_I2C_ADDRESS, 2, data);
}

inline void OLED_iicWriteLen(unsigned char iicId, unsigned char addr, unsigned char length, unsigned char *data_wr)
{
    _G_paIIC.writeLen(iicId, addr, length, data_wr);
}
// void OLED_initSpiGpio();
// void OLED_setCS(char state);
// void OLED_setDC(char state);
// void OLED_setRST(char state);
#endif // __PA_OLED_DRV_H__