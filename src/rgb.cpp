#include "rgb.h"
#include <windows.h>
#include <cmath>

#include <cstdio>


COLORREF *arr;
int toDelete[WIDTH*HEIGHT][2];
int lastToDelete;
HWND window;
HDC hdc;
HDC src;
HBITMAP screen;


void set_pixel(int x, int y, int R, int G, int B, bool del){                                        ///Set a pixel on the screen
    arr[y * WIDTH + x] = RGB(B, G, R);
    if(del){
        toDelete[lastToDelete][0] = x;
        toDelete[lastToDelete][1] = y;
        lastToDelete++;
    }
}


void STARTCYCLE(){
        screen = CreateBitmap(WIDTH, HEIGHT, 1, 8 * 4, (void*) arr);
        SelectObject(src, screen);
        BitBlt(hdc, 0, 0, WIDTH, HEIGHT, src, 0, 0, SRCCOPY);
        DeleteObject(screen);
        while(lastToDelete && !KEEP_SCREEN){
            lastToDelete--;
            arr[toDelete[lastToDelete][1] * WIDTH + toDelete[lastToDelete][0]] = RGB(0, 0, 0);
        }
        lastToDelete = 0;
        Sleep(SLEEP);
}

void INIT(){
    arr = (COLORREF*) calloc(WIDTH * HEIGHT, sizeof(COLORREF));
    hdc = GetDC(window);
    src = CreateCompatibleDC(hdc);
    window = CreateWindow(TEXT("scrollbar"), NULL, WS_VISIBLE | WS_POPUP, 0, 0, WIDTH, HEIGHT, NULL, NULL, NULL, NULL);
}
