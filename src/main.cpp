/*
========================================
Code: OpenGL wiki and Michael Crawford             https://www.khronos.org/opengl/wiki/Programming_OpenGL_in_Linux:_GLX_and_Xlib
Program: AI pathfinding visualization
ProgramName: A* Pathfinding

TO COMPILE USE 
! gcc -o main main.cpp -lX11 -lGL -lGLU
========================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

// variables for completness
Display *dpy;
Window root;
GLint att[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
XVisualInfo *vi;
Colormap cmap;
XSetWindowAttributes swa;
Window win;
GLXContext glc;
XWindowAttributes gwa;
XEvent xev;


// drawing the actual quad
void DrawAQuad()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1., 1., -1., 1., 1., 20.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);
    
    // Drawing shapes
    glBegin(GL_LINES);
    glVertex3f(.25,0.25, 0);
    glVertex3f(.75,.75, 0); //! the vertex to draw a line
    
    
    
    glEnd();

    // Colors
    glColor3f(1., 0., 0.);  //! The color to define the quad. Goes it goes RGB for color
    glColor3f(0., 1., 0.);
    
    

}

int main(int argc, char *argv[])
{

    dpy = XOpenDisplay(NULL); 

    if (dpy == NULL) // if the X server is not working we print null to show that it isn't working
    {
        printf("\n\tcannot connect to X server\n\n");
        exit(0);
    }

    root = DefaultRootWindow(dpy);

    vi = glXChooseVisual(dpy, 0, att);

    if (vi == NULL) //if visual isn't working then print null to terminal
    {
        printf("\n\tno appropriate visual found\n\n");
        exit(0);
    }
    else
    {
        printf("\n\tvisual %p selected\n", (void *)vi->visualid); /* %p creates hexadecimal output like in glxinfo */
    }
    cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;
    win = XCreateWindow(dpy, root, 0, 0, 600, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
    XMapWindow(dpy, win);
    XStoreName(dpy, win, "A*PathFinding in C"); //the main window and the title for it.

    glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);

    glEnable(GL_DEPTH_TEST);

    while (1)
    {
        XNextEvent(dpy, &xev);

        if (xev.type == Expose)
        {
            XGetWindowAttributes(dpy, win, &gwa);
            glViewport(0, 0, gwa.width, gwa.height);
            DrawAQuad();
            glXSwapBuffers(dpy, win);
        }
    }
} /* this closes while(1) { */
 /* this is the } which closes int main(int argc, char *argv[]) { */
