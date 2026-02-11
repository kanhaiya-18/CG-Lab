 #include <GL/glut.h>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;


void drawCircle(int x1,int y1,int radius)
{
    int pk = 1 - radius;
    glBegin(GL_POINTS); 
    int yk = radius;
    int xk = 0;
    vector<pair<int,int>>points;
    //first octane
    while(xk <= yk)
    {
    	if(pk < 0)
    	{
    		glVertex2i(x1+xk+1,y1+yk);  
    		pk = pk+1+(2*(xk+1));
    		points.push_back({xk+1,yk});
    		//cout<<"("<<xk+1+x1<<","<<yk+y1<<")"<<endl;
    	}
    	else{
    		glVertex2i(xk+1+x1,yk-1+y1);  
    		pk = pk+1+(2*(xk+1))-(2*(yk-1));
    		points.push_back({xk+1,yk-1});
    		//cout<<"("<<xk+1+x1<<","<<yk-1+y1<<")"<<endl;
    		yk--;
    	}
    	xk++;
    }
    //second octane
    int size = points.size();
    for(int i=0; i<size; i++)
    {
    	glVertex2i(points[i].second+x1,points[i].first+y1);
    	//cout<<"("<<points[i].second+y1<<","<<points[i].first+x1<<")"<<endl;  
    	points.push_back({points[i].second,points[i].first});
    }
    //second quadrant
    for(int i=0; i<points.size(); i++)
    {
    	glVertex2i(-points[i].first+x1,points[i].second+y1);
    	//cout<<"("<<-points[i].first+x1<<","<<points[i].second+y1<<")"<<endl;
    }
    //third quadrant
    for(int i=0; i<points.size(); i++)
    {
    	glVertex2i(-points[i].first+x1,-points[i].second+y1);
    	//cout<<"("<<-points[i].first+x1<<","<<-points[i].second+y1<<")"<<endl;
    }
    //fourth quadrant
    for(int i=0; i<points.size(); i++)
    {
    	glVertex2i(points[i].first+x1,-points[i].second+y1);
    	//cout<<"("<<points[i].first+x1<<","<<-points[i].second+y1<<")"<<endl;
    }
    glEnd();
}
void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5);
    
    drawCircle(-60,0,20);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-10,0,20);
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(40,0,20);
    glColor3f(1.0, 1.0, 0.0);
    drawCircle(-30,-20,20);
    glColor3f(0.0, 1.0, 0.0);
    drawCircle(15,-20,20);

    glFlush();

}

void init() {

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-100, 100, -100, 100); 

}

int main(int argc, char** argv) {
   

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("circle drawing");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
