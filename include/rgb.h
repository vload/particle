#ifndef RGB_H
#define RGB_H

#include <windows.h>                                                                                /// COLORREF, HWND, HDC, HBITMAP

#define PI      3.1415926535897                                                                     /// Value of Pi

#define WIDTH   1920                                                                                /// Width of the window
#define HEIGHT  1080                                                                                /// Height of the window
#define SLEEP   0                                                                                   /// Amount of time to freeze every frame

#define KEEP_SCREEN FALSE                                                                           /// If false the screen will be wiped every frame
#define MULTI_FRAME TRUE                                                                            /// If false the loop will only execute once
#define MAX_ITERATIONS 500                                                                          /// Change this for the program to run for longer

extern COLORREF *arr;
extern HBITMAP screen;
extern HDC hdc;
extern HDC src;
extern HWND window;
extern int toDelete[WIDTH*HEIGHT][2];
extern int lastToDelete;


void INIT();
void STARTCYCLE();


void set_pixel(int x, int y, int R, int G, int B, bool del = true);                                 ///Set a pixel on the screen

#endif // RGB_H
