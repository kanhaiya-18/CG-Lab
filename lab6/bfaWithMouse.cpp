#include <GL/glut.h>
#include <stdio.h>

float boundaryColor[3] = {1.0, 1.0, 1.0}; 
float fillColor[3] = {1.0, 0.0, 0.0};     

void getPixel(int x, int y, float color[3])
{
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

// Set pixel color
void setPixel(int x, int y)
{
    glColor3fv(fillColor);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void boundaryFill8(int x, int y)
{
    float current[3];
    getPixel(x, y, current);

    if ((current[0] != boundaryColor[0] ||
         current[1] != boundaryColor[1] ||
         current[2] != boundaryColor[2]) &&

        (current[0] != fillColor[0] ||
         current[1] != fillColor[1] ||
         current[2] != fillColor[2]))
    {
        setPixel(x, y);

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
        glVertex2i(150, 150);
        glVertex2i(350, 150);
        glVertex2i(400, 300);
        glVertex2i(250, 400);
        glVertex2i(100, 300);
    glEnd();

    glFlush();
}

// Mouse function
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int newY = 500 - y;

        boundaryFill8(x, newY);
    }
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
    glutCreateWindow("Polygon Boundary Fill with Mouse");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
