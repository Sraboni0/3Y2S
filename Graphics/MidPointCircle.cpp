#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void MidPointCircle(int x0,int y0,int radius)
{
    int x = radius;
    int y=0,error =0;

    while(x>=y)
    {
        putpixel(x0 + x,y0 + y,1);
        putpixel(x0 + y,y0 + x,2);
        putpixel(x0 - y,y0 + x,3);
        putpixel(x0 - x,y0 + y,4);
        putpixel(x0 - x,y0 - y,5);
        putpixel(x0 - y,y0 - x,6);
        putpixel(x0 + y,y0 - x,7);
        putpixel(x0 + x,y0 - y,8);

        if(error<=0)
        {
            y = y+1;
            error = error +2*y +1;
        }
        else{
            x =x-1;
            error = error - 2*x +1;
        }
    }
}

int main()
{
    int x,y,radius;

    cout<<"Enter Radius of Circle: ";
    cin>>radius;
    cout<<"Enter Co-ordinate of Center: ";
    cin>>x>>y;

    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");

    MidPointCircle(x,y,radius);

    getch();
    closegraph();

    return 0;
}
