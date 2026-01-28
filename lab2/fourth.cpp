#include <GL/glut.h>

int points[6][2] = {

    {50, 50},

    {75, 100},

    {100, 50},
    {40,85},
    {110, 85},
    {50,50}

};

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINE_STRIP); 

    for (int i = 0; i < 6; i++) {

        glVertex2iv(points[i]); 
    }
	
    glEnd();

    glFlush();

}

void init() {

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0, 200, 0, 200); 

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("Line Drawing using Points Array");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
