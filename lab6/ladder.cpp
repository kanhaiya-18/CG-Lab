#include <GL/glut.h>
#include <cmath>

float angle = 30.0 * 3.14159265 / 180.0;

float x1 = 0, y1_coord = 0;
float x2 = 0, y2_coord = 5;

float tx = 3, ty = 2;

void drawAxis(){
	glColor3f(0.5, 0.5, 0.5);
	glLineWidth(1.0);
	glBegin(GL_LINES);
		glVertex2f(-10, 0);
		glVertex2f(10, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0, 10);
		glVertex2f(0, -10);
	glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
    glLineWidth(3.0);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex2f(x1, y1_coord);
        glVertex2f(x2, y2_coord);
    glEnd();


    float rx = x2 * cos(angle) - y2_coord * sin(angle);
    float ry = x2 * sin(angle) + y2_coord * cos(angle);

    float new_x1 = x1;
    float new_y1 = y1_coord;
    float new_x2 = rx;
    float new_y2 = ry;

	glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        glVertex2f(new_x1, new_y1);
        glVertex2f(new_x2, new_y2);
    glEnd();
	
	new_x1 += tx;	new_x2 += tx;
	new_y1 += ty;	new_y2 += ty;
	
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(new_x1, new_y1);
        glVertex2f(new_x2, new_y2);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(-10, 10, -10, 10);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Ladder");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
