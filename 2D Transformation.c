#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

// Function to draw triangle without loop
void drawTriangle(int x[], int y[]) {
    line(x[0], y[0], x[1], y[1]);  // First to second vertex
    line(x[1], y[1], x[2], y[2]);  // Second to third vertex
    line(x[2], y[2], x[0], y[0]);  // Third to first vertex
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");    // Initialize graphics mode
    
    // Arrays for triangle coordinates
    int x[3], y[3];
    // Variables for transformations
    int tx, ty;              // Translation factors
    float sx, sy;           // Scaling factors
    float angle;           // Rotation angle in degrees
    
    // Get triangle coordinates from user using a loop
    for (int i = 0; i < 3; i++) {
        printf("Enter coordinates for vertex %d (x%d y%d): ", i + 1, i + 1, i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }
    
    // Draw original triangle
    setcolor(WHITE);
    drawTriangle(x, y);
    
    // Get translation values
    printf("Enter translation value for X: ");
    scanf("%d", &tx);
    printf("Enter translation value for Y: ");
    scanf("%d", &ty);
    
    // Apply and draw translated triangle
    int transX[3], transY[3];
    for (int i = 0; i < 3; i++) {
        transX[i] = x[i] + tx;
        transY[i] = y[i] + ty;
    }
    setcolor(RED);
    drawTriangle(transX, transY);
    
    // Get scaling values
    printf("Enter scaling factor for X (e.g., 1.5 for 150%%): ");
    scanf("%f", &sx);
    printf("Enter scaling factor for Y (e.g., 1.5 for 150%%): ");
    scanf("%f", &sy);
    
    // Apply and draw scaled triangle (scaling from first vertex)
    int scaleX[3], scaleY[3];
    for (int i = 0; i < 3; i++) {
        scaleX[i] = x[0] + (int)((x[i] - x[0]) * sx);
        scaleY[i] = y[0] + (int)((y[i] - y[0]) * sy);
    }
    setcolor(GREEN);
    drawTriangle(scaleX, scaleY);
    
    // Get rotation value
    printf("Enter rotation angle in degrees: ");
    scanf("%f", &angle);
    
    // Convert angle to radians
    float rad = angle * M_PI / 180.0;
    
    // Apply and draw rotated triangle (rotating around first vertex)
    int rotX[3], rotY[3];
    for (int i = 0; i < 3; i++) {
        rotX[i] = x[0] + (int)((x[i] - x[0]) * cos(rad) - (y[i] - y[0]) * sin(rad));
        rotY[i] = y[0] + (int)((x[i] - x[0]) * sin(rad) + (y[i] - y[0]) * cos(rad));
    }
    setcolor(YELLOW);
    drawTriangle(rotX, rotY);
    
    // Apply all transformations combined (scale -> rotate -> translate)
    int combX[3], combY[3];
    for (int i = 0; i < 3; i++) {
        // First scale
        int sxTemp = x[0] + (int)((x[i] - x[0]) * sx);
        int syTemp = y[0] + (int)((y[i] - y[0]) * sy);
        // Then rotate
        combX[i] = x[0] + (int)((sxTemp - x[0]) * cos(rad) - (syTemp - y[0]) * sin(rad));
        combY[i] = y[0] + (int)((sxTemp - x[0]) * sin(rad) + (syTemp - y[0]) * cos(rad));
        // Finally translate
        combX[i] += tx;
        combY[i] += ty;
    }
    setcolor(CYAN);
    drawTriangle(combX, combY);
    
    getch();    // Wait for key press
    closegraph();    // Close graphics mode
    return 0;
}