#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <vector>
#include <GL/glu.h>
#include "drawgrid.h"

int gridX, gridY;

void initGrid(int x, int y)
{
    gridX = x;
    gridY = y;
};

void unit(int x, int y)
{
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y );
        glVertex2f(x+1,y );
        glVertex2f(x+1,y+1 );
        glVertex2f(x,y+1);
    glEnd();
}

void drawGrid()
{
    unit(20, 20);
}

