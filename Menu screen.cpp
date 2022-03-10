#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <cmath>
#include "screens.cpp"

using namespace sf;
using namespace std;
using namespace screens;

int main()
{
    // create the window
    RenderWindow window(VideoMode(2000, 1400), "                                                                                                               Game                                                                                                                                                                                                                                    type: yibalerbalisk");
    window.setFramerateLimit(30);
    window.setKeyRepeatEnabled(false);
    int activescreen = 0; //initializes in main menu mode.

    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int mousex = localPosition.x;
    int mousey = localPosition.y;
    bool clicking = false;
    int ballx = 0;
    int bally = 0;
    int speed = 0;
    bool quitclick = false;
    string inputText = "";

    // run the program as long as the window is open
    while (window.isOpen())
    {
        //Update mouse position
        // Vector2i localPosition = Mouse::getPosition(window);
        // int mousex = localPosition.x;
        // int mousey = localPosition.y;

        // check all the window's events that were triggered since the last iteration of the loop
        // Event event;
        // while (window.pollEvent(event))
        // {
        //     // "close requested" event: we close the window
        //     if (event.type == Event::Closed){
        //         window.close();
        //     }
        //     // If left mouse button is pressed, notify
        //     if (event.type == Event::MouseButtonPressed){
        //         if (Mouse::isButtonPressed(Mouse::Left)){
        //             clicking = true;
        //         }
        //     }
        //     //If a mouse button is released, check where the mouse is and apply activescreen appropriately.
        //     if(event.type == Event::MouseButtonReleased){
        //         if (clicking){
        //             activescreen = menubuttoncheck(mousex, mousey);
        //         }
        //         clicking = false;
        //     }
        // }




        switch(activescreen){
            case 0:
                screens::menuscreen(window, clicking, activescreen, inputText);
                break;
            case 1:
                screens::startscreen(window, clicking, speed, mousex, mousey, ballx, bally, quitclick, activescreen);
                break;
            case 2:
                screens::infoscreen(window, clicking, activescreen);
                break;
            case 3:
                screens::creditscreen(window, clicking, activescreen);
                break;
            case 4:
                screens::eggscreen(window, clicking, activescreen);
                break;
            default:
                screens::menuscreen(window, clicking, activescreen, inputText);
                break;
        }
        window.display();
    }

    return 0;
}