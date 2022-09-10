#include "rgb.h"
#include "program.h"

using namespace std;

int main(){
    INIT();
    SETUP();
    do{
        STARTCYCLE();
        LOOP();
    }while(MULTI_FRAME);
    return 0;
}
