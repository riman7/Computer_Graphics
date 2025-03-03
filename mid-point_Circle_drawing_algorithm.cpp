#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to plot a point in all eight octants
void plotCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r, x, y, d;

    // Get user input
    printf("Enter center coordinates (xc yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius: ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "");

    x = 0;
    y = r;
    d = 1 - r;  
    
    plotCirclePoints(xc, yc, x, y);

    while (x < y) {
        x++;
        if (d < 0) {
            d = d + 2 * x + 1;
        } else {
            y--;
            d = d + 2 * (x - y) + 1;
        }
        plotCirclePoints(xc, yc, x, y);
    }

    getch();
    closegraph();
    return 0;
}