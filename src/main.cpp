/*
========================================
Code: Michael Crawford           
Program: AI pathfinding visualization
ProgramName: A* Pathfinding

TO COMPILE USE 
! g++ -o main main.cpp -lglut -lGL -lGLU
========================================
*/
#include "grid.h"
#include "drawgrid.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <math.h>
#include <SFML/Audio.hpp>


#define COLUMUS 40
#define ROWS 40



void init()
{
    initGrid(COLUMUS, ROWS);
}


int main()
{
    sf::Window* window(sf::VideoMode(800, 600), "Test");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }


    return 0;
}