#include <graphics.h>
using namespace std;

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    int n=0;

    while(1){
        line(rand()%650,rand()%650,rand()%650,rand()%650);
        n++;
        if(n>25){
            delay(500);
            cleardevice();
            n=0;
        }
    }

    getch();
    closegraph();

    return 0;
}
