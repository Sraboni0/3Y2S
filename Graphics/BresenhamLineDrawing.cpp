#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void Bresenham(int x1,int x2,int y1,int y2){
    int dx,dy,p,startX,startY;

    dx = x2-x1;
    dy = y2-y1;

    startX=x1;
    startY=y1;

    p = 2*dy-dx;
    //decision maker
    // if P<0 --> (X+1,Y) AND SET P1 = p+2*dy
    // if P>=0 --> (X+1,Y+1) AND SET P1 = p+2*dy-2*dx

    while (startX < x2)
    {
        if(p>=0)
        {
            putpixel(startX,startY,rand()%15);
            startY++;
            p = p+2*dy - 2*dx;
        }
        else
        {
            putpixel(startX,startY,rand()%15);
            p = p+2*dy;
        }
        startX++ ;
    }
}
int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    int x1,x2,y1,y2;

    cout<<"Enter First Point: ";
    cin>>x1>>y1;

    cout<<"Enter Second Point: ";
    cin>>x2>>y2;

    Bresenham(x1,x2,y1,y2);

    getch();
    closegraph();

    return 0;
}
