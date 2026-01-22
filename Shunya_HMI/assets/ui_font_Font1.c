/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:/Users/Sidd/SquareLine/assets/AovelSansRounded-rdDL.ttf -o C:/Users/Sidd/SquareLine/assets\ui_font_Font1.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xb0,

    /* U+0022 "\"" */
    0xb6, 0xd0,

    /* U+0023 "#" */
    0x12, 0x12, 0x12, 0x16, 0x7f, 0x34, 0x24, 0xff,
    0x24, 0x24, 0x2c, 0x2c,

    /* U+0024 "$" */
    0x3e, 0x6b, 0x89, 0x89, 0xc8, 0x78, 0xe, 0x89,
    0x89, 0x89, 0x6b, 0x3e, 0x8, 0x8,

    /* U+0025 "%" */
    0x70, 0xa2, 0x48, 0xb2, 0x28, 0x8e, 0x1d, 0x0,
    0xb8, 0x71, 0x14, 0x49, 0x16, 0x45, 0xe,

    /* U+0026 "&" */
    0x38, 0x44, 0x44, 0x6c, 0x38, 0x30, 0x78, 0xca,
    0x86, 0x86, 0xc6, 0x79,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x69, 0x69, 0x24, 0x92, 0x64, 0x88,

    /* U+0029 ")" */
    0xc9, 0x32, 0x49, 0x24, 0xb4, 0xb0,

    /* U+002A "*" */
    0x25, 0x7e, 0xe5, 0x0,

    /* U+002B "+" */
    0x10, 0x20, 0x40, 0x8f, 0xe2, 0x4, 0x8, 0x10,

    /* U+002C "," */
    0xf8,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x8, 0x46, 0x21, 0x10, 0x88, 0x46, 0x21, 0x0,

    /* U+0030 "0" */
    0x3c, 0x42, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x42, 0x66, 0x3c,

    /* U+0031 "1" */
    0x17, 0xd1, 0x11, 0x11, 0x11, 0x10,

    /* U+0032 "2" */
    0x38, 0x8e, 0xc, 0x18, 0x20, 0x83, 0xc, 0x60,
    0x82, 0x7, 0xf0,

    /* U+0033 "3" */
    0x3c, 0x43, 0x81, 0x81, 0x3, 0xe, 0x3, 0x81,
    0x81, 0x81, 0x42, 0x3c,

    /* U+0034 "4" */
    0x4, 0xc, 0x1c, 0x14, 0x24, 0x64, 0xc4, 0xff,
    0x4, 0x4, 0x4,

    /* U+0035 "5" */
    0x7f, 0x40, 0x40, 0x7c, 0xc2, 0x81, 0x1, 0x81,
    0x81, 0x42, 0x3c,

    /* U+0036 "6" */
    0x3c, 0x62, 0x43, 0x81, 0xbc, 0xc2, 0x81, 0x81,
    0x81, 0x81, 0x42, 0x3c,

    /* U+0037 "7" */
    0xfe, 0xc, 0x30, 0x41, 0x82, 0x4, 0x10, 0x20,
    0x40, 0x80,

    /* U+0038 "8" */
    0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x42, 0x81,
    0x81, 0x81, 0x42, 0x3c,

    /* U+0039 "9" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,
    0x81, 0xc2, 0x46, 0x3c,

    /* U+003A ":" */
    0xc1, 0x80,

    /* U+003B ";" */
    0xc3, 0xc0,

    /* U+003C "<" */
    0x1, 0x83, 0x87, 0xe, 0xc, 0x3, 0x80, 0x70,
    0xe, 0x1, 0x80,

    /* U+003D "=" */
    0xff, 0x80, 0x0, 0x1f, 0xf0,

    /* U+003E ">" */
    0xc0, 0x38, 0x7, 0x0, 0xe0, 0x18, 0x38, 0x70,
    0xe0, 0xc0, 0x0,

    /* U+003F "?" */
    0x3c, 0x8e, 0xc, 0x18, 0x61, 0x82, 0x8, 0x10,
    0x20, 0x40, 0x80,

    /* U+0040 "@" */
    0x1f, 0x6, 0x19, 0x3d, 0x6c, 0xd9, 0x1b, 0x42,
    0x68, 0xcd, 0x1b, 0xa6, 0x4b, 0xfc, 0xc3, 0xf,
    0x80,

    /* U+0041 "A" */
    0x8, 0xe, 0x5, 0x2, 0x82, 0x61, 0x11, 0x88,
    0xfe, 0x41, 0x60, 0xe0, 0x30, 0x10,

    /* U+0042 "B" */
    0xfe, 0x41, 0xa0, 0x50, 0x28, 0x37, 0xf2, 0x5,
    0x1, 0x80, 0xc0, 0x60, 0x5f, 0xc0,

    /* U+0043 "C" */
    0x1f, 0x8, 0x64, 0xf, 0x1, 0x80, 0x20, 0x8,
    0x2, 0x1, 0x80, 0x50, 0x26, 0x18, 0x78,

    /* U+0044 "D" */
    0xfc, 0x41, 0xa0, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xc0, 0xa0, 0x9f, 0x80,

    /* U+0045 "E" */
    0xff, 0x80, 0x80, 0x80, 0x80, 0xfe, 0x80, 0x80,
    0x80, 0x80, 0x80, 0xff,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xe0, 0x40, 0x81,
    0x2, 0x4, 0x0,

    /* U+0047 "G" */
    0x1f, 0x18, 0x64, 0xe, 0x1, 0x80, 0x20, 0x8,
    0x7e, 0x1, 0x80, 0x50, 0x22, 0x18, 0x7c,

    /* U+0048 "H" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xf, 0xfe, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x30, 0x10,

    /* U+0049 "I" */
    0xff, 0xf0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x41, 0x86, 0x1c,
    0xde,

    /* U+004B "K" */
    0x81, 0xc1, 0xa1, 0x91, 0x89, 0x85, 0x83, 0x61,
    0x10, 0x8c, 0x43, 0x20, 0xd0, 0x30,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x2, 0x7, 0xf0,

    /* U+004D "M" */
    0x80, 0x38, 0xf, 0x1, 0xf0, 0x7a, 0xb, 0x43,
    0x64, 0x4c, 0x89, 0x9b, 0x31, 0x46, 0x38, 0xc2,
    0x10,

    /* U+004E "N" */
    0x80, 0xe0, 0x78, 0x36, 0x19, 0xc, 0xc6, 0x33,
    0x9, 0x86, 0xc1, 0xe0, 0x70, 0x10,

    /* U+004F "O" */
    0x1e, 0x18, 0x64, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x50, 0x22, 0x10, 0x78,

    /* U+0050 "P" */
    0xfe, 0x83, 0x81, 0x81, 0x81, 0x82, 0xfc, 0x80,
    0x80, 0x80, 0x80, 0x80,

    /* U+0051 "Q" */
    0x1f, 0x4, 0x11, 0x1, 0x40, 0x38, 0x3, 0x0,
    0x60, 0xc, 0x1, 0xc0, 0x68, 0x8, 0x83, 0xf,
    0x90,

    /* U+0052 "R" */
    0xfe, 0x41, 0xa0, 0x50, 0x28, 0x14, 0x1b, 0xf9,
    0x2, 0x81, 0x40, 0xa0, 0x50, 0x30,

    /* U+0053 "S" */
    0x3e, 0x20, 0xa0, 0x30, 0x1c, 0x3, 0xe0, 0x3d,
    0x3, 0x80, 0xc0, 0x50, 0x47, 0xc0,

    /* U+0054 "T" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0,

    /* U+0055 "U" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x42, 0x3c,

    /* U+0056 "V" */
    0xc0, 0x50, 0x24, 0x8, 0x86, 0x21, 0xc, 0x41,
    0x30, 0x48, 0x1a, 0x3, 0x80, 0xc0, 0x10,

    /* U+0057 "W" */
    0x82, 0xe, 0xc, 0x28, 0x70, 0x91, 0x42, 0x45,
    0x99, 0x12, 0x46, 0xc9, 0xa, 0x24, 0x28, 0xf0,
    0xe1, 0x83, 0x6, 0x4, 0x18,

    /* U+0058 "X" */
    0x40, 0xd8, 0x62, 0x10, 0x48, 0x1e, 0x3, 0x0,
    0xc0, 0x78, 0x33, 0x8, 0x44, 0xb, 0x3,

    /* U+0059 "Y" */
    0x80, 0xe0, 0xd0, 0x44, 0x43, 0x60, 0xa0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0,

    /* U+005A "Z" */
    0xff, 0x80, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x60,
    0x60, 0x20, 0x30, 0x30, 0x1f, 0xf0,

    /* U+005B "[" */
    0xea, 0xaa, 0xaa, 0xac,

    /* U+005C "\\" */
    0x81, 0x4, 0x18, 0x20, 0xc1, 0x4, 0x8, 0x20,
    0xc1,

    /* U+005D "]" */
    0xd5, 0x55, 0x55, 0x5c,

    /* U+005E "^" */
    0x10, 0x70, 0xa3, 0x64, 0x48, 0xe0, 0xc1,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0xc8, 0x80,

    /* U+0061 "a" */
    0x3c, 0x62, 0x42, 0x42, 0x3e, 0x42, 0xc2, 0x46,
    0x3f,

    /* U+0062 "b" */
    0x81, 0x2, 0x7, 0xcc, 0x50, 0x60, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0063 "c" */
    0x3c, 0x8a, 0xc, 0x8, 0x10, 0x60, 0xa2, 0x3c,

    /* U+0064 "d" */
    0x2, 0x4, 0x9, 0xf4, 0x70, 0x60, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0065 "e" */
    0x38, 0x8b, 0xc, 0x1f, 0xf0, 0x60, 0xa3, 0x3c,

    /* U+0066 "f" */
    0xf2, 0x4f, 0x24, 0x92, 0x40,

    /* U+0067 "g" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xa3, 0x3a,
    0x4, 0x19, 0xe0,

    /* U+0068 "h" */
    0x82, 0x8, 0x3e, 0xce, 0x18, 0x61, 0x86, 0x18,
    0x61,

    /* U+0069 "i" */
    0xdf, 0xf0,

    /* U+006A "j" */
    0x24, 0x12, 0x49, 0x24, 0x92, 0x78,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x38, 0xd3, 0x28, 0x78, 0x91,
    0x12, 0x14, 0x10,

    /* U+006C "l" */
    0xff, 0xf0,

    /* U+006D "m" */
    0xfb, 0xd8, 0xc6, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xc, 0x21, 0x84, 0x20,

    /* U+006E "n" */
    0xfb, 0x38, 0x61, 0x86, 0x18, 0x61, 0x84,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x38,

    /* U+0070 "p" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xe2, 0xf9,
    0x2, 0x4, 0x0,

    /* U+0071 "q" */
    0x3a, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xa3, 0x3e,
    0x4, 0x8, 0x10,

    /* U+0072 "r" */
    0xfc, 0x88, 0x88, 0x88, 0x80,

    /* U+0073 "s" */
    0x7b, 0x18, 0x78, 0x7a, 0x38, 0x71, 0x78,

    /* U+0074 "t" */
    0x4, 0x4f, 0x44, 0x44, 0x44, 0x47,

    /* U+0075 "u" */
    0x85, 0xa, 0x14, 0x28, 0x50, 0xa1, 0x66, 0x7e,

    /* U+0076 "v" */
    0x87, 0xb, 0x12, 0x64, 0x8d, 0xe, 0x18, 0x10,

    /* U+0077 "w" */
    0x84, 0x31, 0x8d, 0x29, 0x25, 0x24, 0xa4, 0xe7,
    0xc, 0x61, 0x8c, 0x31, 0x80,

    /* U+0078 "x" */
    0x85, 0x99, 0xa1, 0x83, 0x7, 0x12, 0x62, 0x86,

    /* U+0079 "y" */
    0x87, 0xb, 0x12, 0x64, 0x8d, 0xe, 0x18, 0x30,
    0x60, 0x87, 0x0,

    /* U+007A "z" */
    0x7e, 0x8, 0x20, 0xc3, 0x4, 0x18, 0x60, 0xfe,

    /* U+007B "{" */
    0x69, 0x24, 0x94, 0x49, 0x24, 0x98,

    /* U+007C "|" */
    0xff, 0xff, 0x80,

    /* U+007D "}" */
    0xc9, 0x24, 0x91, 0x49, 0x24, 0xb0,

    /* U+007E "~" */
    0x73, 0x18
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 71, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 47, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 71, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 5, .adv_w = 142, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 142, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 31, .adv_w = 175, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 147, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 43, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 59, .adv_w = 57, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 65, .adv_w = 57, .box_w = 3, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 71, .adv_w = 90, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 75, .adv_w = 154, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 71, .box_w = 1, .box_h = 5, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 84, .adv_w = 85, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 85, .adv_w = 71, .box_w = 1, .box_h = 2, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 85, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 142, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 142, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 142, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 142, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 142, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 142, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 142, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 142, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 71, .box_w = 1, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 71, .box_w = 1, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 207, .adv_w = 154, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 154, .box_w = 9, .box_h = 4, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 223, .adv_w = 154, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 205, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 147, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 156, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 175, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 166, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 319, .adv_w = 138, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 123, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 185, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 166, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 33, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 119, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 152, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 123, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 407, .adv_w = 200, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 166, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 438, .adv_w = 185, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 147, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 465, .adv_w = 185, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 156, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 156, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 128, .box_w = 9, .box_h = 12, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 162, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 138, .box_w = 10, .box_h = 12, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 223, .box_w = 14, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 133, .box_w = 10, .box_h = 12, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 587, .adv_w = 138, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 128, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 57, .box_w = 2, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 619, .adv_w = 85, .box_w = 6, .box_h = 12, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 628, .adv_w = 57, .box_w = 2, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 632, .adv_w = 154, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 639, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 640, .adv_w = 33, .box_w = 3, .box_h = 3, .ofs_x = -1, .ofs_y = 9},
    {.bitmap_index = 642, .adv_w = 123, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 662, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 670, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 681, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 689, .adv_w = 52, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 133, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 705, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 33, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 716, .adv_w = 33, .box_w = 3, .box_h = 15, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 722, .adv_w = 114, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 733, .adv_w = 33, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 735, .adv_w = 199, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 755, .adv_w = 133, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 763, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 774, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 785, .adv_w = 66, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 790, .adv_w = 119, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 797, .adv_w = 62, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 811, .adv_w = 104, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 819, .adv_w = 175, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 832, .adv_w = 104, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 104, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 851, .adv_w = 104, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 859, .adv_w = 85, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 865, .adv_w = 57, .box_w = 1, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 868, .adv_w = 85, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 874, .adv_w = 154, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    34, 53,
    34, 55,
    34, 56,
    34, 58,
    34, 87,
    34, 88,
    34, 90,
    39, 13,
    39, 15,
    39, 34,
    45, 53,
    45, 55,
    45, 56,
    45, 58,
    45, 90,
    49, 13,
    49, 15,
    49, 34,
    53, 13,
    53, 15,
    53, 27,
    53, 28,
    53, 34,
    53, 68,
    53, 70,
    53, 74,
    53, 80,
    53, 83,
    53, 84,
    53, 86,
    53, 88,
    53, 90,
    55, 13,
    55, 15,
    55, 27,
    55, 28,
    55, 34,
    55, 70,
    55, 80,
    55, 83,
    55, 86,
    56, 13,
    56, 15,
    56, 27,
    56, 28,
    56, 34,
    56, 70,
    56, 80,
    58, 13,
    58, 15,
    58, 27,
    58, 28,
    58, 34,
    58, 70,
    58, 80,
    58, 81,
    58, 82,
    58, 86,
    58, 87,
    83, 13,
    83, 15,
    83, 87,
    83, 90,
    87, 13,
    87, 15,
    88, 13,
    88, 15,
    90, 13,
    90, 15
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -19, -14, -5, -9, -10, -5, -10, -23,
    -23, -9, -23, -23, -19, -28, -14, -26,
    -26, -14, -28, -28, -28, -28, -19, -23,
    -23, -6, -23, -23, -23, -23, -23, -23,
    -23, -23, -9, -9, -14, -9, -9, -5,
    -5, -14, -14, -5, -5, -5, -5, -5,
    -23, -23, -14, -14, -14, -19, -19, -14,
    -19, -9, -5, -14, -14, 5, 5, -19,
    -19, -14, -14, -19, -19
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 69,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT1*/

