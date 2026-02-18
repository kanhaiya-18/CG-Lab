#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int xstart,ystart,radiusx,radiusy;
void plotSym(int x,int y)
{
	glVertex2i(round(xstart+x),round(y+ystart)); 
	glVertex2i(round(xstart-x),round(y+ystart)); 
	glVertex2i(round(-x+xstart),round(-y+ystart)); 
	glVertex2i(round(xstart+x),round(-y+ystart)); 
	
}

void drawR2(int x1,int y1,int rx,int ry)
{
    float pk = (ry*ry)*(x1+0.5)*(x1+0.5) + (rx*rx)*(y1-1)*(y1-1)-(ry*ry)*(rx*rx);
    glBegin(GL_POINTS); 
    int yk = y1;
    int xk = x1;
    while(yk >= 0)
    {
    	if(pk <= 0)
    	{
    		plotSym(xk+1,yk-1);
    		pk = pk+(2*ry*ry*(xk+1))+(rx*rx)-(2*rx*rx*(yk-1));
    		cout<<"("<<xk+1<<","<<yk<<")"<<endl;
    		xk++;
    		
    		//glVertex2i(round(xk+1),round(yk-1)); 
    	}
    	else{
    		plotSym(xk,yk-1);
    		//glVertex2i(round(xk),round(yk-1));  
    		pk = pk-(2*rx*rx*(yk-1))+(ry*ry)+(rx*rx);
    		cout<<"("<<xk+1<<","<<yk-1<<")"<<endl;
    	}
    	yk--;
    }
    glEnd();
}


void drawR1(int x1,int y1,int rx,int ry)
{
    float pk = (ry*ry) -(rx*rx)*ry+(0.25*rx*rx);
    glBegin(GL_POINTS); 
    int yk = ry;
    int xk = 0;
    
    while(ry*ry*xk < rx*rx*yk)
    {
    	if(pk < 0)
    	{
    		plotSym(xk+1,yk); 
    		pk = pk+(2*ry*ry*(xk+1))+(ry*ry);
    		cout<<"("<<xk+1<<","<<yk<<")"<<endl;
    	}
    	else{
    		//glVertex2i(round(xk+1),round(yk-1)); 
    		plotSym(xk+1,yk-1);  
    		pk = pk+(2*ry*ry*(xk+1))-(2*rx*rx*(yk-1))+(ry*ry);
    		cout<<"("<<xk+1<<","<<yk-1<<")"<<endl;
    		yk--;
    	}
    	xk++;
    }
    drawR2(xk,yk,rx,ry);
   
    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    drawR1(xstart,ystart,radiusx,radiusy);

    

    glFlush();

}

void init() {

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-100, 100, -100, 100); 

}

int main(int argc, char** argv) {
   
    cout<<"enter the coordinates of start point and both the radius \n";
    cin >> xstart >> ystart >> radiusx >> radiusy;

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("ellipse drawing");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
