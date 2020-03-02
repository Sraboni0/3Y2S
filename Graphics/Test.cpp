#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;
double xmin,xmax,ymin,ymax;

int ComputeCode(double x,double y)
{
    int code =INSIDE;

    if(x<xmin)
        code |= LEFT;
    else if(x>xmax)
        code |= RIGHT;
    if(y<ymin)
        code |= LEFT;
    else if(y>ymax)
        code |= RIGHT;

    return code;
}

void CohenSutherland(double x1,double y1,double x2,double y2)
{
    int xk0 =x1,xk1 = x2,yk0 =y1,yk1 = y2;
    int outcode1 = ComputeCode(x1,y1);
    int outcode2 = ComputeCode(x2,y2);
    bool accept =false;

    while(true){
        if(!(outcode1 | outcode2))
        {
            accept = true;
            break;
        }
        else if(outcode1 & outcode2){
            break;
        }else{
            double x,y;
            int code_out;

            if(outcode1 !=0) code_out =outcode1;
            else code_out = outcode2;

            double slope = (y2-y1)/(x2-x1);

            if(code_out & TOP){
                x = x1 +(1/slope)*(ymax - y1);
                y = ymax;
            }
            else if(code_out & BOTTOM){
                x = x1 +(1/slope)*(ymin - y1);
                y = ymin;
            }
            else if(code_out & RIGHT){
                y = y1 +(slope)*(xmax - x1);
                x = xmax;
            }
           else if(code_out & LEFT){
                y = y1 +(slope)*(xmin - x1);
                x = xmin;
            }

            if(code_out == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = ComputeCode(x1,y1);
            }
            else{
                x2 = x;
                y2 = y;
                outcode2 = ComputeCode(x2,y2);
            }
        }
    }
    if(accept)
    {
        setcolor(BLUE);
        line(xk0,yk0,xk1,yk1);
        rectangle(xmin,ymin,xmax,ymax);
        setcolor(RED);
        line(x1,y1,x2,y2);
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    //setbkcolor(WHITE);

    double x1,x2,y1,y2;
    xmin =100;
    xmax = 400;
    ymin = 100;
    ymax = 400;

    x1 =10,y1=52,x2=500,y2=300;
    CohenSutherland(x1,y1,x2,y2);

    delay(5000);
    closegraph();
    return 0;
}
