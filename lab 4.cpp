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
    x= 0;
    y = r;
    p0 = 5.0/4.0-r;
	
	for(i=0; y>=x; i++){
		putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

//		line(i, 100, 200, 200);
		if(p0<0){
			x = x +1;
			y = y;
			p0 = p0 + 2* x +1;
		}
		else{
			x = x +1;
			y = y - 1;
			p0 = p0 + 2* x +1 - 2 *y;
		}

	}
	
 getch();

    closegraph();
   

    return 0;
}
