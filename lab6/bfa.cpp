#include <GL/glut.h>
#include <stdio.h>

float boundaryColor[3] = {1.0, 1.0, 1.0}; 
float fillColor[3] = {1.0, 0.0, 0.0};  

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

void boundaryFill8(int x, int y)
{
    float currentColor[3];
    getPixel(x, y, currentColor);

    if ((currentColor[0] != boundaryColor[0] ||
         currentColor[1] != boundaryColor[1] ||
         currentColor[2] != boundaryColor[2]) &&

        (currentColor[0] != fillColor[0] ||
         currentColor[1] != fillColor[1] ||
         currentColor[2] != fillColor[2]))
    {
        setPixel(x, y, fillColor);

        boundaryFill8(x + 1, y);
        boundaryFill8(x - 1, y);
        boundaryFill8(x, y + 1);
        boundaryFill8(x, y - 1);

        boundaryFill8(x + 1, y + 1);
        boundaryFill8(x - 1, y + 1);
        boundaryFill8(x + 1, y - 1);
        boundaryFill8(x - 1, y - 1);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 100);
        glVertex2i(300, 100);
        glVertex2i(300, 300);
        glVertex2i(100, 300);
    glEnd();

    glFlush();

    boundaryFill8(150, 150);
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
    glutCreateWindow("Boundary Fill 8-Connected");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
