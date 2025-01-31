#include <graphics.h>
#include <stdio.h>
#include <math.h>

void pixel(int xc, int yc, int x, int y){
//	using symmetry
	putpixel(xc+x, yc+y,15);
	putpixel(xc+x, yc-y,15);
	putpixel(xc-x, yc+y,15);
	putpixel(xc-x, yc-y,15);
//	15 = WHITE
}

int main() {
    float xc, yc, x, y, p, rx, ry;
    int i, gd = DETECT, gm;
    
    printf("Enter the value of centre point: ");
    scanf("%f%f", &xc, &yc);
    printf("Enter the value of rx and ry of ellipse ");
    scanf("%f%f", &rx, &ry);

    // Initializes the graphics system
    initgraph(&gd, &gm, (char *)"");
    
    x=0;
    y = ry;
    p = pow(ry, 2)-(rx*rx*ry)+(pow(rx,2)/4);
	pixel(xc, yc, x, y);
    while((2*x*pow(ry,2))<(2*y*pow(rx,2)))
    {
    	if(p<0){
    		x++;
    		p = p + (2*pow(ry,2)*x) + pow(ry,2);
		}
		else{
			x++;
			y--;
			p = p + (2*pow(ry,2)*x) + pow(ry,2) - (2*pow(rx,2)*y);
		}
		pixel(xc, yc, x, y);
	}

	p = pow(ry, 2) * pow((float)x+0.5,2) + pow(rx, 2) *pow(y-1,2)-pow(rx,2)*pow(ry,2);
	pixel(xc, yc, x, y);
	while(y>=0){
		if(p>0){
			y--;
			p=p-(2*y*pow(rx, 2))+pow(rx,2);
		}
		else{
			y--;
			x++;
			p = p + (2*pow(ry,2)*x) - (2*y*pow(rx,2)) + 2*rx;
		}
		pixel(xc, yc, x, y);
	}
	
 	getch();

    closegraph();
   

    return 0;
}
