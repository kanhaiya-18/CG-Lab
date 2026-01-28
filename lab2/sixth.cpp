#include <GL/glut.h>
#include <cstdio>
int px = 0, py = 0;
int windowSize = 500;
void mouseCallback(int button, int state, int x, int y)
{
	if(button ==  GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
 	    //printf("hello");
	    px = x;
	    py = windowSize - y;
	    glutPostRedisplay();
	}
}
void display() {

    glColor3f(1.0, 0.0, 0.0);

    glPointSize(10.0);
    glBegin(GL_POINTS);

	glVertex2i(px,py);
    glEnd();
    glFlush();

}

void init() {

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0, 500, 0, 500); 

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("Line Drawing using Points Array");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouseCallback);

    glutMainLoop();

    return 0;

}
