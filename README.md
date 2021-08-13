# A* PathFinding 
This project is built in C++ and uses GL and the X server to help display since this was built on linux.

Code is Mostly from the [OpenGL Wiki](https://www.khronos.org/opengl/wiki/Programming_OpenGL_in_Linux:_GLX_and_Xlib)
with some tinkering here and there

To compile do
```sh
gcc -o main main.cpp -lX11 -lGL -lGLU
```