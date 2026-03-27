#include <GL/glut.h>
#include <stdio.h>

float oldColor[3], newColor[3];

void getPixel(int x, int y, float color[3])
{
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

void setPixel(int x, int y, float color[3])
{
    glColor3fv(color);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void floodFill(int x, int y)
{
    float currentColor[3];
    getPixel(x, y, currentColor);

    if ((currentColor[0] == oldColor[0] &&
         currentColor[1] == oldColor[1] &&
         currentColor[2] == oldColor[2]))
    {
        setPixel(x, y, newColor);

        floodFill(x + 1, y);
        floodFill(x - 1, y);
        floodFill(x, y + 1);
        floodFill(x, y - 1);
        floodFill(x-1, y+1);
        floodFill(x + 1, y+1);
        floodFill(x + 1, y-1);
        floodFill(x - 1, y-1);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0); 
    glBegin(GL_POLYGON);
        glVertex2i(100, 100);
        glVertex2i(300, 100);
        glVertex2i(300, 300);
        glVertex2i(100, 300);
    glEnd();

    glFlush();

    oldColor[0] = 0.0; oldColor[1] = 0.0; oldColor[2] = 1.0; 
    newColor[0] = 1.0; newColor[1] = 0.0; newColor[2] = 0.0; 
    floodFill(150, 150);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Flood Fill Algorithm");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
