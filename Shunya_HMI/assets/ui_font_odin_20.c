/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font C:/Users/Sidd/SquareLine/assets/OdinRounded-Yd82.ttf -o C:/Users/Sidd/SquareLine/assets\ui_font_odin_20.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_ODIN_20
#define UI_FONT_ODIN_20 1
#endif

#if UI_FONT_ODIN_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xf0, 0xf0,

    /* U+0022 "\"" */
    0x4f, 0x3d, 0x80,

    /* U+0023 "#" */
    0x8, 0x41, 0x8e, 0x18, 0xe1, 0x8c, 0xff, 0xff,
    0xff, 0x38, 0xc3, 0xc, 0x31, 0xcf, 0xff, 0xff,
    0xf3, 0x18, 0x71, 0x86, 0x18,

    /* U+0024 "$" */
    0x1e, 0x1f, 0x9e, 0x8d, 0x6, 0x81, 0xc0, 0xf8,
    0x1e, 0xb, 0xe4, 0xf2, 0x7d, 0x77, 0xf1, 0xf0,

    /* U+0025 "%" */
    0x38, 0x8, 0x7c, 0x18, 0xc6, 0x38, 0xc6, 0x70,
    0xc6, 0x60, 0x7c, 0xc0, 0x39, 0xc0, 0x3, 0x9c,
    0x3, 0x3e, 0x6, 0x63, 0xe, 0x63, 0x1c, 0x63,
    0x18, 0x3e, 0x10, 0x1c,

    /* U+0026 "&" */
    0xe, 0x3, 0xe0, 0xc6, 0x18, 0xc3, 0x18, 0x77,
    0xf, 0xc3, 0xf0, 0xee, 0x78, 0xff, 0xe, 0x71,
    0xe7, 0xec, 0x78, 0x80,

    /* U+0027 "'" */
    0x5b, 0x0,

    /* U+0028 "(" */
    0x37, 0x66, 0xcc, 0xcc, 0xcc, 0x66, 0x73,

    /* U+0029 ")" */
    0xce, 0x66, 0x33, 0x33, 0x33, 0x66, 0xec,

    /* U+002A "*" */
    0xdf, 0xff, 0xb0,

    /* U+002B "+" */
    0xc, 0x6, 0x3, 0x1, 0x8f, 0xff, 0xfc, 0x30,
    0x18, 0xc, 0x0,

    /* U+002C "," */
    0xf, 0x60,

    /* U+002D "-" */
    0xff, 0xff, 0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x13, 0x33, 0x36, 0x66, 0x66, 0xcc, 0xcc,

    /* U+0030 "0" */
    0x1c, 0x3f, 0x98, 0xd8, 0x7c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x67, 0xf0, 0xe0,

    /* U+0031 "1" */
    0xfd, 0xb6, 0xdb, 0x6d, 0xb6, 0xc0,

    /* U+0032 "2" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0x7, 0xe, 0x1c,
    0x38, 0x70, 0xe0, 0xc0, 0xff, 0xff,

    /* U+0033 "3" */
    0x7c, 0x3f, 0x0, 0xc0, 0x60, 0x70, 0x70, 0x3c,
    0x7, 0x1, 0xe0, 0xf0, 0x7c, 0x77, 0xf0, 0xf0,

    /* U+0034 "4" */
    0x6, 0x7, 0x7, 0x83, 0xc3, 0xe1, 0xb1, 0xd8,
    0xcc, 0xe6, 0x7f, 0xff, 0xe0, 0xc0, 0x60, 0x30,

    /* U+0035 "5" */
    0x3e, 0x1f, 0xc, 0x4, 0x6, 0x3, 0xf1, 0xfc,
    0x7, 0x1, 0xe0, 0xf0, 0x7c, 0x77, 0xf1, 0xf0,

    /* U+0036 "6" */
    0xc, 0x6, 0x6, 0x7, 0x3, 0x3, 0xf1, 0xfd,
    0xc7, 0xc1, 0xe0, 0xf0, 0x7c, 0x77, 0xf0, 0xf0,

    /* U+0037 "7" */
    0xff, 0xff, 0x6, 0x6, 0xc, 0xc, 0x18, 0x18,
    0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0,

    /* U+0038 "8" */
    0x1c, 0x1f, 0x18, 0xcc, 0x66, 0x31, 0xf1, 0xfc,
    0xc7, 0xc1, 0xe0, 0xf0, 0x7c, 0x77, 0xf1, 0xf0,

    /* U+0039 "9" */
    0x3e, 0x3f, 0xb8, 0xd8, 0x3c, 0x1e, 0xf, 0x8e,
    0xfe, 0x3f, 0x3, 0x3, 0x81, 0x81, 0x80, 0xc0,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0xd8, 0x0, 0x1e, 0xc0,

    /* U+003C "<" */
    0x6, 0x1c, 0x73, 0x8e, 0x1c, 0x1e, 0xe, 0xe,
    0xc,

    /* U+003D "=" */
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xfc,

    /* U+003E ">" */
    0xc1, 0xc1, 0xc1, 0xc0, 0xe1, 0xcf, 0x38, 0xe1,
    0x80,

    /* U+003F "?" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0x3, 0xe, 0x1c,
    0x18, 0x18, 0x0, 0x0, 0x18, 0x18,

    /* U+0040 "@" */
    0xf, 0xc0, 0x7f, 0x83, 0x87, 0x19, 0xfe, 0xef,
    0xdb, 0x77, 0x3d, 0x8c, 0xf6, 0x33, 0xdd, 0xcf,
    0xbf, 0x36, 0x7d, 0x8e, 0x1c, 0x1f, 0x80, 0x3e,
    0x0,

    /* U+0041 "A" */
    0x6, 0x0, 0xe0, 0xe, 0x0, 0xf0, 0x1b, 0x1,
    0xb8, 0x39, 0x83, 0x18, 0x30, 0xc7, 0xfc, 0x7f,
    0xee, 0x6, 0xc0, 0x6c, 0x2,

    /* U+0042 "B" */
    0xfc, 0x7f, 0x30, 0xd8, 0x6c, 0x36, 0x3b, 0xfd,
    0xff, 0xc3, 0xe0, 0xf0, 0x78, 0x7f, 0xf7, 0xf0,

    /* U+0043 "C" */
    0xf, 0xc3, 0xfc, 0xe1, 0x30, 0xe, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x1c, 0x1, 0x80, 0x1c,
    0x21, 0xfe, 0x1f, 0x80,

    /* U+0044 "D" */
    0xfe, 0x3f, 0xcc, 0x3b, 0x6, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0x1b, 0xe, 0xff,
    0x3f, 0x80,

    /* U+0045 "E" */
    0xff, 0x7f, 0xb0, 0x18, 0xc, 0x6, 0x3, 0xf9,
    0xfc, 0xc0, 0x60, 0x30, 0x18, 0xf, 0xf7, 0xf8,

    /* U+0046 "F" */
    0xff, 0xff, 0xf0, 0x18, 0xc, 0x6, 0x3, 0xfd,
    0xfe, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0,

    /* U+0047 "G" */
    0xf, 0xc1, 0xfe, 0x38, 0x76, 0x1, 0xe0, 0xc,
    0x0, 0xc3, 0xfc, 0x3f, 0xc0, 0x3e, 0x3, 0x60,
    0x33, 0x87, 0x1f, 0xe0, 0xf8,

    /* U+0048 "H" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3f,
    0xff, 0xff, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xf0, 0x30,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+004A "J" */
    0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x7f,
    0x70,

    /* U+004B "K" */
    0xc1, 0xe1, 0xf1, 0xd8, 0xcc, 0xc6, 0xc3, 0xe1,
    0xf0, 0xd8, 0x66, 0x31, 0x98, 0xec, 0x3e, 0xc,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0x6, 0xf, 0xff, 0xc0,

    /* U+004D "M" */
    0xc0, 0x1f, 0x1, 0xf8, 0xf, 0xe0, 0xff, 0x8f,
    0xee, 0xef, 0x36, 0x78, 0xe3, 0xc7, 0x1e, 0x0,
    0xf0, 0x7, 0x80, 0x3c, 0x1, 0xe0, 0xc,

    /* U+004E "N" */
    0xc0, 0xf0, 0x3e, 0xf, 0xc3, 0xf0, 0xf6, 0x3c,
    0xcf, 0x33, 0xc6, 0xf0, 0xfc, 0x3f, 0x7, 0xc0,
    0xf0, 0x30,

    /* U+004F "O" */
    0xf, 0x81, 0xff, 0xe, 0x38, 0xc0, 0x6e, 0x3,
    0xe0, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1f, 0x1,
    0xd8, 0xc, 0x71, 0xe3, 0xfe, 0x7, 0xc0,

    /* U+0050 "P" */
    0xfe, 0x7f, 0xb0, 0xf8, 0x3c, 0x1e, 0xf, 0xf,
    0xfe, 0xfe, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0,

    /* U+0051 "Q" */
    0xf, 0x81, 0xff, 0xe, 0x38, 0xc0, 0x6e, 0x3,
    0xe0, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x9f, 0x7,
    0xd8, 0x3c, 0x71, 0xc3, 0xff, 0x7, 0xc8,

    /* U+0052 "R" */
    0xfe, 0x7f, 0xb0, 0xf8, 0x3c, 0x1e, 0xf, 0xf,
    0xfe, 0xfe, 0x63, 0x31, 0xd8, 0x6c, 0x1e, 0xc,

    /* U+0053 "S" */
    0x1e, 0x1f, 0x9c, 0xc, 0x6, 0x1, 0xc0, 0xf8,
    0xe, 0x3, 0x80, 0xd0, 0x7c, 0x77, 0xf1, 0xe0,

    /* U+0054 "T" */
    0xff, 0xff, 0xc3, 0x1, 0x80, 0xc0, 0x60, 0x30,
    0x18, 0xc, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60,

    /* U+0055 "U" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xd, 0x86, 0x7f,
    0x87, 0x80,

    /* U+0056 "V" */
    0xc0, 0x2c, 0x6, 0xe0, 0x66, 0xe, 0x60, 0xc3,
    0xc, 0x31, 0x83, 0x98, 0x1b, 0x81, 0xb0, 0xf,
    0x0, 0xe0, 0xe, 0x0, 0x60,

    /* U+0057 "W" */
    0xc6, 0x31, 0xe3, 0x98, 0xf8, 0xd8, 0x6c, 0x6c,
    0x66, 0x1e, 0x31, 0x8e, 0x38, 0xc7, 0x18, 0x33,
    0x8c, 0x19, 0xcc, 0xf, 0xb6, 0x3, 0xde, 0x1,
    0xe7, 0x0, 0x63, 0x80, 0x31, 0x80,

    /* U+0058 "X" */
    0xc0, 0xf0, 0x36, 0x19, 0xce, 0x37, 0x7, 0x81,
    0xe0, 0x78, 0x1e, 0xd, 0xc7, 0x39, 0x86, 0xc0,
    0xf0, 0x30,

    /* U+0059 "Y" */
    0xc0, 0xf0, 0x36, 0x19, 0xce, 0x37, 0x7, 0x81,
    0xe0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xc0, 0xc0, 0xe0, 0x60, 0x70, 0x30,
    0x30, 0x38, 0x18, 0x1c, 0xc, 0xf, 0xff, 0xfc,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xff,

    /* U+005C "\\" */
    0xcc, 0xcc, 0x66, 0x66, 0x63, 0x33, 0x31,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0xff,

    /* U+005E "^" */
    0x10, 0x71, 0xf7, 0x7c, 0x60,

    /* U+005F "_" */
    0xff, 0xff, 0xf0,

    /* U+0060 "`" */
    0xcf, 0x30,

    /* U+0061 "a" */
    0x3c, 0x7e, 0x43, 0x3f, 0xff, 0xc3, 0xc7, 0xff,
    0x7f,

    /* U+0062 "b" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x7, 0xf3, 0xfd,
    0xc7, 0xc1, 0xe0, 0xf0, 0x7c, 0x7f, 0xf7, 0xf0,

    /* U+0063 "c" */
    0x3c, 0xfb, 0x86, 0xc, 0x18, 0x38, 0x3f, 0x3c,

    /* U+0064 "d" */
    0x1, 0x80, 0xc0, 0x60, 0x30, 0x19, 0xed, 0xff,
    0xc7, 0xc1, 0xe0, 0xf0, 0x7c, 0x77, 0xf9, 0xec,

    /* U+0065 "e" */
    0x3c, 0x7e, 0xe7, 0xff, 0xff, 0xc0, 0xe2, 0x7e,
    0x3c,

    /* U+0066 "f" */
    0x1c, 0x73, 0xc, 0x33, 0xff, 0xcc, 0x30, 0xc3,
    0xc, 0x30, 0xc0,

    /* U+0067 "g" */
    0x3f, 0xbf, 0xf8, 0xf8, 0x3c, 0x1e, 0xf, 0x8e,
    0xff, 0x1f, 0x80, 0xd0, 0x6c, 0x67, 0xf0, 0xe0,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xfe, 0xc7,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0xf0, 0x3f, 0xff, 0xf0,

    /* U+006A "j" */
    0x18, 0xc0, 0x0, 0xc, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x73, 0x0,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x73, 0xee, 0xf9,
    0xe3, 0xe6, 0xec, 0xf8, 0x40,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+006D "m" */
    0xff, 0xbf, 0xfc, 0xcf, 0x33, 0xcc, 0xf3, 0x3c,
    0xcf, 0x33, 0xcc, 0xc0,

    /* U+006E "n" */
    0xc3, 0xe3, 0xf3, 0xf3, 0xdb, 0xcf, 0xcf, 0xc7,
    0xc3,

    /* U+006F "o" */
    0x3e, 0x3f, 0xb8, 0xf8, 0x3c, 0x1e, 0xf, 0x8e,
    0xfe, 0x3e, 0x0,

    /* U+0070 "p" */
    0xde, 0x7f, 0xb8, 0xf8, 0x3c, 0x1e, 0xf, 0x8f,
    0xfe, 0xde, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0,

    /* U+0071 "q" */
    0x3d, 0xbf, 0xf8, 0xf8, 0x3c, 0x1e, 0xf, 0x8e,
    0xff, 0x3d, 0x80, 0xc0, 0x60, 0x30, 0x18, 0xc,

    /* U+0072 "r" */
    0xff, 0xcc, 0xcc, 0xcc, 0xc0,

    /* U+0073 "s" */
    0x79, 0xfb, 0x7, 0x87, 0xc1, 0xb3, 0x7e, 0x78,

    /* U+0074 "t" */
    0x30, 0x60, 0xc1, 0x83, 0x1f, 0xff, 0x98, 0x30,
    0x60, 0xc1, 0x83, 0x6, 0x0,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xbe, 0x38,

    /* U+0076 "v" */
    0xc1, 0xe1, 0xd8, 0xcc, 0x63, 0x61, 0xb0, 0x70,
    0x38, 0x8, 0x0,

    /* U+0077 "w" */
    0xc6, 0x3c, 0x63, 0xef, 0x76, 0xf6, 0x6f, 0x67,
    0x9e, 0x39, 0xc3, 0x9c, 0x10, 0x80,

    /* U+0078 "x" */
    0x87, 0x9f, 0xb3, 0xc3, 0x8f, 0x3b, 0x67, 0x86,

    /* U+0079 "y" */
    0xc1, 0xe0, 0xd8, 0xcc, 0x63, 0x61, 0xb0, 0xf0,
    0x38, 0x18, 0xc, 0xc, 0x6, 0x7, 0x3, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xe, 0xc, 0x18, 0x30, 0x70, 0xff,
    0xff,

    /* U+007B "{" */
    0x1c, 0x38, 0xc1, 0x83, 0xe, 0x38, 0x70, 0x70,
    0x60, 0xc1, 0x81, 0xc3, 0x80,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0x70, 0xe0, 0x60, 0xc1, 0x83, 0x83, 0x87, 0x1c,
    0x30, 0x60, 0xc7, 0xe, 0x0,

    /* U+007E "~" */
    0x6f, 0xfd, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 86, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 63, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 123, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 8, .adv_w = 221, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 178, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 276, .box_w = 16, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 202, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 72, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 95, .adv_w = 91, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 91, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 102, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 112, .adv_w = 175, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 123, .adv_w = 72, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 125, .adv_w = 184, .box_w = 10, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 128, .adv_w = 63, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 100, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 136, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 81, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 158, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 220, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 236, .adv_w = 156, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 63, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 72, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 288, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 297, .adv_w = 184, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 306, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 315, .adv_w = 156, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 250, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 212, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 201, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 194, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 166, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 222, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 184, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 63, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 504, .adv_w = 110, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 147, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 231, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 194, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 240, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 170, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 622, .adv_w = 240, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 170, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 661, .adv_w = 166, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 184, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 711, .adv_w = 212, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 732, .adv_w = 302, .box_w = 17, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 194, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 780, .adv_w = 194, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 798, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 814, .adv_w = 100, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 821, .adv_w = 100, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 828, .adv_w = 100, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 835, .adv_w = 144, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 840, .adv_w = 184, .box_w = 10, .box_h = 2, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 843, .adv_w = 100, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 845, .adv_w = 156, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 854, .adv_w = 165, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 870, .adv_w = 135, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 894, .adv_w = 156, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 903, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 914, .adv_w = 165, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 930, .adv_w = 156, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 944, .adv_w = 63, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 948, .adv_w = 100, .box_w = 5, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 960, .adv_w = 147, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 973, .adv_w = 63, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 977, .adv_w = 199, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 989, .adv_w = 156, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 998, .adv_w = 175, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1009, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1025, .adv_w = 175, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1041, .adv_w = 100, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1046, .adv_w = 138, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1054, .adv_w = 138, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1067, .adv_w = 145, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1075, .adv_w = 169, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1086, .adv_w = 220, .box_w = 12, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1100, .adv_w = 147, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1108, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1124, .adv_w = 156, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1133, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1146, .adv_w = 63, .box_w = 2, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1151, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1164, .adv_w = 128, .box_w = 6, .box_h = 3, .ofs_x = 1, .ofs_y = 11}
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
    3, 34,
    5, 13,
    5, 15,
    5, 34,
    5, 43,
    5, 53,
    5, 55,
    5, 56,
    5, 58,
    5, 75,
    8, 3,
    8, 8,
    8, 69,
    8, 70,
    8, 78,
    8, 84,
    8, 85,
    15, 87,
    15, 88,
    16, 78,
    17, 18,
    17, 43,
    17, 55,
    17, 56,
    19, 20,
    19, 22,
    20, 18,
    20, 24,
    20, 26,
    21, 19,
    21, 26,
    22, 26,
    23, 18,
    23, 24,
    23, 26,
    24, 17,
    24, 19,
    24, 20,
    24, 21,
    24, 22,
    24, 23,
    24, 25,
    24, 26,
    24, 34,
    24, 48,
    24, 50,
    25, 18,
    25, 24,
    25, 26,
    26, 20,
    26, 22,
    26, 24,
    26, 25,
    34, 3,
    34, 5,
    34, 8,
    34, 36,
    34, 40,
    34, 48,
    34, 50,
    34, 52,
    34, 53,
    34, 54,
    34, 55,
    34, 56,
    34, 58,
    34, 66,
    34, 68,
    34, 69,
    34, 70,
    34, 71,
    34, 72,
    34, 75,
    34, 80,
    34, 82,
    34, 84,
    34, 85,
    34, 86,
    34, 87,
    34, 88,
    34, 90,
    35, 13,
    35, 15,
    35, 34,
    35, 36,
    35, 48,
    35, 50,
    35, 53,
    35, 55,
    35, 56,
    35, 57,
    35, 58,
    35, 59,
    35, 75,
    35, 85,
    36, 13,
    36, 25,
    36, 48,
    36, 69,
    36, 70,
    36, 80,
    37, 13,
    37, 15,
    37, 24,
    37, 34,
    37, 43,
    37, 53,
    37, 55,
    37, 56,
    37, 57,
    37, 58,
    37, 59,
    37, 75,
    38, 36,
    38, 40,
    38, 48,
    38, 50,
    38, 87,
    38, 88,
    39, 5,
    39, 13,
    39, 15,
    39, 17,
    39, 21,
    39, 22,
    39, 23,
    39, 25,
    39, 26,
    39, 34,
    39, 36,
    39, 40,
    39, 43,
    39, 48,
    39, 50,
    39, 52,
    39, 66,
    39, 68,
    39, 69,
    39, 70,
    39, 72,
    39, 75,
    39, 80,
    39, 82,
    39, 83,
    39, 84,
    39, 87,
    39, 88,
    39, 91,
    40, 13,
    40, 15,
    43, 13,
    43, 15,
    43, 34,
    44, 36,
    44, 40,
    44, 48,
    44, 70,
    44, 80,
    44, 82,
    44, 86,
    44, 90,
    45, 3,
    45, 8,
    45, 48,
    45, 53,
    45, 54,
    45, 55,
    45, 56,
    45, 58,
    45, 70,
    45, 72,
    45, 75,
    45, 80,
    45, 85,
    45, 87,
    45, 88,
    45, 90,
    47, 13,
    48, 5,
    48, 13,
    48, 15,
    48, 24,
    48, 34,
    48, 43,
    48, 52,
    48, 53,
    48, 55,
    48, 56,
    48, 57,
    48, 58,
    48, 59,
    48, 69,
    48, 75,
    49, 5,
    49, 13,
    49, 15,
    49, 21,
    49, 24,
    49, 34,
    49, 43,
    49, 52,
    49, 55,
    49, 56,
    49, 58,
    49, 66,
    49, 70,
    49, 75,
    49, 80,
    50, 13,
    50, 15,
    50, 75,
    51, 48,
    51, 53,
    51, 55,
    51, 56,
    51, 68,
    51, 69,
    51, 70,
    51, 72,
    51, 80,
    51, 82,
    52, 13,
    52, 15,
    52, 34,
    52, 43,
    52, 53,
    52, 55,
    52, 56,
    52, 58,
    52, 75,
    53, 13,
    53, 14,
    53, 15,
    53, 27,
    53, 28,
    53, 34,
    53, 43,
    53, 48,
    53, 66,
    53, 68,
    53, 70,
    53, 72,
    53, 75,
    53, 80,
    53, 82,
    53, 83,
    53, 86,
    53, 87,
    53, 88,
    53, 90,
    54, 13,
    54, 15,
    54, 34,
    54, 43,
    54, 75,
    55, 5,
    55, 13,
    55, 14,
    55, 15,
    55, 17,
    55, 21,
    55, 25,
    55, 27,
    55, 28,
    55, 34,
    55, 36,
    55, 40,
    55, 43,
    55, 48,
    55, 50,
    55, 52,
    55, 66,
    55, 68,
    55, 69,
    55, 70,
    55, 72,
    55, 75,
    55, 78,
    55, 79,
    55, 80,
    55, 81,
    55, 82,
    55, 83,
    55, 84,
    55, 85,
    55, 86,
    55, 87,
    55, 88,
    55, 90,
    55, 91,
    56, 5,
    56, 13,
    56, 14,
    56, 15,
    56, 17,
    56, 21,
    56, 25,
    56, 27,
    56, 28,
    56, 34,
    56, 36,
    56, 40,
    56, 43,
    56, 48,
    56, 50,
    56, 52,
    56, 66,
    56, 68,
    56, 69,
    56, 70,
    56, 72,
    56, 75,
    56, 78,
    56, 79,
    56, 80,
    56, 81,
    56, 82,
    56, 83,
    56, 84,
    56, 85,
    56, 86,
    56, 87,
    56, 88,
    56, 90,
    56, 91,
    57, 36,
    57, 40,
    57, 48,
    57, 85,
    58, 5,
    58, 13,
    58, 14,
    58, 15,
    58, 27,
    58, 28,
    58, 34,
    58, 36,
    58, 40,
    58, 48,
    58, 50,
    58, 52,
    58, 66,
    58, 68,
    58, 69,
    58, 70,
    58, 71,
    58, 72,
    58, 75,
    58, 80,
    58, 82,
    58, 83,
    58, 85,
    58, 86,
    58, 87,
    58, 88,
    59, 36,
    59, 40,
    59, 48,
    59, 85,
    66, 53,
    66, 58,
    66, 71,
    66, 75,
    66, 85,
    66, 87,
    66, 88,
    66, 90,
    67, 13,
    67, 15,
    67, 55,
    67, 56,
    67, 58,
    67, 66,
    67, 71,
    67, 75,
    67, 85,
    67, 87,
    67, 90,
    68, 13,
    68, 53,
    68, 58,
    68, 69,
    68, 70,
    68, 75,
    68, 80,
    69, 75,
    70, 8,
    70, 13,
    70, 15,
    70, 55,
    70, 56,
    70, 66,
    70, 71,
    70, 75,
    70, 85,
    70, 87,
    70, 88,
    70, 89,
    70, 90,
    70, 91,
    71, 3,
    71, 8,
    71, 13,
    71, 15,
    71, 66,
    71, 68,
    71, 69,
    71, 70,
    71, 72,
    71, 75,
    71, 80,
    71, 84,
    72, 53,
    72, 55,
    72, 56,
    72, 58,
    73, 55,
    73, 56,
    73, 71,
    73, 75,
    73, 85,
    73, 90,
    74, 75,
    76, 66,
    76, 68,
    76, 69,
    76, 70,
    76, 72,
    76, 75,
    76, 80,
    76, 82,
    77, 75,
    78, 55,
    78, 56,
    78, 71,
    78, 75,
    78, 85,
    78, 90,
    79, 55,
    79, 56,
    80, 8,
    80, 13,
    80, 15,
    80, 53,
    80, 55,
    80, 56,
    80, 58,
    80, 71,
    80, 75,
    80, 84,
    80, 85,
    80, 87,
    80, 88,
    80, 89,
    80, 90,
    80, 91,
    81, 13,
    81, 15,
    81, 43,
    81, 53,
    81, 58,
    81, 75,
    81, 87,
    81, 88,
    81, 90,
    83, 13,
    83, 14,
    83, 15,
    83, 27,
    83, 28,
    83, 34,
    83, 55,
    83, 56,
    83, 58,
    83, 66,
    83, 68,
    83, 69,
    83, 70,
    83, 72,
    83, 75,
    83, 80,
    83, 82,
    83, 84,
    84, 8,
    84, 13,
    84, 15,
    84, 71,
    84, 75,
    84, 85,
    84, 87,
    84, 88,
    84, 90,
    85, 16,
    85, 55,
    85, 56,
    85, 57,
    85, 58,
    85, 59,
    85, 66,
    85, 68,
    85, 69,
    85, 70,
    85, 75,
    85, 80,
    85, 84,
    86, 55,
    86, 56,
    86, 75,
    87, 13,
    87, 15,
    87, 55,
    87, 56,
    87, 58,
    87, 66,
    87, 68,
    87, 69,
    87, 70,
    87, 75,
    87, 80,
    87, 84,
    88, 13,
    88, 15,
    88, 55,
    88, 56,
    88, 58,
    88, 66,
    88, 68,
    88, 69,
    88, 70,
    88, 75,
    88, 80,
    88, 84,
    89, 70,
    89, 75,
    89, 80,
    90, 13,
    90, 15,
    90, 66,
    90, 68,
    90, 69,
    90, 70,
    90, 72,
    90, 80,
    90, 82,
    90, 84,
    91, 55,
    91, 56,
    91, 69,
    91, 70,
    91, 75,
    91, 80
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -54, -20, -15, -10, -13, -16, -19, -19,
    -16, -32, -7, -6, -83, -35, -19, -35,
    -31, -26, -26, -13, -13, -19, -13, -13,
    -16, -13, -13, -10, -13, -6, -16, -13,
    -13, -10, -13, -16, -13, -13, -54, -22,
    -45, -30, -13, -61, -26, -26, -13, -10,
    -13, -22, -13, -13, -13, -46, -10, -47,
    -23, -23, -23, -23, -10, -44, -15, -54,
    -54, -50, -6, -13, -13, -12, -27, -13,
    -35, -13, -13, -4, -32, -8, -35, -30,
    -13, -19, -13, -12, -3, -3, -3, -22,
    -22, -22, -13, -26, -13, -32, -16, -10,
    -13, -16, -10, -6, -10, -30, -25, -22,
    -20, -27, -22, -20, -20, -22, -24, -22,
    -38, -16, -16, -16, -16, -19, -19, -19,
    -90, -84, -13, -29, -19, -22, -19, -10,
    -44, -16, -16, -45, -16, -16, -19, -22,
    -19, -19, -22, -22, -35, -22, -19, -16,
    -22, -19, -19, -16, -15, -10, -17, -12,
    -10, -22, -22, -22, -4, -4, -13, -4,
    -4, -54, -54, -26, -44, -13, -54, -57,
    -50, -6, -6, -26, -6, -38, -35, -35,
    -13, -4, -13, -35, -29, -19, -23, -27,
    -13, -23, -23, -23, -4, -26, -22, -3,
    -38, -16, -90, -82, -26, -13, -36, -40,
    -16, -13, -13, -16, -12, -15, -35, -17,
    -13, -8, -38, -4, -15, -13, -13, -13,
    -13, -13, -13, -13, -13, -20, -15, -10,
    -13, -16, -19, -19, -16, -32, -49, -25,
    -44, -24, -24, -43, -40, -23, -32, -48,
    -31, -48, -38, -48, -48, -20, -20, -20,
    -20, -20, -22, -17, -15, -16, -35, -26,
    -61, -28, -54, -13, -50, -19, -26, -26,
    -54, -22, -23, -32, -23, -22, -26, -35,
    -38, -38, -38, -40, -32, -19, -22, -38,
    -22, -38, -26, -35, -26, -20, -22, -22,
    -20, -26, -26, -64, -30, -57, -13, -50,
    -19, -27, -27, -54, -22, -22, -32, -23,
    -22, -26, -35, -38, -38, -38, -40, -32,
    -19, -22, -38, -22, -38, -26, -35, -26,
    -26, -22, -22, -20, -26, -22, -22, -22,
    -32, -19, -56, -29, -50, -28, -28, -50,
    -26, -26, -26, -26, -19, -58, -48, -58,
    -35, -26, -61, -35, -61, -58, -32, -26,
    -23, -32, -32, -22, -22, -22, -32, -32,
    -51, -13, -32, -10, -10, -8, -8, -20,
    -15, -38, -38, -58, -6, -16, -38, -16,
    -14, -13, -8, -48, -48, -8, -13, -32,
    -13, -32, -13, -19, -12, -38, -38, -10,
    -13, -38, -13, -13, -10, -4, -13, -10,
    -7, -7, -34, -30, -10, -16, -16, -15,
    -13, -35, -16, -6, -48, -22, -22, -45,
    -38, -38, -13, -38, -13, -8, -32, -6,
    -13, -13, -13, -15, -38, -13, -13, -32,
    -26, -26, -10, -35, -10, -7, -22, -22,
    -22, -20, -15, -48, -38, -38, -61, -16,
    -38, -10, -16, -15, -12, -10, -13, -13,
    -20, -15, -16, -48, -58, -35, -13, -13,
    -13, -35, -5, -29, -4, -4, -32, -22,
    -22, -32, -10, -15, -16, -15, -15, -38,
    -16, -16, -8, -26, -15, -8, -16, -38,
    -16, -13, -13, -13, -16, -26, -26, -32,
    -26, -32, -10, -16, -16, -13, -32, -16,
    -6, -26, -26, -38, -46, -39, -22, -22,
    -32, -10, -13, -13, -12, -32, -13, -8,
    -36, -30, -22, -22, -32, -10, -13, -13,
    -12, -32, -13, -8, -5, -38, -10, -46,
    -41, -10, -15, -15, -13, -15, -13, -13,
    -10, -26, -26, -13, -13, -38, -13
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 551,
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
const lv_font_t ui_font_odin_20 = {
#else
lv_font_t ui_font_odin_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_ODIN_20*/

