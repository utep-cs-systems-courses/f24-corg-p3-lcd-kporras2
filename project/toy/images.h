#ifndef images_included
#define images_included

typedef unsigned char u_char;
typedef unsigned int u_int;

extern short redrawScreen;

void draw_init();
void draw_eighth_notes(u_char col, u_char row, u_int color);
void draw_cloud(u_char startCol, u_char startRow);
void draw_cop_car();
void draw_lamb();
void draw_sun(u_char col, u_char row);
void draw_flower(u_char col, u_char row);
void draw_fluff(u_char col, u_char row, u_char width, u_char height);
void draw_star();
void draw_large_star(u_char col, u_char row, u_char size, u_int color);
void draw_small_star(u_char col, u_char row, u_int color);
void draw_shooting_star(u_char col, u_char row, u_char length, u_int color);
void draw_stop();
void update_image();
void drawString11x16(u_char col, u_char row, char *string, u_int fgColorBGR, u_int bgColorBGR);
void drawChar11x16(u_char col, u_char row, char c, u_int fgColorBGR, u_int bgColorBGR);
#endif
