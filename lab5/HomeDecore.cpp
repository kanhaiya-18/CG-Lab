#include <GL/glut.h>
#include <cmath>

int front[5][2] = {
    {-50,0}, {-50,120}, {50,120}, {50,0}, {-50,0}
};

int chhat[3][2] = {
    {-50,120}, {0,180}, {50,120}
};

int door[4][2] = {
    {-12,0}, {-12,50}, {12,50}, {12,0}
};

int khidki[4][2] = {
    {-12,80}, {-12,100}, {12,100}, {12,80}
};

void drawHome(int x, int y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 5; i++)
        glVertex2iv(front[i]);
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 3; i++)
        glVertex2iv(chhat[i]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 4; i++)
        glVertex2iv(door[i]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 4; i++)
        glVertex2iv(khidki[i]);
    glEnd();

    glPopMatrix();
}

void plotPoints(int xc, int yc, int x, int y)
{
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

void drawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    glBegin(GL_POINTS);

    while (x <= y)
    {
        plotPoints(xc, yc, x, y);
        x++;

        if (p < 0)
            p = p + 2 * x + 1;
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }

    glEnd();
}

void drawFence()
{
    glBegin(GL_LINES);

    for (int i = -450; i <= 450; i += 30)
    {
        glVertex2i(i, -120);
        glVertex2i(i, -60);
    }

    glVertex2i(-450, -90);
    glVertex2i(450, -90);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    drawHome(-250, -100);
    drawHome(0, -100);
    drawHome(250, -100);

    drawFence();

    glColor3f(1, 1, 0);
    drawCircle(300, 300, 70);

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Three Houses with Fence and Sun");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

