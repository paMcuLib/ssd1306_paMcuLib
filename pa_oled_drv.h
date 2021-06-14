#ifndef __PA_OLED_DRV_H__
#define __PA_OLED_DRV_H__

#include "./pa_oled_drv.h"
#include "paCoreHead/paIIC.h"

#define SSD1306_I2C_ADDRESS 0x3c //oled地址

#define OLED_Delay_Ms(t) pa_delayMs(t)
namespace SSD1306
{
    extern char protocalId;
}
// inline
inline void OLED_iicWriteLen(unsigned char addr, unsigned char length, ByteArr data_wr[])
{
    _G_paIIC.writeLen(SSD1306::protocalId, addr, length, data_wr);
}

////////////////////////////////////////////////////////////////////////////////
inline void OLED_Write_IIC_Command(unsigned char cmd)
{
    uint8_t data1[2];
    data1[0] = 0x00;
    data1[1] = cmd;
    auto ba = ByteArr(2, data1);
    OLED_iicWriteLen(SSD1306_I2C_ADDRESS, 1, &ba);
}
/**********************************************
// IIC Write Data
**********************************************/
inline void OLED_Write_IIC_Data(unsigned char cmd)
{
    uint8_t data1[2];
    data1[0] = 0x40;
    data1[1] = cmd;
    auto ba = ByteArr(2, data1);
    OLED_iicWriteLen(SSD1306_I2C_ADDRESS, 1, &ba);
    // OLED_iicWriteLen(SSD1306_I2C_ADDRESS, 2, (unsigned char *)data1);
}
// void OLED_initSpiGpio();
// void OLED_setCS(char state);
// void OLED_setDC(char state);
// void OLED_setRST(char state);
#endif // __PA_OLED_DRV_H__