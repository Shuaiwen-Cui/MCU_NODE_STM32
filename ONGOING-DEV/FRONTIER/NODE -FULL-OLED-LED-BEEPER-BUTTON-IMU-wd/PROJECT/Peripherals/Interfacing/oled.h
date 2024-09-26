/**
 * @file oled.c
 * @brief 波特律动OLED驱动(CH1116)
 * @anchor 波特律动(keysking 博哥在学习)
 * @version 1.0
 * @date 2023-08-04
 * @license MIT License
 *
 * @attention
 * 本驱动库针对波特律动·keysking的STM32教程学习套件进行开发
 * 在其他平台或驱动芯片上使用可能需要进行移植
 *
 * @note
 * 使用流程:
 * 1. STM32初始化IIC完成后调用OLED_Init()初始化OLED. 注意STM32启动比OLED上电快, 可等待20ms再初始化OLED
 * 2. 调用OLED_NewFrame()开始绘制新的一帧
 * 3. 调用OLED_DrawXXX()系列函数绘制图形到显存 调用OLED_Printxxx()系列函数绘制文本到显存
 * 4. 调用OLED_ShowFrame()将显存内容显示到OLED
 *
 * @note
 * 为保证中文显示正常 请将编译器的字符集设置为UTF-8
 *
 */
/**
 * @file oled.c
 * @brief BaudDance OLED Driver (CH1116)
 * @anchor BaudDance (keysking learning)
 * @version 1.0
 * @date 2023-08-04
 * @license MIT License
 *
 * @attention
 * This driver library is developed for the BoteLvdong · keysking STM32 tutorial kit.
 * Porting may be required for other platforms or driver chips.
 *
 * @note
 * Usage Flow:
 * 1. After initializing IIC on STM32, call OLED_Init() to initialize the OLED. Note that STM32 boots faster than OLED power-on; wait for 20ms before initializing OLED.
 * 2. Call OLED_NewFrame() to start drawing a new frame.
 * 3. Call OLED_DrawXXX() series functions to draw graphics to the framebuffer and OLED_PrintXXX() series functions to draw text to the framebuffer.
 * 4. Call OLED_ShowFrame() to display the framebuffer content on the OLED.
 *
 * @note
 * To ensure proper Chinese display, set the compiler's character set to UTF-8.
 *
 */
#ifndef _OLED_H_
#define _OLED_H_

#include "font.h"
#include "main.h"
#include "string.h"

typedef enum
{
  OLED_COLOR_NORMAL = 0, // 正常模式 黑底白字 normal mode black background white font
  OLED_COLOR_REVERSED    // 反色模式 白底黑字 reversed mode white background black font
} OLED_ColorMode;

void OLED_Init();
void OLED_DisPlay_On();
void OLED_DisPlay_Off();

void OLED_NewFrame();
void OLED_ShowFrame();
void OLED_SetPixel(uint8_t x, uint8_t y, OLED_ColorMode color);

void OLED_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_ColorMode color);
void OLED_DrawRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, OLED_ColorMode color);
void OLED_DrawFilledRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, OLED_ColorMode color);
void OLED_DrawTriangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, OLED_ColorMode color);
void OLED_DrawFilledTriangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, OLED_ColorMode color);
void OLED_DrawCircle(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);
void OLED_DrawFilledCircle(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);
void OLED_DrawEllipse(uint8_t x, uint8_t y, uint8_t a, uint8_t b, OLED_ColorMode color);
void OLED_DrawImage(uint8_t x, uint8_t y, const Image *img, OLED_ColorMode color);

void OLED_PrintASCIIChar(uint8_t x, uint8_t y, char ch, const ASCIIFont *font, OLED_ColorMode color);
void OLED_PrintASCIIString(uint8_t x, uint8_t y, char *str, const ASCIIFont *font, OLED_ColorMode color);
void OLED_PrintString(uint8_t x, uint8_t y, char *str, const Font *font, OLED_ColorMode color);

#endif // _OLED_H_