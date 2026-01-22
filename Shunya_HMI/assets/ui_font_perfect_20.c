/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font C:/Users/Sidd/SquareLine/assets/PerfectlyAmicable-26Vl.ttf -o C:/Users/Sidd/SquareLine/assets\ui_font_perfect_20.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_PERFECT_20
#define UI_FONT_PERFECT_20 1
#endif

#if UI_FONT_PERFECT_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xcf,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xbd, 0x80,

    /* U+0023 "#" */
    0x66, 0xff, 0xff, 0x66, 0xff, 0xff, 0x66, 0x66,

    /* U+0024 "$" */
    0x18, 0x7c, 0xff, 0xdf, 0xd8, 0xfc, 0x3f, 0x1b,
    0xdb, 0xff, 0x3c, 0x18,

    /* U+0025 "%" */
    0x1, 0x87, 0x18, 0xfb, 0x8d, 0xb0, 0xdb, 0xf,
    0xe0, 0x76, 0xe0, 0xdf, 0xd, 0xb1, 0xdf, 0x18,
    0xe1, 0x80,

    /* U+0026 "&" */
    0x18, 0x7b, 0xfe, 0x1c, 0x1f, 0xbf, 0x60, 0xc3,
    0xfc, 0xf0, 0xc0,

    /* U+0027 "'" */
    0xff, 0xc0,

    /* U+0028 "(" */
    0x13, 0x66, 0xcc, 0xcc, 0xcc, 0x66, 0x31,

    /* U+0029 ")" */
    0x8c, 0x66, 0x33, 0x33, 0x33, 0x66, 0xc8,

    /* U+002A "*" */
    0x18, 0x18, 0xda, 0x7e, 0x3c, 0x7e, 0xda, 0x18,

    /* U+002B "+" */
    0x30, 0x60, 0xc7, 0xff, 0xe6, 0xc, 0x0,

    /* U+002C "," */
    0xfe,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0xc, 0x61, 0x86, 0x38, 0xc3, 0xc, 0x61, 0x86,
    0x30,

    /* U+0030 "0" */
    0x1c, 0x3f, 0x98, 0xd8, 0x7c, 0x1e, 0xf, 0x7,
    0x83, 0xc3, 0xb1, 0x9f, 0xc3, 0x80,

    /* U+0031 "1" */
    0x7d, 0xb6, 0xdb, 0x6d, 0xb0,

    /* U+0032 "2" */
    0x3c, 0x7e, 0x63, 0x3, 0x3, 0x7, 0xe, 0x1c,
    0x30, 0x60, 0x7f, 0x7f,

    /* U+0033 "3" */
    0x79, 0xf9, 0x18, 0x30, 0x6f, 0x9f, 0x3, 0x6,
    0x8f, 0xf3, 0xc0,

    /* U+0034 "4" */
    0xc, 0x38, 0x71, 0xe3, 0xcd, 0xbb, 0x7f, 0xfe,
    0x18, 0x30, 0x60,

    /* U+0035 "5" */
    0x7e, 0xfd, 0x83, 0x6, 0xf, 0x9f, 0x3, 0x6,
    0x8f, 0xf3, 0xc0,

    /* U+0036 "6" */
    0x1e, 0x3c, 0x70, 0x60, 0x7c, 0xfe, 0x63, 0x63,
    0x63, 0x3e, 0x1c,

    /* U+0037 "7" */
    0xff, 0xfc, 0x18, 0x60, 0xc1, 0x86, 0xc, 0x18,
    0x60, 0xc1, 0x80,

    /* U+0038 "8" */
    0x3c, 0x7e, 0xc3, 0xc3, 0xc3, 0x7e, 0x7e, 0xc3,
    0xc3, 0xc3, 0x7e, 0x3c,

    /* U+0039 "9" */
    0x3a, 0xff, 0x9e, 0x3c, 0x7c, 0xdf, 0x9f, 0x6,
    0xc, 0x18, 0x30,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+003B ";" */
    0xf0, 0xfe,

    /* U+003C "<" */
    0x6, 0x3d, 0xf7, 0x8f, 0xf, 0x87, 0x83,

    /* U+003D "=" */
    0xff, 0xfc, 0x7, 0xff, 0xe0,

    /* U+003E ">" */
    0x81, 0xc1, 0xe0, 0xf1, 0xef, 0x38, 0x40,

    /* U+003F "?" */
    0x3c, 0x7e, 0x63, 0x3, 0x3, 0x6, 0x1e, 0x18,
    0x18, 0x0, 0x18, 0x18,

    /* U+0040 "@" */
    0x1f, 0x7, 0xf1, 0xc7, 0x77, 0xfd, 0xf7, 0xb6,
    0xf7, 0xdf, 0x7b, 0x71, 0xc7, 0xb8, 0x70, 0x0,

    /* U+0041 "A" */
    0xc, 0x7, 0x1, 0xe0, 0x78, 0x3e, 0xd, 0xc3,
    0x30, 0xfc, 0x7f, 0x18, 0x66, 0x1b, 0x6,

    /* U+0042 "B" */
    0xf8, 0xfc, 0xc6, 0xc6, 0xc6, 0xfe, 0xfe, 0xc3,
    0xc3, 0xc3, 0xfe, 0xfc,

    /* U+0043 "C" */
    0x1f, 0xf, 0xe7, 0x1b, 0x80, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xe0, 0x1c, 0x63, 0xf8, 0x7c,

    /* U+0044 "D" */
    0xf8, 0xfe, 0xc6, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc6, 0xfe, 0xf8,

    /* U+0045 "E" */
    0xff, 0xff, 0x6, 0xc, 0x1f, 0xff, 0xe0, 0xc1,
    0x83, 0xff, 0xf0,

    /* U+0046 "F" */
    0xff, 0xff, 0x6, 0xc, 0x1f, 0xff, 0xe0, 0xc1,
    0x83, 0x6, 0x0,

    /* U+0047 "G" */
    0x1f, 0x7, 0xf1, 0xc6, 0x70, 0xc, 0x1, 0x8f,
    0xf1, 0xfe, 0x6, 0xe0, 0xce, 0x38, 0xff, 0xf,
    0xe0,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0049 "I" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xcf,
    0xff,

    /* U+004A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6,
    0x9f, 0xf3, 0xc0,

    /* U+004B "K" */
    0xc7, 0x63, 0x33, 0x1b, 0x8d, 0x87, 0xc3, 0xe1,
    0xd8, 0xee, 0x63, 0x31, 0xd8, 0x60,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0xff, 0xf0,

    /* U+004D "M" */
    0x70, 0x67, 0xe, 0x70, 0xe7, 0xe, 0x79, 0xe7,
    0x9e, 0x79, 0xe6, 0xf2, 0x6f, 0x3c, 0xf3, 0xc6,
    0x3c, 0x63,

    /* U+004E "N" */
    0xc3, 0xe3, 0xe3, 0xf3, 0xf3, 0xdb, 0xdb, 0xcf,
    0xcf, 0xc7, 0xc7, 0xc3,

    /* U+004F "O" */
    0x1f, 0x7, 0xf1, 0xc7, 0x70, 0x6c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xe0, 0xee, 0x38, 0xfe, 0xf,
    0x80,

    /* U+0050 "P" */
    0xfc, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xfc,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0051 "Q" */
    0x1f, 0x7, 0xf1, 0xc7, 0x70, 0x6c, 0x7, 0x80,
    0xf0, 0xde, 0x1b, 0xe1, 0xee, 0x38, 0xff, 0xf,
    0xb0,

    /* U+0052 "R" */
    0xfc, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xfc,
    0xcc, 0xce, 0xc7, 0xc3,

    /* U+0053 "S" */
    0x3c, 0x7f, 0xc3, 0xc0, 0xe0, 0x7c, 0x3e, 0x7,
    0x3, 0xc3, 0xfe, 0x3c,

    /* U+0054 "T" */
    0xff, 0xfc, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18,
    0x30, 0x60, 0xc0,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xe7, 0x7e, 0x3c,

    /* U+0056 "V" */
    0xc1, 0x98, 0x66, 0x19, 0x8c, 0x33, 0xc, 0xc3,
    0x70, 0xf8, 0x1e, 0x7, 0x81, 0xc0, 0x30,

    /* U+0057 "W" */
    0xc3, 0x86, 0xc7, 0x19, 0x8e, 0x33, 0x1c, 0x66,
    0x6c, 0xc6, 0xdb, 0xd, 0xb6, 0x1b, 0x6c, 0x3c,
    0x78, 0x38, 0xe0, 0x71, 0xc0, 0xc3, 0x80,

    /* U+0058 "X" */
    0xc1, 0xb1, 0x9d, 0xc6, 0xc3, 0xe0, 0xe0, 0x70,
    0x7c, 0x36, 0x3b, 0x98, 0xd8, 0x30,

    /* U+0059 "Y" */
    0xc3, 0xc3, 0x66, 0x66, 0x7e, 0x3c, 0x3c, 0x18,
    0x18, 0x18, 0x18, 0x18,

    /* U+005A "Z" */
    0xff, 0xfc, 0x38, 0x61, 0xc3, 0xc, 0x18, 0x61,
    0xc3, 0xff, 0xf0,

    /* U+005B "[" */
    0xff, 0x6d, 0xb6, 0xdb, 0x6f, 0xc0,

    /* U+005C "\\" */
    0xc1, 0x86, 0x18, 0x30, 0xc3, 0xe, 0x18, 0x61,
    0x83,

    /* U+005D "]" */
    0xfd, 0xb6, 0xdb, 0x6d, 0xbf, 0xc0,

    /* U+005E "^" */
    0x8, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xe3,

    /* U+005F "_" */
    0xff, 0xf0,

    /* U+0060 "`" */
    0x47, 0xe, 0x20,

    /* U+0061 "a" */
    0x3f, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7f, 0x3f,

    /* U+0062 "b" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xfe, 0xe7, 0xc3,
    0xc3, 0xe7, 0xfe, 0xfc,

    /* U+0063 "c" */
    0x3c, 0xff, 0x96, 0xc, 0x1c, 0x9f, 0x9e,

    /* U+0064 "d" */
    0x3, 0x3, 0x3, 0x3, 0x3f, 0x7f, 0xe7, 0xc3,
    0xc3, 0xe7, 0x7f, 0x3f,

    /* U+0065 "e" */
    0x38, 0xfb, 0x1f, 0xff, 0xfc, 0x9f, 0x9e,

    /* U+0066 "f" */
    0x19, 0xdc, 0xcf, 0xfd, 0x8c, 0x63, 0x18, 0xc0,

    /* U+0067 "g" */
    0x3f, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7f, 0x3f,
    0x3, 0x27, 0x7e, 0x3c,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xfe, 0xe7, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0xf3, 0xff, 0xfc,

    /* U+006A "j" */
    0x33, 0x33, 0x33, 0x33, 0x33, 0x37, 0xec,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0xc, 0xdb, 0x3e, 0x78, 0xf9,
    0xf3, 0x36, 0x70,

    /* U+006C "l" */
    0xff, 0xff, 0xff,

    /* U+006D "m" */
    0xf9, 0xcf, 0xfe, 0xc6, 0x7c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63,

    /* U+006E "n" */
    0xfc, 0xfe, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+006F "o" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0x3c,

    /* U+0070 "p" */
    0xfc, 0xfe, 0xe7, 0xc3, 0xc3, 0xe7, 0xfe, 0xfc,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0071 "q" */
    0x3f, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7f, 0x3f,
    0x3, 0x3, 0x3, 0x3,

    /* U+0072 "r" */
    0xff, 0xec, 0xcc, 0xcc,

    /* U+0073 "s" */
    0x7b, 0xfc, 0xbc, 0x3d, 0x3f, 0xde,

    /* U+0074 "t" */
    0x63, 0x18, 0xcf, 0xfd, 0x8c, 0x63, 0x18, 0xc0,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7f, 0x3f,

    /* U+0076 "v" */
    0xc6, 0xcd, 0xb3, 0x63, 0xc7, 0xe, 0xc,

    /* U+0077 "w" */
    0xcc, 0xed, 0xd9, 0xbb, 0x3f, 0x67, 0xf8, 0x77,
    0xe, 0xe1, 0x9c,

    /* U+0078 "x" */
    0xee, 0xd9, 0xf1, 0xc3, 0x8f, 0x9b, 0x77,

    /* U+0079 "y" */
    0xc6, 0xcd, 0xb3, 0x63, 0xc7, 0xe, 0x1c, 0x38,
    0x60, 0xc1, 0x80,

    /* U+007A "z" */
    0xff, 0xf1, 0x8e, 0x71, 0x8f, 0xff,

    /* U+007B "{" */
    0x19, 0xcc, 0x63, 0x3b, 0x9c, 0x71, 0x8c, 0x63,
    0x8c,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xc7, 0x18, 0xc6, 0x38, 0xe7, 0x73, 0x18, 0xce,
    0x60,

    /* U+007E "~" */
    0x6f, 0x3f, 0xce, 0x40
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 62, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 54, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 88, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 8, .adv_w = 144, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 16, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 198, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 127, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 46, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 59, .adv_w = 76, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 66, .adv_w = 76, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 73, .adv_w = 120, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 81, .adv_w = 121, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 88, .adv_w = 54, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 89, .adv_w = 101, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 91, .adv_w = 54, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 97, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 153, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 64, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 126, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 119, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 122, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 119, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 132, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 115, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 139, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 124, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 54, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 212, .adv_w = 54, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 214, .adv_w = 116, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 121, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 226, .adv_w = 116, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 125, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 184, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 261, .adv_w = 156, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 163, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 142, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 126, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 126, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 178, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 109, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 119, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 149, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 115, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 194, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 149, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 185, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 188, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 140, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 124, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 534, .adv_w = 156, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 549, .adv_w = 239, .box_w = 15, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 151, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 148, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 118, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 609, .adv_w = 62, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 615, .adv_w = 97, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 62, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 630, .adv_w = 132, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 637, .adv_w = 113, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 639, .adv_w = 81, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 642, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 662, .adv_w = 116, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 669, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 681, .adv_w = 123, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 81, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 708, .adv_w = 138, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 54, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 54, .box_w = 4, .box_h = 14, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 730, .adv_w = 121, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 741, .adv_w = 54, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 744, .adv_w = 206, .box_w = 12, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 756, .adv_w = 138, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 764, .adv_w = 130, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 772, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 784, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 796, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 800, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 806, .adv_w = 85, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 814, .adv_w = 138, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 822, .adv_w = 118, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 829, .adv_w = 173, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 116, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 847, .adv_w = 117, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 858, .adv_w = 117, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 864, .adv_w = 87, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 873, .adv_w = 54, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 877, .adv_w = 87, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 886, .adv_w = 149, .box_w = 9, .box_h = 3, .ofs_x = 0, .ofs_y = 4}
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
    17, 17,
    17, 18,
    17, 19,
    17, 20,
    17, 21,
    17, 22,
    17, 23,
    17, 24,
    17, 25,
    17, 26,
    18, 17,
    18, 23,
    18, 26,
    19, 21,
    19, 23,
    19, 24,
    20, 17,
    20, 23,
    20, 24,
    21, 24,
    21, 26,
    22, 17,
    22, 18,
    22, 23,
    22, 26,
    23, 17,
    23, 18,
    23, 19,
    23, 20,
    23, 23,
    23, 24,
    23, 25,
    23, 26,
    24, 17,
    24, 22,
    24, 23,
    24, 25,
    24, 26,
    25, 17,
    25, 18,
    25, 19,
    25, 20,
    25, 22,
    25, 23,
    25, 24,
    25, 25,
    25, 26,
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
    34, 80,
    34, 82,
    34, 84,
    34, 85,
    34, 86,
    34, 87,
    34, 88,
    34, 90,
    35, 34,
    35, 42,
    35, 43,
    35, 46,
    35, 53,
    35, 55,
    35, 56,
    35, 57,
    35, 58,
    35, 85,
    35, 87,
    35, 88,
    35, 89,
    35, 90,
    36, 34,
    36, 35,
    36, 36,
    36, 37,
    36, 41,
    36, 43,
    36, 44,
    36, 45,
    36, 47,
    36, 48,
    36, 49,
    36, 51,
    36, 54,
    36, 55,
    36, 57,
    36, 58,
    36, 59,
    36, 85,
    36, 87,
    36, 88,
    36, 89,
    36, 90,
    37, 34,
    37, 35,
    37, 36,
    37, 43,
    37, 46,
    37, 53,
    37, 55,
    37, 56,
    37, 57,
    37, 58,
    37, 59,
    38, 87,
    38, 88,
    38, 90,
    39, 34,
    39, 43,
    39, 52,
    39, 66,
    39, 82,
    39, 87,
    39, 88,
    39, 89,
    39, 90,
    40, 34,
    40, 35,
    40, 36,
    40, 43,
    40, 45,
    40, 53,
    40, 55,
    40, 56,
    40, 57,
    40, 58,
    42, 36,
    42, 40,
    42, 48,
    42, 50,
    42, 52,
    42, 66,
    42, 68,
    42, 69,
    42, 70,
    42, 72,
    42, 80,
    42, 82,
    42, 87,
    42, 88,
    42, 90,
    43, 34,
    43, 43,
    44, 34,
    44, 36,
    44, 40,
    44, 43,
    44, 48,
    44, 50,
    44, 52,
    44, 53,
    44, 54,
    44, 55,
    44, 56,
    44, 58,
    44, 66,
    44, 68,
    44, 69,
    44, 70,
    44, 71,
    44, 72,
    44, 74,
    44, 77,
    44, 80,
    44, 82,
    44, 85,
    44, 86,
    44, 87,
    44, 88,
    44, 90,
    44, 91,
    45, 36,
    45, 40,
    45, 48,
    45, 50,
    45, 52,
    45, 53,
    45, 54,
    45, 55,
    45, 56,
    45, 58,
    45, 66,
    45, 68,
    45, 69,
    45, 70,
    45, 72,
    45, 80,
    45, 82,
    45, 85,
    45, 87,
    45, 88,
    45, 90,
    46, 56,
    46, 58,
    46, 85,
    46, 87,
    46, 88,
    46, 90,
    47, 36,
    48, 34,
    48, 36,
    48, 42,
    48, 43,
    48, 52,
    48, 53,
    48, 55,
    48, 56,
    48, 57,
    48, 58,
    48, 59,
    49, 34,
    49, 36,
    49, 42,
    49, 43,
    49, 46,
    49, 53,
    49, 55,
    49, 56,
    49, 57,
    49, 58,
    49, 59,
    49, 66,
    49, 68,
    49, 69,
    49, 70,
    49, 72,
    49, 80,
    49, 82,
    49, 84,
    50, 43,
    50, 52,
    50, 53,
    50, 55,
    50, 56,
    50, 58,
    51, 34,
    51, 40,
    51, 43,
    51, 48,
    51, 50,
    51, 52,
    51, 53,
    51, 55,
    51, 56,
    51, 57,
    51, 58,
    51, 66,
    51, 68,
    51, 69,
    51, 70,
    51, 71,
    51, 72,
    51, 80,
    51, 82,
    51, 84,
    51, 86,
    51, 87,
    51, 88,
    51, 90,
    52, 34,
    52, 36,
    52, 42,
    52, 43,
    52, 48,
    52, 50,
    52, 55,
    52, 56,
    52, 57,
    52, 58,
    52, 74,
    52, 82,
    52, 84,
    52, 85,
    52, 87,
    52, 88,
    52, 89,
    52, 90,
    53, 34,
    53, 36,
    53, 40,
    53, 43,
    53, 48,
    53, 50,
    53, 52,
    53, 66,
    53, 68,
    53, 69,
    53, 70,
    53, 71,
    53, 72,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 83,
    53, 84,
    53, 85,
    53, 86,
    53, 87,
    53, 88,
    53, 89,
    53, 90,
    53, 91,
    54, 34,
    54, 43,
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
    55, 71,
    55, 72,
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
    56, 34,
    56, 36,
    56, 37,
    56, 40,
    56, 43,
    56, 46,
    56, 48,
    56, 50,
    56, 52,
    56, 66,
    56, 68,
    56, 69,
    56, 70,
    56, 71,
    56, 72,
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
    56, 89,
    56, 90,
    56, 91,
    57, 36,
    57, 40,
    57, 43,
    57, 48,
    57, 50,
    57, 52,
    57, 66,
    57, 68,
    57, 69,
    57, 70,
    57, 71,
    57, 72,
    57, 80,
    57, 82,
    57, 84,
    57, 85,
    57, 86,
    57, 87,
    57, 88,
    57, 90,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 46,
    58, 48,
    58, 50,
    58, 52,
    58, 66,
    58, 67,
    58, 68,
    58, 69,
    58, 70,
    58, 71,
    58, 72,
    58, 74,
    58, 75,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 85,
    58, 86,
    58, 87,
    58, 88,
    58, 89,
    58, 90,
    58, 91,
    59, 36,
    59, 37,
    59, 40,
    59, 48,
    59, 50,
    59, 66,
    59, 68,
    59, 69,
    59, 70,
    59, 71,
    59, 72,
    59, 80,
    59, 82,
    59, 87,
    59, 88,
    59, 90,
    66, 53,
    66, 55,
    66, 56,
    66, 58,
    66, 66,
    66, 87,
    66, 88,
    67, 34,
    67, 42,
    67, 43,
    67, 52,
    67, 53,
    67, 55,
    67, 56,
    67, 57,
    67, 58,
    67, 59,
    67, 67,
    67, 84,
    67, 85,
    67, 87,
    67, 88,
    67, 89,
    67, 90,
    67, 91,
    68, 53,
    68, 55,
    68, 56,
    68, 57,
    68, 58,
    68, 69,
    68, 85,
    68, 87,
    68, 88,
    69, 58,
    69, 86,
    69, 87,
    69, 88,
    70, 53,
    70, 55,
    70, 56,
    70, 57,
    70, 58,
    70, 85,
    70, 87,
    70, 88,
    70, 89,
    70, 90,
    70, 91,
    71, 34,
    71, 43,
    71, 46,
    71, 53,
    71, 59,
    71, 66,
    71, 67,
    71, 68,
    71, 69,
    71, 70,
    71, 72,
    71, 80,
    72, 52,
    72, 53,
    72, 55,
    72, 56,
    72, 58,
    72, 75,
    72, 86,
    72, 87,
    72, 88,
    73, 52,
    73, 53,
    73, 55,
    73, 56,
    73, 57,
    73, 58,
    73, 71,
    73, 75,
    73, 84,
    73, 85,
    73, 86,
    73, 87,
    73, 88,
    73, 90,
    73, 91,
    74, 58,
    74, 82,
    75, 57,
    75, 58,
    75, 66,
    75, 69,
    75, 70,
    75, 80,
    75, 82,
    75, 84,
    75, 86,
    76, 36,
    76, 40,
    76, 43,
    76, 48,
    76, 49,
    76, 50,
    76, 52,
    76, 53,
    76, 55,
    76, 56,
    76, 58,
    76, 66,
    76, 67,
    76, 68,
    76, 69,
    76, 70,
    76, 71,
    76, 72,
    76, 73,
    76, 74,
    76, 75,
    76, 77,
    76, 78,
    76, 79,
    76, 80,
    76, 82,
    76, 83,
    76, 84,
    76, 85,
    76, 86,
    76, 87,
    76, 88,
    76, 90,
    77, 86,
    78, 50,
    78, 52,
    78, 53,
    78, 55,
    78, 56,
    78, 58,
    78, 84,
    78, 85,
    78, 86,
    78, 87,
    78, 88,
    78, 90,
    78, 91,
    79, 50,
    79, 52,
    79, 53,
    79, 55,
    79, 56,
    79, 58,
    79, 84,
    79, 85,
    79, 86,
    79, 87,
    79, 88,
    79, 90,
    79, 91,
    80, 34,
    80, 42,
    80, 43,
    80, 52,
    80, 53,
    80, 55,
    80, 56,
    80, 57,
    80, 58,
    80, 75,
    80, 84,
    80, 85,
    80, 86,
    80, 87,
    80, 88,
    80, 89,
    80, 90,
    80, 91,
    81, 34,
    81, 42,
    81, 43,
    81, 52,
    81, 53,
    81, 55,
    81, 56,
    81, 57,
    81, 58,
    81, 71,
    81, 75,
    81, 77,
    81, 84,
    81, 85,
    81, 87,
    81, 88,
    81, 89,
    81, 90,
    81, 91,
    82, 52,
    82, 53,
    82, 55,
    82, 56,
    82, 58,
    82, 75,
    83, 34,
    83, 42,
    83, 43,
    83, 53,
    83, 55,
    83, 56,
    83, 57,
    83, 58,
    83, 59,
    83, 66,
    83, 68,
    83, 69,
    83, 70,
    83, 72,
    83, 80,
    83, 82,
    84, 34,
    84, 52,
    84, 53,
    84, 55,
    84, 56,
    84, 57,
    84, 58,
    84, 66,
    84, 82,
    84, 84,
    84, 85,
    84, 87,
    84, 88,
    84, 89,
    84, 90,
    85, 34,
    85, 43,
    85, 46,
    85, 52,
    85, 53,
    85, 55,
    85, 56,
    85, 57,
    85, 58,
    85, 66,
    85, 68,
    85, 69,
    85, 70,
    85, 72,
    85, 80,
    85, 82,
    86, 52,
    86, 53,
    86, 55,
    86, 56,
    86, 58,
    87, 34,
    87, 42,
    87, 43,
    87, 46,
    87, 53,
    87, 55,
    87, 56,
    87, 57,
    87, 58,
    87, 59,
    87, 66,
    87, 68,
    87, 69,
    87, 70,
    87, 72,
    87, 80,
    87, 82,
    87, 84,
    87, 86,
    88, 34,
    88, 42,
    88, 43,
    88, 46,
    88, 53,
    88, 55,
    88, 56,
    88, 57,
    88, 58,
    88, 59,
    88, 66,
    88, 68,
    88, 69,
    88, 70,
    88, 72,
    88, 80,
    88, 82,
    88, 84,
    88, 86,
    88, 91,
    89, 40,
    89, 53,
    89, 56,
    89, 58,
    89, 66,
    89, 68,
    89, 69,
    89, 70,
    89, 72,
    89, 80,
    89, 81,
    89, 82,
    89, 84,
    90, 34,
    90, 42,
    90, 43,
    90, 46,
    90, 53,
    90, 55,
    90, 56,
    90, 57,
    90, 58,
    90, 59,
    90, 66,
    90, 68,
    90, 69,
    90, 70,
    90, 72,
    90, 80,
    90, 82,
    90, 84,
    90, 91,
    91, 53,
    91, 55,
    91, 56,
    91, 58,
    91, 66,
    91, 68,
    91, 69,
    91, 70,
    91, 80,
    91, 82
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -4, -10, -8, -12, -4, -4, -4, -16,
    -4, -4, -4, -4, -4, -8, -4, -4,
    -2, -2, -4, -4, -8, -2, -2, -4,
    -10, -4, -8, -4, -4, -2, -16, -2,
    -12, -12, -4, -12, -8, -4, -4, -4,
    -4, -4, -4, -4, -8, -2, -4, -12,
    -12, -12, -12, -8, -20, -8, -23, -23,
    -23, -8, -8, -8, -8, -8, -8, -8,
    -8, -4, -12, -8, -12, -12, -8, -8,
    -4, -6, -2, -10, -16, -16, -12, -20,
    -4, -4, -4, -4, -4, -4, 4, -4,
    4, 4, -4, 4, 4, 4, -4, 4,
    4, 4, -4, -4, -4, 4, -4, -4,
    -4, -4, -4, -12, 4, 4, -16, -4,
    -8, -12, -12, -16, -16, -8, -2, -2,
    -2, -12, -23, -4, -2, -2, -2, -2,
    -4, -2, -4, 4, 4, -8, 4, -12,
    -8, -8, -8, -16, -8, -8, -8, -8,
    -4, -4, -4, -4, -4, -4, -4, -4,
    -4, -4, -4, -8, -8, -20, -20, -20,
    -8, -20, -20, -12, -8, -12, -12, -12,
    -8, -12, -12, -12, -12, -12, -12, -4,
    -4, -20, -12, -16, -16, -16, -16, -16,
    -4, -12, -16, -12, -12, -4, -28, -4,
    -28, -28, -28, -4, -4, -4, -4, -4,
    -4, -4, -16, -16, -16, -16, -8, -8,
    -2, -4, -4, -4, 4, -12, 4, -8,
    -16, -4, -8, -8, -8, -12, -12, -4,
    -23, 4, -4, -28, -4, -4, -8, -8,
    -12, -12, -4, -8, -8, -8, -8, -8,
    -8, -8, -4, -4, -4, -8, -8, -8,
    -12, -12, -4, -8, -4, -4, -4, -8,
    -8, -8, -8, -8, -8, -8, -8, -8,
    -2, -8, -20, -8, -6, -2, -2, -2,
    -2, -8, -2, -4, -8, -4, -4, -8,
    -4, -4, -4, -4, -4, -4, -4, -4,
    -4, -4, -4, -20, -8, -8, -23, -8,
    -8, -4, -16, -16, -16, -16, -6, -16,
    -12, -12, -16, -12, -16, -12, -16, -12,
    -12, -16, -16, -12, -12, -12, -8, -8,
    -23, -12, -8, -28, -8, -8, -8, -20,
    -20, -20, -20, -8, -20, -8, -8, -16,
    -8, -16, -8, -12, -8, -12, -8, -8,
    -8, -8, -23, -12, -4, -8, -28, -8,
    -8, -8, -4, -20, -20, -20, -20, -8,
    -20, -8, -8, -16, -8, -16, -8, -12,
    -8, -12, -8, -8, -8, -8, -12, -12,
    -12, -4, -12, -12, -4, -12, -12, -12,
    -12, -8, -12, -12, -12, -4, -8, -8,
    -12, -12, -12, -23, -20, -16, -28, -8,
    -12, -12, -10, -20, -4, -20, -20, -20,
    -16, -20, -4, -4, -16, -16, -20, -16,
    -20, -16, -16, -8, -16, -16, -16, -16,
    -16, -16, -4, 4, -4, -4, -4, -4,
    -2, -2, -2, -4, -2, -2, -2, -4,
    -4, -4, -12, -8, -8, -16, -2, -2,
    -2, -8, -4, -4, -4, -16, -20, -20,
    -12, -20, -4, -2, -2, -4, -8, -8,
    -8, -8, -4, -12, -12, -12, -8, -20,
    -2, 2, -2, -2, -4, -2, -2, -2,
    -16, -20, -20, -12, -20, -4, -8, -8,
    -4, -4, -4, -12, -16, -6, 4, 4,
    -8, 2, -4, -4, -2, -4, -4, -4,
    -12, -8, -8, -16, 8, -4, -4, -4,
    -4, -16, -20, -20, -4, -20, -2, -2,
    -4, -8, -4, -12, -12, -8, -4, -4,
    -2, -4, -4, -2, -2, -2, -2, -2,
    -4, -4, -12, -12, -4, -12, -4, -14,
    -12, -20, -20, -20, -23, -16, -4, -16,
    -18, -16, -8, -16, -4, -8, -4, -8,
    -4, -4, -12, -16, -2, -10, -12, -12,
    -8, -8, -8, -4, -2, -4, -16, -20,
    -20, -20, -4, -8, -4, -12, -12, -8,
    -4, -2, -4, -16, -20, -20, -20, -4,
    -8, -4, -8, -8, -8, -4, -8, -4,
    -4, -4, -16, -16, -16, -12, -20, -2,
    -4, -6, -2, -8, -8, -12, -8, -4,
    -8, -4, -4, -4, -16, -16, -16, -12,
    -20, -4, -2, -4, -2, -8, -8, -8,
    -8, -12, -6, -4, -12, -8, -8, -16,
    20, -16, -8, -20, -12, -8, -8, -12,
    -16, -4, -6, -4, -4, -4, -4, -6,
    -4, -4, -4, -16, -12, -12, -4, -16,
    -2, -2, -2, -4, -4, -4, -2, -4,
    -12, -16, -2, -4, -12, -8, -8, -8,
    -8, -4, -4, -4, -4, -6, -6, -4,
    -4, -12, -8, -8, -16, -12, -4, -20,
    -4, -16, -8, -8, -12, -16, -8, -8,
    -8, -8, -8, -8, -8, -8, -4, -2,
    -12, -4, -20, -4, -16, -8, -8, -12,
    -16, -8, -8, -8, -8, -8, -8, -8,
    -8, -4, -2, -2, -4, -12, -8, -16,
    -8, -8, -8, -4, -4, -8, 4, -8,
    -2, -12, -4, -20, -4, -12, -8, -8,
    -12, -16, -12, -8, -8, -8, -4, -8,
    -8, -8, -4, -2, -12, -8, -12, -16,
    -4, -4, -4, -4, -4, -4
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 774,
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
const lv_font_t ui_font_perfect_20 = {
#else
lv_font_t ui_font_perfect_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if UI_FONT_PERFECT_20*/

