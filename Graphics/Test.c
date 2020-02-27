#include <graphics.h>

void plot8CirclePoints(int ox, int oy, int x, int y) {
    putpixel(ox + x, oy + y, 1);
    putpixel(ox + y, oy + x, 2);
    putpixel(ox - x, ox + y, 3);
    putpixel(ox - y, ox + x, 4);
    putpixel(ox - x, oy - y, 5);
    putpixel(ox - y, oy - x, 6);
    putpixel(ox + x, oy - y, 7);
    putpixel(ox + y, oy - x, 8);
}

void plotTriangle(int ox, int oy, int r) {
    int x = r, y = 0, re = 0;
    int xc = 1 - 2 * r;
    int yc = 1;

    while(x >= y) {
        plot8CirclePoints(ox, oy, x, y);
        y++;
        re += yc;
        yc += 2;

        if(2 * re + xc > 0) {
            x--;
            re += xc;
            xc += 2;
        }
    }
}

int main() {
    int gd=DETECT, gm=DETECT;
	initgraph(&gd,&gm,"");
    setbkcolor(WHITE);

    int ox = 250, oy = 250, r = 200;
    plotTriangle(ox, oy, r);

    delay(5000);
    closegraph();
    return 0;
}
