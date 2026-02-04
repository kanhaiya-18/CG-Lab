#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;



void draw(int x1, int y1, int x2, int y2)
{
    glBegin(GL_POINTS);

    // Vertical line
    if (x1 == x2)
    {
        if (y1 > y2) swap(y1, y2);
        for (int y = y1; y <= y2; y++)
            glVertex2i(x1, y);
    }
    else
    {
        int dx = x2 - x1;
        int dy = y2 - y1;

        int p = 2 * dy - dx;
        int x = x1;
        int y = y1;

        glVertex2i(x, y);

        while (x < x2)
        {
            x++;

            if (p < 0)
                p += 2 * dy;
            else
            {
                y++;
                p += 2 * dy - 2 * dx;
            }

            glVertex2i(x, y);
        }
    }

    glEnd();
}



void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    
     //Drawing H
    draw(-150,0,-150,100);
    draw(-100,0,-100,100);
    draw(-150,50,-100,50);
    //drawing E
    draw(-90,0,-90,100);
    draw(-90,0,-40,0);
    draw(-90,50,-40,50);
    draw(-90,100,-40,100); 
    //drawing L
    draw(-30,0,-30,100);
    draw(-30,0,20,0);
    //drawing L
    draw(30,0,30,100);
    draw(30,0,80,0);
    //drawing 
    draw(90,0,90,100);
    draw(90,100,140,100);
    draw(140,100,140,0);
    draw(90,0,140,0);

    
   glFlush();

}

void init() {

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-200, 200, -200, 200); 

}

int main(int argc, char** argv) {
   
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(400, 400);

    glutCreateWindow("Line Drawing using Points Array");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
