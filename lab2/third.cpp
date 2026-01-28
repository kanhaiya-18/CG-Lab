#include <GL/glut.h>

int p1[] = {0,50};

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINE_STRIP); 
    int x = 20;
    int y = 0;
    /*for (int i = 0; i < 4; i++) {

        glVertex2iv(points[i]); 
    }*/
    while(p1[0] <= 200)
    {
    	if(y % 2 == 0)
    	p1[1] = 50;
    	else 
    	p1[1] = 70;
    	
    	glVertex2iv(p1);	
    	p1[0] += x;
    	y++;
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
