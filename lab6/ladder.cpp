#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

// Use float (important for transformations)
float xstart, ystart, xend, yend;

// Function to draw line using simple DDA
void drawLine(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // -------- ORIGINAL LINE --------
    glColor3f(1.0, 1.0, 1.0); // White
    drawLine(xstart, ystart, xend, yend);

    // -------- TRANSFORMATION --------
    float angle = 30 * M_PI / 180;

    // Copy original points
    float xs = xstart, ys = ystart;
    float xe = xend, ye = yend;

    // --- Rotation ---
    float rx1 = xs * cos(angle) - ys * sin(angle);
    float ry1 = xs * sin(angle) + ys * cos(angle);

    float rx2 = xe * cos(angle) - ye * sin(angle);
    float ry2 = xe * sin(angle) + ye * cos(angle);

    // --- Translation (3,2) ---
    rx1 += 3;
    ry1 += 2;

    rx2 += 3;
    ry2 += 2;

    // -------- TRANSFORMED LINE --------
    glColor3f(1.0, 0.0, 0.0); // Red
    drawLine(rx1, ry1, rx2, ry2);

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-30, 30, -30, 30);
}

int main(int argc, char** argv)
{
    cout << "Enter start point (x y): ";
    cin >> xstart >> ystart;

    cout << "Enter end point (x y): ";
    cin >> xend >> yend;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Ladder Transformation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
