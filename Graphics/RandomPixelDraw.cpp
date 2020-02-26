#include <conio.h>
#include <graphics.h>

int main()
{
    int gd=DETECT,gm;
    int i,x,y;
    initgraph(&gd,&gm,"");

    while(!kbhit())
    {
        for(i=0;i<=500;i++)
        {
            x = rand()%getmaxx();
            y= rand()%getmaxy();
            putpixel(x,y,rand()%15);
        }
        delay(250);
        //clear screen
        cleardevice();
    }
    getch();
    closegraph();

    return 0;
}
