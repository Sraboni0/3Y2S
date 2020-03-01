#include <bits/stdc++.h>
#include<graphics.h>
#include<math.h>
using namespace std;

void bezierCurveDraw(int x[4],int y[4])
{
    for(double u=0.0;u<1.0;u+=0.0005)
    {
        double xu = pow(1-u,3)*x[0] + 3*u*pow(1-u,2)*x[1] +
        3*pow(u,2)*(1-u)*x[2] + pow(u,3)*x[3];

        double yu = pow(1-u,3)*y[0] + 3*u*pow(1-u,2)*y[1] +
        3*pow(u,2)*(1-u)*y[2] + pow(u,3)*y[3];

        putpixel(xu,yu,BLUE);
    }

    for (int i = 0; i < 4; ++i)
    {
        putpixel(x[i],y[i],RED);
    }

}
int main()
{
    int gd =DETECT,gm;
    initgraph(&gd,&gm,"");

    int x[4],y[4];
    x[0] = 10,y[0]=10;
    x[1] = 100,y[1]=105;
    x[2] = 100,y[2]=20;
    x[3] = 300,y[3]=350;

    bezierCurveDraw(x,y);

    delay(5000);
    closegraph();
    return 0;
}
