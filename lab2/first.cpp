#include <GL/glut.h>

int points1[2][2] = {

    {50, 100},

    {75, 150},
};
int points2[2][2] = {

    {40, 80},

    {80, 100},
};

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINE_STRIP); 

    for (int i = 0; i < 2; i++) {

        glVertex2iv(points1[i]); 
    }
    for (int i = 0; i < 2; i++) {

        glVertex2iv(points2[i]); 
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
