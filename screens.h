#ifndef TETRIS_BLOCKS_H_INCLUDED
#define TETRIS_BLOCKS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace screens{
    void menuscreen(sf::RenderWindow &window, bool &clicking, int &activescreen, string &inputText);
    void infoscreen(sf::RenderWindow &window, bool &clicking, int &activescreen);
    void startscreen(sf::RenderWindow &window, bool &clicking, int &speed, int &mousex, int &mousey, int &ballx, int &bally, bool &quitclick, int &activescreen);
    void creditscreen(sf::RenderWindow &window, bool &clicking, int &activescreen);
    void eggscreen(sf::RenderWindow &window, bool &clicking, int &activescreen);
    int menubuttoncheck(int mousex, int mousey); // 1: Start  2:Info  3:Credits
}


#endif // TETRIS_BLOCKS_H_INCLUDED
