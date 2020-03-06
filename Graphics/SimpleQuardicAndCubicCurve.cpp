#include <bits/stdc++.h>
#include<graphics.h>
#include<math.h>
using namespace std;

void CubicCurve(int x[4],int y[4])
{
    // the main Equation for this curve is
    // p(u) = p0 *(1-u)^3 + p1*3*u*(1-u)^2 + p2*3*u^2*(1-u) + p3*u^3
    //implement for this Equation

    for(double u=0.0;u<1.0;u+=0.0005)
    {
        // x Co-ordinate calculate by
        //x(u) = x0 *(1-u)^3 + x1*3*u*(1-u)^2 + x2*3*u^2*(1-u) + x3*u^3 Equation
        double xu = pow(1-u,3)*x[0] + 3*u*pow(1-u,2)*x[1] + 3*pow(u,2)*(1-u)*x[2] + pow(u,3)*x[3];

        // y Co-ordinate calculate by
        //y(u) = y0 *(1-u)^3 + y1*3*u*(1-u)^2 + y2*3*u^2*(1-u) + y3*u^3
        double yu = pow(1-u,3)*y[0] + 3*u*pow(1-u,2)*y[1] + 3*pow(u,2)*(1-u)*y[2] + pow(u,3)*y[3];

        putpixel(xu,yu,BLUE);
    }

    //For Checking the Main Four Point by Different Color
    //Not Compoltury part
    for (int i = 0; i < 4; ++i)
    {
        setfillstyle(SOLID_FILL,WHITE);
        circle(x[i],y[i],10);
        putpixel(x[i],y[i],RED);
    }

}

void QuardicCurve(int x[3],int y[3])
{
    // the main Equation for this curve is
    // p(u) = p0 *(1-u)^2 + p1*2*u*(1-u) + p3*u^2
    //implement for this Equation

    for(double u=0.0;u<1.0;u+=0.0005)
    {
        // x Co-ordinate calculate by
        // x(u) = x0 *(1-u)^2 + x1*2*u*(1-u) + x3*u^2
       double xu = pow(1-u,2)*x[0] + x[1]*2*u*(1-u) + pow(u,2)*x[2];

        // y Co-ordinate calculate by
        //y(u) = y0 *(1-u)^3 + y1*3*u*(1-u)^2 + y2*3*u^2*(1-u) + y3*u^3
        double yu = pow(1-u,2)*y[0] + y[1]*2*u*(1-u) + pow(u,2)*y[2];
        putpixel(xu,yu,BLUE);
    }

    //For Checking the Main Four Point by Different Color
    for (int i = 0; i < 3; ++i)
    {
        setfillstyle(SOLID_FILL,WHITE);
        circle(x[i],y[i],10);
        putpixel(x[i],y[i],RED);
    }

}

void SimpleCurve(int x[2],int y[2])
{
    // the main Equation for this curve is
    // p(u) = p0 *(1-u) + p1*u
    //implement for this Equation

    for(double u=0.0;u<1.0;u+=0.0005)
    {
        // x Co-ordinate calculate by
        // x(u) = x0 *(1-u) + x1*u
        double xu = x[0]*(1-u) + x[1]*u;

        // y Co-ordinate calculate by
       // y(u) = y0 *(1-u) + y1*u
        double yu = y[0]*(1-u) + y[1]*u;
        putpixel(xu,yu,BLUE);
    }

    //For Checking the Main Four Point by Different Color
    //Not Compoltury part
    for (int i = 0; i < 2; ++i)
    {
        setfillstyle(SOLID_FILL,WHITE);
        circle(x[i],y[i],10);
        putpixel(x[i],y[i],RED);
    }
}


int main()
{
    int x[4],y[4];
    x[0] = 10,y[0]=10;  //take input for x0,y0 or for P0
    x[1] = 100,y[1]=250; //take input for x1,y1 or for P1
    x[2] = 300,y[2]=20; //take input for x2,y2 or for P2
    x[3] = 450,y[3]=350;//take input for x3,y3 or for P3
    //This is created For  four Point Cubic curve

    int N;
    cout<<"Enter which Type of curve do you want: "<<endl;
    cout<<"Simple curve."<<endl;
    cout<<"2.QuardicCurve."<<endl;
    cout<<"3.Curve curve."<<endl;

    cin>>N;
    int gd =DETECT,gm;
    initgraph(&gd,&gm,"");


    if (N==3){
        CubicCurve(x,y);
    }
    else if(N==2){
        QuardicCurve(x,y);
    }
    else if (N){
        SimpleCurve(x,y);
    }

    delay(5000);
    closegraph();
    return 0;
}
