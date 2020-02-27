#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;

const int LEFT =1,RIGHT=2,BOTTOM=4,TOP=8;
double xmin,xmax,ymin,ymax;

int OutCode(double x,double y)
{
    int code = 0;

    if(x < xmin)
        code =code|LEFT;
    else if(x>xmax)
        code = code|RIGHT;
    if(y<ymin)
        code = code | BOTTOM;
    else if(y>ymax)
        code = code | TOP;
    return code;
}

void CohenLineClip(double x0,double y0,double x1,double y1)
{
    int xk0 =x0,xk1 = x1,yk0 =y0,yk1 = y1;
    int oout1 = OutCode(x0,y0);
    int oout2 = OutCode(x1,y1);
    int accept = false;

    while(true)
    {
        if(!(oout1 | oout2))//Inside rectangle
        {
            accept = true;
            break;
        }
        else if(oout1 & oout2)
        {
            break; //two endpoint Outsize
        }
        else
        {
            int code_out;
            double x,y;

            if(oout1 != 0)  //Find which point is outside
                            //of rectangle
                code_out = oout1;
            else
                code_out= oout2;

            if(code_out & TOP) //above the rectangle
            {
                x = x0+ (ymax - y0)*(x1-x0) /(y1-y0);
                y = ymax;
            }
            else if(code_out & BOTTOM) // Below
            {
                x = x0 +(ymin - y0) * (x1-x0)/(y1-y0);
                y = ymin;
            }
            else if(code_out & RIGHT)
            {
                y= y0 + (xmax - x0) *(y1-y0)/(x1 - x0);
                x = xmax;
            }
           else if(code_out & LEFT)
            {
                y= y0 + (xmin - x0) *(y1-y0)/(x1 - x0);
                x = xmin;
            }
            //Intersection Point
            if(code_out==oout1)
            {
                x0 =x;
                y0=y;
                oout1 = OutCode(x0,y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                oout2 = OutCode(x1,y1);
            }
        }
    }
    if(accept )
    {
        //Draw Clipped part

        setcolor(BLUE);
        line(xk0,yk0,xk1,yk1);
        rectangle(xmin,ymin,xmax,ymax);
        setcolor(RED);
        line(x0,y0,x1,y1);
    }
    else{
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(BLUE);
        line(xk0,yk0,xk1,yk1);
	}
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    setbkcolor(WHITE);

    double x1,x2,y1,y2;
    xmin =100;
    xmax = 400;
    ymin = 100;
    ymax = 400;

    x1=50,y1=50,x2=450,y2=300;
    CohenLineClip(x1,y1,x2,y2);

    delay(5000);
    closegraph();
    return 0;
}
