#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void MidPointCircle(int xinit,int yinit,int radius)
{
    int x = radius;
    int y=0;
    int RoundError = 1 - radius;


    while(x>=y)
    {
        putpixel(xinit + x,yinit + y,1);
        putpixel(xinit - x,yinit - y,2);

        putpixel(xinit + y,yinit + x,3);  
        putpixel(xinit - y,yinit - x,4);
        
        putpixel(xinit - x,yinit + y, 5);
        putpixel(xinit + x,yinit - y, 6);

        putpixel(xinit - y,yinit + x, 7);
        putpixel(xinit + y,yinit - x, 8);
        

        if(RoundError<=0){
            RoundError += 2*y + 1;
        }else{
            RoundError += 2*(y-x)+1;
            x =x-1;
        }
        y++;
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
