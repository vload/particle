#include "rgb.h"
#include "program.h"

using namespace std;

int main(){
    long iterations = 0;

    INIT();
    SETUP();
    do{
        STARTCYCLE();
        LOOP();
    } while (MULTI_FRAME && ++iterations < MAX_ITERATIONS);
    return 0;
}
