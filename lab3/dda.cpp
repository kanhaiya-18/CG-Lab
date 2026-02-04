#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;


int xstart,ystart,xend,yend;

void drawy(int x1,int y1,int x2,int y2,float slop)
{
    int step = x1;
    int limit = x2;
    glBegin(GL_POINTS); 
    
    float prevx = x1, prevy = y1;
    for(; step <= limit; step++)
    {
    	float temp = prevy + slop;
    	//glVertex2iv(prevx,prevy);
    	glVertex2i(round(step),round(temp));  
    	cout<<round(step)<<","<<round(temp)<<endl;
    	prevx = step;
    	prevy = temp;
    }
    
    glEnd();
}
void drawx(int x1,int y1,int x2,int y2,float slop)
{
    int step = y1;
    int limit = y2;
    glBegin(GL_POINTS); 
    
    float prevx = x1, prevy = y1;
    float move = 1/(float)slop;
    for(; step <= limit; step++)
    {
    	float temp = prevx + move;
    	//glVertex2iv(prevx,prevy);
    	glVertex2i(round(temp),round(step));  
    	cout<<round(temp)<<","<<round(step)<<endl;
    	prevx = temp;
    	prevy = step;
    }
    glEnd();
}
void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    int dx = xend-xstart;
    int dy = yend-ystart;
    float slop = (float)dy/dx;
    if(abs(slop) <= 1)
    {
    	if(xstart > xend)
    	{
    		swap(xstart,xend);
    		swap(ystart,yend);
    	}
    	drawy(xstart,ystart,xend,yend,slop);
    }
    else
    {
    	if(ystart > yend)
    	{
    		swap(xstart,xend);
    		swap(ystart,yend);
    	}
    	drawx(xstart,ystart,xend,yend,slop);
    }
    
    

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
