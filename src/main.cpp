/*
========================================
Code: Michael Crawford           
Program: AI pathfinding visualization
ProgramName: A* Pathfinding

TO COMPILE USE 
! g++ -o main main.cpp -lglut -lGL -lGLU
========================================
*/
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "grid.h"
#include "drawgrid.h"


#define COLUMUS 40
#define ROWS 40



void init()
{
    initGrid(COLUMUS, ROWS);
}


// drawing the actual line
void Grid()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawGrid();
    glEnable(GL_LINE_SMOOTH);
    glOrtho(-1., 1., COLUMUS, 1., 1., ROWS);
}

int main(int argc, char *argv[])
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
   // glutInitWindowSize(500, 500);
   // glutInitWindowPosition(100, 100);
    glutCreateWindow("A*PathFinding");
    glutDisplayFunc(Grid);
    glutMainLoop();

}
/* this closes while(1) { */
 /* this is the } which closes int main(int argc, char *argv[]) { */
