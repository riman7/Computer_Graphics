#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


int main() {
    float xc, yc, r, x, y, p0;
    int i, gd = DETECT, gm;
    
    printf("Enter the value of centre point: ");
    scanf("%f%f", &xc, &yc);
    printf("Enter the value of r ");
    scanf("%f", &r);

    // Initializes the graphics system
    initgraph(&gd, &gm, (char *)"");
    
	
 getch();

    closegraph();
   

    return 0;
}
