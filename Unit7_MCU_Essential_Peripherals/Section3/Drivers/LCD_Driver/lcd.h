/*
 * lcd.h
 *
 * Created: 11/5/2021 2:25:49 PM
 *  Author: Abdallah
 */


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 1000000UL

/* ========= Includes ======= */
#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"

/* ========= LCD Port Connections =========== */
#define LCD_CTRL_DATA_R     GPIO_PORTA  // LCD CTRL Ports connected to PORTA Pins

/* ======= CTRL SWitches ========== */
#define RS_SWITCH       GPIO_PIN_8
#define RW_SWITCH       GPIO_PIN_9
#define ENABLE_SWITCH   GPIO_PIN_10

/* ============= LCD Configurations Registers ================== */
#define LCD_FUNCTION_8BIT_2LINES               (0x38)  // Set 8-bit , 2 lines , 5 x 7 Dots
#define LCD_FUNCTION_4BIT_2LINES               (0x28)  // Set 4-bit , 2 lines , 5 x 7 Dots
#define LCD_MOVE_DISP_RIGHT                    (0x1C)  // Shift entire display right
#define LCD_MOVE_DISP_LEFT                     (0x18)  // Shift entire display left
#define LCD_MOVE_CURSOR_RIGHT                  (0x14)  // Move cursor right by one character
#define LCD_MOVE_CURSOR_LEFT                   (0x10)  // Move cursor left by one character
#define LCD_DISP_OFF                           (0x08)  // Display off Cursor off ( Clearing display without clearing DDRAM content )
#define LCD_DISP_ON_CURSOR                     (0x0E)  // Display on Cursor on
#define LCD_DISP_ON_CURSOR_BLINK               (0x0F)  // Display on Cursor blinking
#define LCD_DISP_ON_BLINK                      (0x0D)
#define LCD_DISP_ON                            (0x0C)
#define LCD_ENTRY_DEC                          (0x04)
#define LCD_ENTRY_DEC_SHIFT                    (0x05)
#define LCD_ENTRY_INC                          (0x06)
#define LCD_ENTRY_INC_SHIFT                    (0x07)
#define LCD_BEGIN_AT_FIRST_ROW                 (0x80)
#define LCD_BEGIN_AT_SECOND_ROW                (0xC0)
#define LCD_CLEAR_SCREEN                       (0x01)
#define LCD_ENTRY_MODE                         (0x06)

/* ============= Functions Prototypes ============ */
void LCD_init               (void);
void LCD_write_command      (unsigned char command);
void LCD_write_char         (unsigned char character);
void LCD_write_string       (char* string);
void LCD_is_busy            (void);
void LCD_kick               (void);
void LCD_clear_screen       (void);
void LCD_goTo_XY_Axis       (unsigned char line, unsigned char position);
//	void LCD_custom_characters  (void);

/* ============= Global Variable ================= */
GPIO_PinConfig_t PinCfg;

#endif /* LCD_H_ */
