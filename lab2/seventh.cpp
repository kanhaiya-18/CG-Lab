#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;
int n;   

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    float cx = 250, cy = 250;  
    float r = 150;        
    float angle;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++)
    {
        angle = 2 * 3.14159f * i / n;
        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);

        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
  
    cout<<"Enter number of sides: ";
    cin>>n;
    if(n < 3)
    {
    	printf("the sides should be more than 2 to make a polygon\n");
    	return 0;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Regular Polygon");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

