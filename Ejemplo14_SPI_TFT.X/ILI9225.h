/* 
 * Driver for the ILI9225 intended for PIC18F26K42 but should be transferrable
 * to other models fairly easily.
 * 
 * Works with OTM2201A, and ILI9925 controller chips.
 * 
 * For more details see main description in C file.
 * 
 * File:   ILI9225.h
 * Author: tommy
 *
 * Created on 2 July 2019, 7:33 PM
 */

#ifndef ILI9225_H
#define	ILI9225_H

#ifdef	__cplusplus
extern "C" {
#endif

    //Hard-coded dimensions of the display
    #define WIDTH       220
    #define HEIGHT      176
    #define LANDSCAPE   1

    /* Font files. Thanks Stack Overflow!
     */

    const unsigned char FontLarge[95][13] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},// space :32
    {0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},// ! :33
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x36, 0x36, 0x36},
    {0x00, 0x00, 0x00, 0x66, 0x66, 0xff, 0x66, 0x66, 0xff, 0x66, 0x66, 0x00, 0x00},
    {0x00, 0x00, 0x18, 0x7e, 0xff, 0x1b, 0x1f, 0x7e, 0xf8, 0xd8, 0xff, 0x7e, 0x18},
    {0x00, 0x00, 0x0e, 0x1b, 0xdb, 0x6e, 0x30, 0x18, 0x0c, 0x76, 0xdb, 0xd8, 0x70},
    {0x00, 0x00, 0x7f, 0xc6, 0xcf, 0xd8, 0x70, 0x70, 0xd8, 0xcc, 0xcc, 0x6c, 0x38},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1c, 0x0c, 0x0e},
    {0x00, 0x00, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c},
    {0x00, 0x00, 0x30, 0x18, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x18, 0x30},
    {0x00, 0x00, 0x00, 0x00, 0x99, 0x5a, 0x3c, 0xff, 0x3c, 0x5a, 0x99, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18, 0x00, 0x00},
    {0x00, 0x00, 0x30, 0x18, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x06, 0x03, 0x03},
    {0x00, 0x00, 0x3c, 0x66, 0xc3, 0xe3, 0xf3, 0xdb, 0xcf, 0xc7, 0xc3, 0x66, 0x3c}, //0 : 48
    {0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x38, 0x18},
    {0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0xe7, 0x7e},
    {0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0x07, 0x03, 0x03, 0xe7, 0x7e},
    {0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0xff, 0xcc, 0x6c, 0x3c, 0x1c, 0x0c},
    {0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
    {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
    {0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x03, 0x03, 0xff},
    {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e},
    {0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x03, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e},
    {0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x30, 0x18, 0x1c, 0x1c, 0x00, 0x00, 0x1c, 0x1c, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06}, // < : 60
    {0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x60},
    {0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x18, 0x0c, 0x06, 0x03, 0xc3, 0xc3, 0x7e},
    {0x00, 0x00, 0x3f, 0x60, 0xcf, 0xdb, 0xd3, 0xdd, 0xc3, 0x7e, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18}, // A : 65
    {0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
    {0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
    {0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc},
    {0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
    {0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff},
    {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
    {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
    {0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e},
    {0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
    {0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3},
    {0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
    {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3},
    {0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3},
    {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},
    {0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
    {0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c},
    {0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
    {0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e},
    {0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff},
    {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
    {0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
    {0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
    {0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
    {0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
    {0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff}, // Z : 90
    {0x00, 0x00, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3c},
    {0x00, 0x03, 0x03, 0x06, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x30, 0x60, 0x60},
    {0x00, 0x00, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x3c},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18},
    {0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x38, 0x30, 0x70},
    {0x00, 0x00, 0x7f, 0xc3, 0xc3, 0x7f, 0x03, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00}, // a : 97
    {0x00, 0x00, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
    {0x00, 0x00, 0x7e, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0x7f, 0x03, 0x03, 0x03, 0x03, 0x03},
    {0x00, 0x00, 0x7f, 0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x33, 0x1e},
    {0x7e, 0xc3, 0x03, 0x03, 0x7f, 0xc3, 0xc3, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0},
    {0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x00}, // i
    {0x38, 0x6c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x0c, 0x00},
    {0x00, 0x00, 0xc6, 0xcc, 0xf8, 0xf0, 0xd8, 0xcc, 0xc6, 0xc0, 0xc0, 0xc0, 0xc0},
    {0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78},
    {0x00, 0x00, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xfe, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00}, // o : 111
    {0xc0, 0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0x00, 0x00, 0x00, 0x00},
    {0x03, 0x03, 0x03, 0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0x7f, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xfe, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xfe, 0x03, 0x03, 0x7e, 0xc0, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x1c, 0x36, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x00},
    {0x00, 0x00, 0x7e, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xc3, 0xe7, 0xff, 0xdb, 0xc3, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00},
    {0xc0, 0x60, 0x60, 0x30, 0x18, 0x3c, 0x66, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xff, 0x60, 0x30, 0x18, 0x0c, 0x06, 0xff, 0x00, 0x00, 0x00, 0x00}, // z : 122
    {0x00, 0x00, 0x0f, 0x18, 0x18, 0x18, 0x38, 0xf0, 0x38, 0x18, 0x18, 0x18, 0x0f},
    {0x40, 0x60, 0x70, 0x78, 0x7C, 0x7E, 0x7F, 0x7E, 0x7C, 0x78, 0x70, 0x60, 0x40}, //Special Characger 1
    {0x00, 0x18, 0x3C, 0x7E, 0xFF, 0x00, 0x00, 0x18, 0x3C, 0x7E, 0xFF, 0x00, 0x00}, //Special Character 2
    {0x00, 0x18, 0x3C, 0x7E, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x7E, 0x3C, 0x18, 0x00}}; //Special Character 3 :126

    /* ILI9225 LCD Registers */
    #define ILI9225_DRIVER_OUTPUT_CTRL      (0x01u)  // Driver Output Control
    #define ILI9225_LCD_AC_DRIVING_CTRL     (0x02u)  // LCD AC Driving Control
    #define ILI9225_ENTRY_MODE              (0x03u)  // Entry Mode
    #define ILI9225_DISP_CTRL1              (0x07u)  // Display Control 1
    #define ILI9225_BLANK_PERIOD_CTRL1      (0x08u)  // Blank Period Control
    #define ILI9225_FRAME_CYCLE_CTRL        (0x0Bu)  // Frame Cycle Control
    #define ILI9225_INTERFACE_CTRL          (0x0Cu)  // Interface Control
    #define ILI9225_OSC_CTRL                (0x0Fu)  // Osc Control
    #define ILI9225_POWER_CTRL1             (0x10u)  // Power Control 1
    #define ILI9225_POWER_CTRL2             (0x11u)  // Power Control 2
    #define ILI9225_POWER_CTRL3             (0x12u)  // Power Control 3
    #define ILI9225_POWER_CTRL4             (0x13u)  // Power Control 4
    #define ILI9225_POWER_CTRL5             (0x14u)  // Power Control 5
    #define ILI9225_VCI_RECYCLING           (0x15u)  // VCI Recycling
    #define ILI9225_RAM_ADDR_SET1           (0x20u)  // Horizontal GRAM Address Set
    #define ILI9225_RAM_ADDR_SET2           (0x21u)  // Vertical GRAM Address Set
    #define ILI9225_GRAM_DATA_REG           (0x22u)  // GRAM Data Register
    #define ILI9225_GATE_SCAN_CTRL          (0x30u)  // Gate Scan Control Register
    #define ILI9225_VERTICAL_SCROLL_CTRL1   (0x31u)  // Vertical Scroll Control 1 Register
    #define ILI9225_VERTICAL_SCROLL_CTRL2   (0x32u)  // Vertical Scroll Control 2 Register
    #define ILI9225_VERTICAL_SCROLL_CTRL3   (0x33u)  // Vertical Scroll Control 3 Register
    #define ILI9225_PARTIAL_DRIVING_POS1    (0x34u)  // Partial Driving Position 1 Register
    #define ILI9225_PARTIAL_DRIVING_POS2    (0x35u)  // Partial Driving Position 2 Register
    #define ILI9225_HORIZONTAL_WINDOW_ADDR1 (0x36u)  // Horizontal Address Start Position
    #define ILI9225_HORIZONTAL_WINDOW_ADDR2 (0x37u)  // Horizontal Address End Position
    #define ILI9225_VERTICAL_WINDOW_ADDR1   (0x38u)  // Vertical Address Start Position
    #define ILI9225_VERTICAL_WINDOW_ADDR2   (0x39u)  // Vertical Address End Position
    #define ILI9225_GAMMA_CTRL1             (0x50u)  // Gamma Control 1
    #define ILI9225_GAMMA_CTRL2             (0x51u)  // Gamma Control 2
    #define ILI9225_GAMMA_CTRL3             (0x52u)  // Gamma Control 3
    #define ILI9225_GAMMA_CTRL4             (0x53u)  // Gamma Control 4
    #define ILI9225_GAMMA_CTRL5             (0x54u)  // Gamma Control 5
    #define ILI9225_GAMMA_CTRL6             (0x55u)  // Gamma Control 6
    #define ILI9225_GAMMA_CTRL7             (0x56u)  // Gamma Control 7
    #define ILI9225_GAMMA_CTRL8             (0x57u)  // Gamma Control 8
    #define ILI9225_GAMMA_CTRL9             (0x58u)  // Gamma Control 9
    #define ILI9225_GAMMA_CTRL10            (0x59u)  // Gamma Control 10

    #define ILI9225C_INVOFF  0x20
    #define ILI9225C_INVON   0x21

    /* RGB 16-bit color table definition (RG565) */
    #define COLOR_BLACK          0x0000      /*   0,   0,   0 */
    #define COLOR_WHITE          0xFFFF      /* 255, 255, 255 */
    #define COLOR_BLUE           0x001F      /*   0,   0, 255 */
    #define COLOR_GREEN          0x07E0      /*   0, 255,   0 */
    #define COLOR_RED            0xF800      /* 255,   0,   0 */
    #define COLOR_NAVY           0x000F      /*   0,   0, 128 */
    #define COLOR_DARKBLUE       0x0011      /*   0,   0, 139 */
    #define COLOR_DARKGREEN      0x03E0      /*   0, 128,   0 */
    #define COLOR_DARKCYAN       0x03EF      /*   0, 128, 128 */
    #define COLOR_CYAN           0x07FF      /*   0, 255, 255 */
    #define COLOR_TURQUOISE      0x471A      /*  64, 224, 208 */
    #define COLOR_INDIGO         0x4810      /*  75,   0, 130 */
    #define COLOR_DARKRED        0x8000      /* 128,   0,   0 */
    #define COLOR_OLIVE          0x7BE0      /* 128, 128,   0 */
    #define COLOR_GRAY           0x8410      /* 128, 128, 128 */
    #define COLOR_GREY           0x8410      /* 128, 128, 128 */
    #define COLOR_SKYBLUE        0x867D      /* 135, 206, 235 */
    #define COLOR_BLUEVIOLET     0x895C      /* 138,  43, 226 */
    #define COLOR_LIGHTGREEN     0x9772      /* 144, 238, 144 */
    #define COLOR_DARKVIOLET     0x901A      /* 148,   0, 211 */
    #define COLOR_YELLOWGREEN    0x9E66      /* 154, 205,  50 */
    #define COLOR_BROWN          0xA145      /* 165,  42,  42 */
    #define COLOR_DARKGRAY       0x7BEF      /* 128, 128, 128 */
    #define COLOR_DARKGREY       0x7BEF      /* 128, 128, 128 */
    #define COLOR_SIENNA         0xA285      /* 160,  82,  45 */
    #define COLOR_LIGHTBLUE      0xAEDC      /* 172, 216, 230 */
    #define COLOR_GREENYELLOW    0xAFE5      /* 173, 255,  47 */
    #define COLOR_SILVER         0xC618      /* 192, 192, 192 */
    #define COLOR_LIGHTGRAY      0xC618      /* 192, 192, 192 */
    #define COLOR_LIGHTGREY      0xC618      /* 192, 192, 192 */
    #define COLOR_LIGHTCYAN      0xE7FF      /* 224, 255, 255 */
    #define COLOR_VIOLET         0xEC1D      /* 238, 130, 238 */
    #define COLOR_AZUR           0xF7FF      /* 240, 255, 255 */
    #define COLOR_BEIGE          0xF7BB      /* 245, 245, 220 */
    #define COLOR_MAGENTA        0xF81F      /* 255,   0, 255 */
    #define COLOR_TOMATO         0xFB08      /* 255,  99,  71 */
    #define COLOR_GOLD           0xFEA0      /* 255, 215,   0 */
    #define COLOR_ORANGE         0xFD20      /* 255, 165,   0 */
    #define COLOR_SNOW           0xFFDF      /* 255, 250, 250 */
    #define COLOR_YELLOW         0xFFE0      /* 255, 255,   0 */

    //Pin definitions (For PIC18F26K40) - change as required
    //NOTE: on older micros this will just be RC0, RC1, etc.
    //On newer chips we have to use the latch registers.
    #define CSX     LATD4 //Chip select
    #define RESX    LATA3 //Reset pin
    #define CMD     LATA4 //Command select
    //Software SPI pins if required
    #define SDO     LATC4
    #define SCK     LATC6

    //Use hardware SPI, will just big bang it through if false
    #define USE_HW_SPI  1
    
    //SPI Bus status register and transmission buffer
    //Set these to suit your particular microcontroller
    #define SPIBUF  SPI1TXB
    #define SPIIDLE PIR3bits.SPI1TXIF
    
    void spi_write(unsigned char data);
    void lcd_write_command(unsigned char data);
    void lcd_write_data(unsigned char data);
    void lcd_write_register(unsigned int reg, unsigned int data);
    void lcd_init(void);
    void swap_int(int *num1, int *num2);
    void swap_char(char *num1, char *num2);
    void delay_ms(double millis);
    void delay_us(long int cycles);
    void lcd_init_command_list(void);
    void draw_pixel(char x, char y, unsigned int colour);
    void set_draw_window(char row_start, char row_end, char col_start, char col_end);
    void fill_rectangle(char x1, char y1, char x2, char y2, unsigned int colour);
    void draw_char(char x, char y, char c, unsigned int colour, char size);
    void draw_fast_char(char x, char y, char c, unsigned int colour, unsigned int bg_colour);
    void draw_string(char x, char y, unsigned int colour, char size, char *str);
    void draw_fast_string(char x, char y, unsigned int colour, unsigned int bg_colour, char *str);
    void draw_line(char x1, char y1, char x2, char y2, unsigned int colour);
    void draw_bitmap(int x, int y, int scale, unsigned int *bmp);

#ifdef	__cplusplus
}
#endif

#endif	/* ILI9225_H */
