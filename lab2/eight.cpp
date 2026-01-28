#include <GL/glut.h>

int front[5][2] = {

    {-50,0},
    {-50,120},
    {50,120},
    {50,0},
    {-50,0}
};
int chhat[3][2] = 
{
	{-50,120},
	{0,180},
	{50,120}
};
int door[4][2] = {
	{-12,0},
	{-12,50},
	{12,50},
	{12,0}
};
int khidki[4][2] = {
	{-12, 80},
	{-12,100},
	{12,100},
	{12,80},
	
};
void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINE_STRIP); 

    for (int i = 0; i < 5; i++) {

        glVertex2iv(front[i]); 
    }
    glEnd();
    glBegin(GL_LINE_STRIP); 
    for (int i = 0; i < 3; i++) {

        glVertex2iv(chhat[i]); 
    }
    glEnd();
    glBegin(GL_LINE_STRIP); 
    for (int i = 0; i < 4; i++) {

        glVertex2iv(door[i]); 
    }
	
    glEnd();
    glBegin(GL_LINE_LOOP); 
    for (int i = 0; i < 4; i++) {

        glVertex2iv(khidki[i]); 
    }
	
    glEnd();

    glFlush();

}

void init() {

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-250, 250, -250, 250); 

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
