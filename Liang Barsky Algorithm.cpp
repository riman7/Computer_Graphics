#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
    int p[4], q[4], i, gd = DETECT, gm, x1, y1, x2, y2, xwmax, xwmin, ywmax, ywmin;
    int dx, dy;
    float t1=0, t2=1, r;
	printf("Enter the coordinates of clipping window (xmin ymin xmax ymax): ");
	scanf("%d%d%d%d", &xwmin, &ywmin, &xwmax, &ywmax);
    
    printf("Enter the value of starting and ending coordinate of line: ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    // Initializes the graphics system
    initgraph(&gd, &gm, (char *)"");
    cleardevice();  // Clears the screen and sets up the coordinate system

    dx = x2 - x1;
    dy = y2 - y1;
    
    p[0] = -dx;
    q[0] = x1 - xwmin;
    p[1] = dx;
    q[1] = xwmax - x1;
    p[2] = -dy;
    q[2] = y1 - ywmin;
    p[3] = dy;
    q[3] = ywmax - y1;
	
	for (i = 0; i < 4; i++) {
        if (p[i] == 0) { // Parallel to the clipping boundary
            printf("line is parallel to one of the clipping boundary");
			if (q[i] < 0) {
                printf("Line is outside the clipping window.\n");
                closegraph();
                return 0;
            }
            else{
            	//The Liang-Barsky algorithm itself doesn't explicitly include a special method for handling parallel lines.
			}
        }
		else{
			r = (float)q[i]/p[i];
			if(p[i]<0){
				//outside to inside
				if(r>t1){
					t1 = r;
				}
			}
			else if(p[i]>0){
				//inside to outside
				if(r<t2){
					t2 = r;
				}
			}
		}
	}
	if(t1<t2){
		x2 = x1 + t2 * dx;
		y2 = y1 + t2 * dy;
		x1 = x1 + t1 * dx;
		y1 = y1 + t1 * dy;
		line(x1, y1, x2, y2);
		printf("Clipped line: (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
	}
	else{
		printf("line is completely outside");
	}
	rectangle(xwmin, ywmin, xwmax, ywmax);
 	getch();
    closegraph();
    return 0;
}
