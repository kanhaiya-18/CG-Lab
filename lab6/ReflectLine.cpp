#include <GL/glut.h>
#include <iostream>
using namespace std;

// Renamed variables (IMPORTANT FIX)
float xA, yA, xB, yB;

// Draw line
void drawLine(float a, float b, float c, float d)
{
    glBegin(GL_LINES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // -------- ORIGINAL LINE --------
    glColor3f(1, 1, 1); // White
    drawLine(xA, yA, xB, yB);

    // -------- REFLECTION ABOUT X-AXIS --------
    float rxA = xA;
    float ryA = -yA;

    float rxB = xB;
    float ryB = -yB;

    glColor3f(1, 0, 0); // Red
    drawLine(rxA, ryA, rxB, ryB);

    // -------- REFLECTION ABOUT Y-AXIS --------
    float ryxA = -rxA;
    float ryyA = ryA;

    float ryxB = -rxB;
    float ryyB = ryB;

    glColor3f(0, 1, 0); // Green
    drawLine(ryxA, ryyA, ryxB, ryyB);

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20, 20, -20, 20);
}

int main(int argc, char** argv)
{
    cout << "Enter xA yA: ";
    cin >> xA >> yA;

    cout << "Enter xB yB: ";
    cin >> xB >> yB;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Reflection");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
