#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;


int xstart,ystart,xend,yend;

void draw(int x1,int y1,int x2,int y2)
{
    int dx = x2-x1;
    int dy = y2-y1;
    
    int p = (2*dy)-dx;
    glBegin(GL_POINTS); 
    int y = y1;
    for(int x = x1; x<=x2; x++)
    {
    	if(p < 0)
    	{
    		glVertex2i(x+1,y);
    		p = p + (2*dy);
    	}else{
    		glVertex2i(x+1,y+1);
    		p = p + (2*dy) - (2*dx);
    		y++;
    	}
    }
    
    glEnd();
    
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    
   
    draw(xstart,ystart,xend,yend);
    

    glFlush();

}

void init() {

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-200, 200, -200, 200); 

}

int main(int argc, char** argv) {
   
    cout<<"enter the coordinates of start and end points\n";
    cin >> xstart >> ystart >> xend >> yend;

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("Line Drawing using Points Array");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
