/*
========================================
Code: Michael Crawford           
Program: AI pathfinding visualization
ProgramName: A* Pathfinding

TO COMPILE USE 
! g++ -o main main.cpp -lglut -lGL -lGLU
========================================
*/
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <math.h>
#include <SFML/Audio.hpp>
#include "grid.hpp"



#define COLUMUS 40
#define ROWS 40


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // define the level with an array of tile indices
    const int level[] =
    { // 0 is grass, 1 is water, 2 is trees, 3 is stone
        0,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,
        3,3,3,3,3,3,3,3,3,
        4,4,4,4,4,4,4,4,4,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // draw the map
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}