#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void Bresenham(int x1,int x2,int y1,int y2)
{
    int dx,dy,decisionP,startX,startY;

    dx = x2-x1;
    dy = y2-y1;

    startX = x1;
    startY = y1;

    decisionP = 2*dy -dx;

    while(startX<x2){
        if(decisionP>=0){
            putpixel(startX,startY,15);
            startY++;
            decisionP += 2*dy - 2*dx;
        }
        else{
            putpixel(startX,startY,15);
            decisionP += 2*dy ;
        }
        delay(10);
        startX++;
    }
}

int main()
{
    int x1,x2,y1,y2;
    cout<<"Enter First Point: ";
    cin>>x1>>y1;

    cout<<"Enter Second Point: ";
    cin>>x2>>y2;

    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");

    Bresenham(x1,x2,y1,y2);//call function

    getch();
    closegraph();

    return 0;
}
