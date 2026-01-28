#include <GL/glut.h>
#include <iostream>
using namespace std;

int x = 100;
int y = 100;
void init() {

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glPointSize(10.0);

    glBegin(GL_POINTS);

        glVertex2i(x,y);
    glEnd();

    glFlush();

}
void specialKeys(int key, int, int)
{
    int step = 10;
    if (key == GLUT_KEY_UP) y += step;
    if (key == GLUT_KEY_DOWN) y -= step;
    if (key == GLUT_KEY_LEFT) x -= step;
    if (key == GLUT_KEY_RIGHT) x += step;

    glutPostRedisplay();  // redraw
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("Draw Point Example");

    init();

    glutDisplayFunc(display);
    
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;

}
