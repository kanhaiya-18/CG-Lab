#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;


int xstart = 10 ,ystart = 0,xend = 150,yend = 0;

void drawLine(int x1,int y1,int x2,int y2)
{
    int cnt = 1;
    int dx = x2-x1;
    int dy = y2-y1;
    
    int p = (2*dy)-dx;
    glBegin(GL_POINTS); 
    int y = y1;
    for(int x = x1; x<=x2; x += 1)
    {
    	if(p < 0)
    	{	
    		if(cnt % 6 < 4)
    		glVertex2i(x+1,y);
    		p = p + (2*dy);
    	}else{
    		if(cnt % 6 < 4)
    		glVertex2i(x+1,y+1);
    		p = p + (2*dy) - (2*dx);
    		y += 1;
    	}
    	cnt++;
    }
    
    glEnd();
    
}

void drawDot(int x1,int y1,int x2,int y2)
{
    int dx = x2-x1;
    int dy = y2-y1;
    
    int p = (2*dy)-dx;
    glBegin(GL_POINTS); 
    float y = y1;
    for(float x = x1; x<=x2; x += 0.5)
    {
    	if(p < 0)
    	{
    		glVertex2i(x+1,y);
    		p = p + (2*dy);
    	}else{
    		glVertex2i(x+1,y+1);
    		p = p + (2*dy) - (2*dx);
    		y += 0.5;
    	}
    }
    
    glEnd();
    
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    
   
    drawLine(xstart,ystart,xend,yend);
    drawDot(xstart,ystart+10,xend,yend+10);

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

    glutInitWindowSize(500, 500);

    glutCreateWindow("Line Drawing using Points Array");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
