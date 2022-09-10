#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include "rgb.h"

#define NO_PARTICLES    300000
#define NO_ATTRACTORS   3
#define WALL_COLISIONS  FALSE

double p[NO_PARTICLES][4];
double td, tdx, tdy, ta, tax, tay, tv;
int r, g, b, a[NO_ATTRACTORS][3] = {{600, 880, 5000}, {960, 200, 5000}, {1400, 880, 5000}};

double fRand(double fMin, double fMax){                                                             ///© https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void SETUP(){
    srand(time(NULL));

    for(int i = 0; i < NO_PARTICLES; i++){
        p[i][0] = fRand(0, 1919);
        p[i][1] = fRand(0, 1079);
        p[i][2] = fRand(-1, 1);
        p[i][3] = fRand(-1, 1);
    }


}

void LOOP(){
    for(int i = 0; i < NO_PARTICLES; i++){
        tax = tay = 0;
        for(int j = 0; j < NO_ATTRACTORS; j++){
            tdx = (p[i][0] - a[j][0]);
            tdy = (p[i][1] - a[j][1]);
            td = sqrt(tdx * tdx + tdy * tdy);
            ta = a[j][2]/td/td;
            tax += ta * -tdx / td;
            tay += ta * -tdy / td;
        }
        p[i][0] = p[i][0] + p[i][2] + tax/2;
        p[i][1] = p[i][1] + p[i][3] + tay/2;
        p[i][2] = p[i][2] + tax;
        p[i][3] = p[i][3] + tay;
        tv = sqrt(p[i][2] * p[i][2] + p[i][3] * p[i][3])* 10;
        r = g = b = 0;
        if(tv<256){
            r = 0;
            g = tv;
            b = 256 - tv;
        }
        else if(tv < 512){
            r = tv - 256;
            g = 512 - tv;
            b = 0;
        }
        else if(tv < 768){
            r = 768 - tv;
            g = 0;
            b = tv - 512;
        }
        if(WALL_COLISIONS){
            if(p[i][0] > 1919 || p[i][0] < 0){
                p[i][2] = -p[i][2];
            }
            if(p[i][1] > 1079 || p[i][1] < 0){
                p[i][3] = -p[i][3];
            }
        }

        if(p[i][0] <= 1919 && p[i][1] <= 1079 && p[i][0] > 0 && p[i][1] > 0){
            set_pixel(p[i][0], p[i][1], r, g, b, true);
        }
    }
}
