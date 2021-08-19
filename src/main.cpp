/*
========================================
Code: Michael Crawford           
Program: AI pathfinding visualization
ProgramName: A* Pathfinding

TO COMPILE USE 
! g++ -o main main.cpp -lsfml-graphics -lsfml-window -lsfml-system
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
    sf::RenderWindow window(sf::VideoMode(800, 640), "Tilemap");

    // define the level with an array of tile indices
    const int level[] =
    { // 
    
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("1tileset.png", sf::Vector2u(32, 32), level, 32, 16))
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
        while (1)
        {
            window.clear();
            window.draw(map);
            window.display();
        }
        // draw the map
        //window.clear();
        //window.draw(map);
        //window.display();
    }

    return 0;
}