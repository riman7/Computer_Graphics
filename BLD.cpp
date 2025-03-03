#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


int main() {
    float x, y, x1, y1, x2, y2, dx, dy, p0, lx, ly;
    int i, gd = DETECT, gm;
    
    printf("Enter the value of x1 and y1: ");
    scanf("%f%f", &x1, &y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%f%f", &x2, &y2);

    // Initializes the graphics system
    initgraph(&gd, &gm, (char *)"");
        dx = abs(x2 - x1);
    dy = abs(y2 - y1);
	if (x2>x1){
		lx =1;
	}
	else{
		lx=-1;
	}
	if(y2>y1){
		ly=1;
	}
	else{
		ly = -1;
	}
	
	if(dx>dy){
		
		p0 = 2*dy -dx;
		
		for(i=0; i<=dx; i++){
			putpixel(x1, y1, 15);
		if(p0<0){
			x1 = x1 + lx;
			y1 = y1;
			p0 = p0 + 2 * dy;
		}
		
		else{
			x1 = x1 + lx;
			y1 = y1 + ly;
			p0 = p0 + 2 * dy - 2 * dx;
			
		}
	}
	}
	
	else{
		p0 = 2 * dx - dy;
		for(i=0; i<=dy; i++){
			putpixel(x1, y1, 15);
			if(p0<0){
				x1 = x1;
				y1 = y1 + ly;
				p0 = p0 + 2 * dx;
			}
			else{
				x1 = x1 + lx;
				y1 = y1 + ly;
				p0 = p0 + 2*dx - 2*dy;
			}
		}
	}
	

    getch();
    closegraph();

    return 0;
}
