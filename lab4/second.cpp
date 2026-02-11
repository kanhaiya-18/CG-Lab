#include <GL/glut.h>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int xstart,ystart,radius;

void drawCircle(int x1,int y1,int radius)
{
    int pk = 1 - radius;
    glBegin(GL_POINTS); 
    int yk = radius;
    int xk = 0;
    vector<pair<int,int>>points;
    //first octane
    while(xk < yk)
    {
    	if(pk < 0)
    	{
    		glVertex2i(round(x1+xk+1),round(y1+yk));  
    		pk = pk+1+(2*(xk+1));
    		points.push_back({xk+1,yk});
    		cout<<"("<<xk+1+x1<<","<<yk+y1<<")"<<endl;
    	}
    	else{
    		glVertex2i(round(xk+1+x1),round(yk-1+y1));  
    		pk = pk+1+(2*(xk+1))-(2*(yk-1));
    		points.push_back({xk+1,yk-1});
    		cout<<"("<<xk+1+x1<<","<<yk-1+y1<<")"<<endl;
    		yk--;
    	}
    	xk++;
    }
    //second octane
    int size = points.size();
    for(int i=0; i<size; i++)
    {
    	glVertex2i(round(points[i].second+x1),round(points[i].first+y1));
    	cout<<"("<<points[i].second+y1<<","<<points[i].first+x1<<")"<<endl;  
    	points.push_back({points[i].second,points[i].first});
    }
    //second quadrant
    for(int i=0; i<points.size(); i++)
    {
    	glVertex2i(round(-points[i].first+x1),round(points[i].second+y1));
    	cout<<"("<<-points[i].first+x1<<","<<points[i].second+y1<<")"<<endl;
    }
    //third quadrant
    for(int i=0; i<points.size(); i++)
    {
    	glVertex2i(round(-points[i].first+x1),round(-points[i].second+y1));
    	cout<<"("<<-points[i].first+x1<<","<<-points[i].second+y1<<")"<<endl;
    }
    //fourth quadrant
    for(int i=0; i<points.size(); i++)
    {
    	glVertex2i(round(points[i].first+x1),round(-points[i].second+y1));
    	cout<<"("<<points[i].first+x1<<","<<-points[i].second+y1<<")"<<endl;
    }
    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    
    drawCircle(xstart,ystart,radius);

    glFlush();

}

void init() {

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-250, 250, -250, 250); 

}

int main(int argc, char** argv) {
   
    cout<<"enter the coordinates of start point and radius \n";
    cin >> xstart >> ystart >> radius;

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("circle drawing");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
