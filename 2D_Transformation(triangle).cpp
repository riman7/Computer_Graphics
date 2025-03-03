#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

// Function to draw triangle
void drawTriangle(int x[], int y[]) {
    line(x[0], y[0], x[1], y[1]); 
    line(x[1], y[1], x[2], y[2]); 
    line(x[2], y[2], x[0], y[0]); 
}

// Function to translate points
void translate(int x[], int y[], int tx, int ty, int size) {
    for (int i = 0; i < size; i++) {
        x[i] += tx;
        y[i] += ty;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); 
    
    // Arrays for triangle coordinates
    int x[3], y[3], origX[3], origY[3];  // origX, origY to store original coordinates
    // Variables for transformations
    int tx, ty;              // Translation factors
    float sx, sy;           // Scaling factors
    float angle;           // Rotation angle in degrees
    int refX, refY;         // Reference point for scaling and rotation
    
    
    for (int i = 0; i < 3; i++) {
        printf("Enter coordinates for vertex %d (x%d y%d): ", i + 1, i + 1, i + 1);
        scanf("%d %d", &x[i], &y[i]);
        origX[i] = x[i];  // Store original coordinates
        origY[i] = y[i];
    }
    
    // Get reference point for scaling and rotation
    printf("Enter reference point for scaling and rotation (x y): ");
    scanf("%d %d", &refX, &refY);
    
    // Draw original triangle
    setcolor(WHITE);
    drawTriangle(x, y);
    
    printf("Enter translation value for X: ");
    scanf("%d", &tx);
    printf("Enter translation value for Y: ");
    scanf("%d", &ty);
    
    translate(x, y, tx, ty, 3);
    setcolor(RED);
    drawTriangle(x, y);
    // Restore original coordinates
    for (int i = 0; i < 3; i++) {
        x[i] = origX[i];
        y[i] = origY[i];
    }
    
    printf("Enter scaling factor for X (e.g., 1.5 for 150%%): ");
    scanf("%f", &sx);
    printf("Enter scaling factor for Y (e.g., 1.5 for 150%%): ");
    scanf("%f", &sy);
    
    // Apply and draw scaled triangle (scaling from reference point)
    translate(x, y, -refX, -refY, 3);
    for (int i = 0; i < 3; i++) {
        x[i] = (int)(x[i] * sx);
        y[i] = (int)(y[i] * sy);
    }
    translate(x, y, refX, refY, 3);
    setcolor(GREEN);
    drawTriangle(x, y);
    // Restore original coordinates
    for (int i = 0; i < 3; i++) {
        x[i] = origX[i];
        y[i] = origY[i];
    }
    
    // Get rotation value
    printf("Enter rotation angle in degrees: ");
    scanf("%f", &angle);
    
    // Convert angle to radians
    float rad = angle * M_PI / 180.0;
    float cosRad = cos(rad);
    float sinRad = sin(rad);
    
    // Apply and draw rotated triangle (rotating around reference point)
    translate(x, y, -refX, -refY, 3);
    for (int i = 0; i < 3; i++) {
        int tempX = x[i];
        x[i] = (int)(tempX * cosRad - y[i] * sinRad);
        y[i] = (int)(tempX * sinRad + y[i] * cosRad);
    }
    translate(x, y, refX, refY, 3);
    setcolor(YELLOW);
    drawTriangle(x, y);
    // Restore original coordinates
    for (int i = 0; i < 3; i++) {
        x[i] = origX[i];
        y[i] = origY[i];
    }
    
    // Apply all transformations combined (scale -> rotate -> translate)
    // Scale
    translate(x, y, -refX, -refY, 3);
    for (int i = 0; i < 3; i++) {
        x[i] = (int)(x[i] * sx);
        y[i] = (int)(y[i] * sy);
    }
    translate(x, y, refX, refY, 3);
    // Rotate
    translate(x, y, -refX, -refY, 3);
    for (int i = 0; i < 3; i++) {
        int tempX = x[i];
        x[i] = (int)(tempX * cosRad - y[i] * sinRad);
        y[i] = (int)(tempX * sinRad + y[i] * cosRad);
    }
    translate(x, y, refX, refY, 3);
    // Translate
    translate(x, y, tx, ty, 3);
    setcolor(CYAN);
    drawTriangle(x, y);
    
    getch();  
    closegraph();
    return 0;
}