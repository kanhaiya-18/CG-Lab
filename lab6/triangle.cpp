#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

float xA = 2, yA = 2;
float xB = 6, yB = 2;
float xC = 4, yC = 6;

float fx = 2, fy = 2;

float angle = 45 * M_PI / 180;

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void rotateOrigin(float &x, float &y)
{
    float tx = x;
    float ty = y;

    x = tx * cos(angle) - ty * sin(angle);
    y = tx * sin(angle) + ty * cos(angle);
}

void rotateFixed(float &x, float &y)
{
    x -= fx;
    y -= fy;

    float tx = x;
    float ty = y;

    x = tx * cos(angle) - ty * sin(angle);
    y = tx * sin(angle) + ty * cos(angle);

    x += fx;
    y += fy;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1); 
    drawTriangle(xA, yA, xB, yB, xC, yC);

    float oxA = xA, oyA = yA;
    float oxB = xB, oyB = yB;
    float oxC = xC, oyC = yC;

    rotateOrigin(oxA, oyA);
    rotateOrigin(oxB, oyB);
    rotateOrigin(oxC, oyC);

    glColor3f(1, 0, 0); 
    drawTriangle(oxA, oyA, oxB, oyB, oxC, oyC);

    float fxA = xA, fyA = yA;
    float fxB = xB, fyB = yB;
    float fxC = xC, fyC = yC;

    rotateFixed(fxA, fyA);
    rotateFixed(fxB, fyB);
    rotateFixed(fxC, fyC);

    glColor3f(0, 1, 0);
    drawTriangle(fxA, fyA, fxB, fyB, fxC, fyC);

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangle Rotation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
