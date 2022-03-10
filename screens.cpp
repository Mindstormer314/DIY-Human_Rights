#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <cmath>
#include "screens.h"

using namespace std;
using namespace sf;
using namespace screens;

void screens::menuscreen(RenderWindow &window, bool &clicking, int &activescreen, string &inputText){

    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int mousex = localPosition.x;    
    int mousey = localPosition.y;

    //Setup event managing system
    Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed){
                window.close();
            }
            // If left mouse button is pressed, notify
            if (event.type == Event::MouseButtonPressed){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    clicking = true;
                }
            }
            //If a mouse button is released, check where the mouse is and apply activescreen appropriately.
            if(event.type == Event::MouseButtonReleased){
                if (clicking){
                    activescreen = menubuttoncheck(mousex, mousey);
                }
                clicking = false;
            }
            if(event.type == Event::KeyPressed){
                switch(event.key.code){
                    case Keyboard::A:
                        inputText = inputText + "a";
                        break;
                    case Keyboard::B:
                        inputText = inputText + "b";
                        break;
                    case Keyboard::C:
                        inputText = inputText + "c";
                        break;
                    case Keyboard::D:
                        inputText = inputText + "d";
                        break;
                    case Keyboard::E:
                        inputText = inputText + "e";
                        break;
                    case Keyboard::F:
                        inputText = inputText + "f";
                        break;
                    case Keyboard::G:
                        inputText = inputText + "g";
                        break;
                    case Keyboard::H:
                        inputText = inputText + "h";
                        break;
                    case Keyboard::I:
                        inputText = inputText + "i";
                        break;
                    case Keyboard::J:
                        inputText = inputText + "j";
                        break;
                    case Keyboard::K:
                        inputText = inputText + "k";
                        break;
                    case Keyboard::L:
                        inputText = inputText + "l";
                        break;
                    case Keyboard::M:
                        inputText = inputText + "m";
                        break;
                    case Keyboard::N:
                        inputText = inputText + "n";
                        break;
                    case Keyboard::O:
                        inputText = inputText + "o";
                        break;
                    case Keyboard::P:
                        inputText = inputText + "p";
                        break;
                    case Keyboard::Q:
                        inputText = inputText + "q";
                        break;
                    case Keyboard::R:
                        inputText = inputText + "r";
                        break;
                    case Keyboard::S:
                        inputText = inputText + "s";
                        break;
                    case Keyboard::T:
                        inputText = inputText + "t";
                        break;
                    case Keyboard::U:
                        inputText = inputText + "u";
                        break;
                    case Keyboard::V:
                        inputText = inputText + "v";
                        break;
                    case Keyboard::W:
                        inputText = inputText + "w";
                        break;
                    case Keyboard::X:
                        inputText = inputText + "x";
                        break;
                    case Keyboard::Y:
                        inputText = inputText + "y";
                        break;
                    case Keyboard::Z:
                        inputText = inputText + "z";
                        break;
                }
            }
        }

    window.clear(Color(211, 224, 29));


    Font font;

    if (!font.loadFromFile("Bradley Hand Bold.ttf"))
    {
        window.close();
    }
    Font arial;

    if(!arial.loadFromFile("Arial.ttf")){
        window.close();
    }

    if(inputText == "yibalerbalisk"){
        activescreen = 4;
    }

    Text text;
    text.setFont(font);
    text.setString("Main Menu");
    text.setCharacterSize(220.f);
    text.setFillColor(Color(0, 0, 0));
    text.setPosition(100.f, 100.f);

    CircleShape StartButton(100.f);
    StartButton.setPosition(500.f, 700.f);
    StartButton.setFillColor(Color(255, 0, 0));
    StartButton.setOutlineThickness(1.f);
    StartButton.setOutlineColor(Color(0, 0, 0));

    Text StartText;
    StartText.setFont(arial);
    StartText.setString("Start");
    StartText.setCharacterSize(50.f);
    StartText.setFillColor(Color::Black);
    StartText.setPosition(540.f, 760.f);


    CircleShape InfoButton(100.f);
    InfoButton.setFillColor(Color(0, 255, 0));
    InfoButton.setPosition(900.f, 700.f);
    InfoButton.setOutlineColor(Color(0, 0, 0));
    InfoButton.setOutlineThickness(1.f);

    Text InfoText;
    InfoText.setFont(arial);
    InfoText.setString("Info");
    InfoText.setCharacterSize(50.f);
    InfoText.setFillColor(Color::Black);
    InfoText.setPosition(960.f, 760.f);

    
    CircleShape CreditButton(100.f);
    CreditButton.setFillColor(Color(100, 100, 255));
    CreditButton.setPosition(1300.f, 700.f);
    CreditButton.setOutlineColor(Color(0, 0, 0));
    CreditButton.setOutlineThickness(1.f);

    Text CreditText;
    CreditText.setFont(arial);
    CreditText.setString("Credits");
    CreditText.setCharacterSize(50.f);
    CreditText.setFillColor(Color::Black);
    CreditText.setPosition(1320.f, 760.f);

    switch(menubuttoncheck(mousex, mousey)){
        case 1:
            StartButton.setOutlineThickness(4.f);
            StartButton.setFillColor(Color(255, 100, 100));
            if(clicking){
                StartButton.setOutlineThickness(1.f);
                StartButton.setFillColor(Color(200, 0, 0));
            }
            break;
        case 2:
            InfoButton.setOutlineThickness(4.f);
            InfoButton.setFillColor(Color(100, 255, 100));
            if(clicking){
                InfoButton.setOutlineThickness(1.f);
                InfoButton.setFillColor(Color(0, 200, 0));
            }
            break;
        case 3:
            CreditButton.setOutlineThickness(4.f);
            CreditButton.setFillColor(Color(200, 200, 255));
            if(clicking){
                CreditButton.setOutlineThickness(1.f);
                CreditButton.setFillColor(Color(0, 0, 255));
            }
            break;
    }


    window.draw(StartButton);
    window.draw(InfoButton);
    window.draw(CreditButton);
    window.draw(text);
    window.draw(StartText);
    window.draw(InfoText);
    window.draw(CreditText);
}
int screens::menubuttoncheck(int mousex, int mousey){
    if (pow((mousex-600), 2)+pow((mousey-800), 2) <= 10000){
        return 1;
    }
    else if (pow((mousex - 1000), 2) + pow((mousey - 800), 2) <= 10000){
        return 2;
    }
    else if (pow((mousex - 1400), 2) + pow((mousey - 800), 2) <= 10000){
        return 3;
    }
    
    return 0;
}
void screens::startscreen(RenderWindow &window, bool &clicking, int &speed, int &mousex, int &mousey, int &ballx, int &bally, bool &quitclick, int &activescreen){
   // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed){
                window.close();
            }
            if (event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Right){
                    speed++;
                }
                if(event.key.code == Keyboard::Left){
                    speed--;
                }
            }
            if(event.type == Event::MouseButtonReleased){
                if(quitclick){
                    activescreen = 0;
                    speed = 0;
                    mousex = 0;
                    mousey = 0;
                    ballx = 0;
                    bally = 0;
                }
            }
            
            

        }
            
        if(speed < 0){
            speed = 0;
        }

        Vector2i localPosition = Mouse::getPosition(window); 
        mousex = localPosition.x;
        mousey = localPosition.y;


        int ballrelativex = mousex-ballx-70;
        int ballrelativey = mousey-bally-70;

        ballrelativex = ballrelativex*speed/1000;
        ballrelativey = ballrelativey*speed/1000;

        ballx+=ballrelativex;
        bally+=ballrelativey;

        

        



        // clear the window with black color
        window.clear(Color::Black);

        CircleShape circle(70.f);

        circle.setFillColor(Color(255, 255, 255));

        

        circle.setPosition(Vector2f(ballx, bally));

        Font font;
        if (!font.loadFromFile("Arial.ttf"))
        {
            window.close();
        }
        Font fancy;
        if(!font.loadFromFile("Bradley Hand Bold.ttf")){
            window.close();
        }

        Text text;
        
        text.setFont(font);
        text.setString(std::to_string(speed));
        text.setCharacterSize(40);
        text.setFillColor(Color::White);
        text.setPosition(300.f, 50.f);

        CircleShape button(50.f);

        button.setPosition(500.f, 100.f);
        button.setFillColor(Color(0, 255, 0));
        button.setOutlineThickness(5.f);
        button.setOutlineColor(Color::Red);

        Text buttontext;

        buttontext.setFont(font);        
        buttontext.setString("Button");
        buttontext.setCharacterSize(30);
        buttontext.setFillColor(Color(0, 0, 255));
        buttontext.setPosition(500.f, 130.f);

        if(pow((mousex-550), 2)+pow((mousey-150), 2) <= 2500){
            button.setFillColor(Color(150, 0, 0));
            if (Mouse::isButtonPressed(Mouse::Left)){
                button.setOutlineThickness(1.f);
                text.setString("Release = Menu");
                quitclick = true;
            }
        }


        window.draw(circle);
        window.draw(text);
        

        window.draw(button);
        window.draw(buttontext);
}
void screens::infoscreen(RenderWindow &window, bool &clicking, int &activescreen){
    
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int mousex = localPosition.x;    
    int mousey = localPosition.y;

    //Setup event managing system
    Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed){
                window.close();
            }
            // If left mouse button is pressed, notify
            if (event.type == Event::MouseButtonPressed){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    clicking = true;
                }
            }
            //If a mouse button is released, check where the mouse is and apply activescreen appropriately.
            if(event.type == Event::MouseButtonReleased){
                if (clicking){
                    activescreen = menubuttoncheck(mousex, mousey);
                }
                clicking = false;
            }
        }

    window.clear(Color(255, 100, 100));

    Font font;

    if (!font.loadFromFile("Bradley Hand Bold.ttf"))
    {
        window.close();
    }
    Font arial;

    if(!arial.loadFromFile("Arial.ttf")){
        window.close();
    }

    Text text;
    text.setFont(font);
    text.setString("Much Information");
    text.setCharacterSize(220.f);
    text.setFillColor(Color(0, 0, 0));
    text.setPosition(100.f, 100.f);

    Text hint;
    hint.setFont(font);
    hint.setString("Size up the Window");
    hint.setCharacterSize(15.f);
    hint.setFillColor(Color(255, 200, 200));

    CircleShape StartButton(100.f);
    StartButton.setPosition(500.f, 700.f);
    StartButton.setFillColor(Color(255, 0, 0));
    StartButton.setOutlineThickness(1.f);
    StartButton.setOutlineColor(Color(0, 0, 0));

    Text StartText;
    StartText.setFont(arial);
    StartText.setString("Start");
    StartText.setCharacterSize(50.f);
    StartText.setFillColor(Color::Black);
    StartText.setPosition(540.f, 760.f);


    CircleShape InfoButton(100.f);
    InfoButton.setFillColor(Color(0, 255, 0));
    InfoButton.setPosition(900.f, 700.f);
    InfoButton.setOutlineColor(Color(0, 0, 0));
    InfoButton.setOutlineThickness(1.f);

    Text InfoText;
    InfoText.setFont(arial);
    InfoText.setString("Info");
    InfoText.setCharacterSize(50.f);
    InfoText.setFillColor(Color::Black);
    InfoText.setPosition(960.f, 760.f);

    
    CircleShape CreditButton(100.f);
    CreditButton.setFillColor(Color(100, 100, 255));
    CreditButton.setPosition(1300.f, 700.f);
    CreditButton.setOutlineColor(Color(0, 0, 0));
    CreditButton.setOutlineThickness(1.f);

    Text CreditText;
    CreditText.setFont(arial);
    CreditText.setString("Credits");
    CreditText.setCharacterSize(50.f);
    CreditText.setFillColor(Color::Black);
    CreditText.setPosition(1320.f, 760.f);

    switch(menubuttoncheck(mousex, mousey)){
        case 1:
            StartButton.setOutlineThickness(4.f);
            StartButton.setFillColor(Color(255, 100, 100));
            if(clicking){
                StartButton.setOutlineThickness(1.f);
                StartButton.setFillColor(Color(200, 0, 0));
            }
            break;
        case 2:
            InfoButton.setOutlineThickness(4.f);
            InfoButton.setFillColor(Color(100, 255, 100));
            if(clicking){
                InfoButton.setOutlineThickness(1.f);
                InfoButton.setFillColor(Color(0, 200, 0));
            }
            break;
        case 3:
            CreditButton.setOutlineThickness(4.f);
            CreditButton.setFillColor(Color(200, 200, 255));
            if(clicking){
                CreditButton.setOutlineThickness(1.f);
                CreditButton.setFillColor(Color(0, 0, 255));
            }
            break;
    }


    window.draw(StartButton);
    window.draw(InfoButton);
    window.draw(CreditButton);
    window.draw(text);
    window.draw(StartText);
    window.draw(InfoText);
    window.draw(CreditText);
    window.draw(hint);
}
void screens::creditscreen(RenderWindow &window, bool &clicking, int &activescreen){
     
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int mousex = localPosition.x;    
    int mousey = localPosition.y;

    //Setup event managing system
    Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed){
                window.close();
            }
            // If left mouse button is pressed, notify
            if (event.type == Event::MouseButtonPressed){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    clicking = true;
                }
            }
            //If a mouse button is released, check where the mouse is and apply activescreen appropriately.
            if(event.type == Event::MouseButtonReleased){
                if (clicking){
                    activescreen = menubuttoncheck(mousex, mousey);
                }
                clicking = false;
            }
        }

    window.clear(Color(255, 100, 100));

    Font font;

    if (!font.loadFromFile("Bradley Hand Bold.ttf"))
    {
        window.close();
    }
    Font arial;

    if(!arial.loadFromFile("Arial.ttf")){
        window.close();
    }

    Text text;
    text.setFont(font);
    text.setString("Credits to Me!");
    text.setCharacterSize(220.f);
    text.setFillColor(Color(0, 0, 0));
    text.setPosition(100.f, 100.f);

    CircleShape StartButton(100.f);
    StartButton.setPosition(500.f, 700.f);
    StartButton.setFillColor(Color(255, 0, 0));
    StartButton.setOutlineThickness(1.f);
    StartButton.setOutlineColor(Color(0, 0, 0));

    Text StartText;
    StartText.setFont(arial);
    StartText.setString("Start");
    StartText.setCharacterSize(50.f);
    StartText.setFillColor(Color::Black);
    StartText.setPosition(540.f, 760.f);


    CircleShape InfoButton(100.f);
    InfoButton.setFillColor(Color(0, 255, 0));
    InfoButton.setPosition(900.f, 700.f);
    InfoButton.setOutlineColor(Color(0, 0, 0));
    InfoButton.setOutlineThickness(1.f);

    Text InfoText;
    InfoText.setFont(arial);
    InfoText.setString("Info");
    InfoText.setCharacterSize(50.f);
    InfoText.setFillColor(Color::Black);
    InfoText.setPosition(960.f, 760.f);

    
    CircleShape CreditButton(100.f);
    CreditButton.setFillColor(Color(100, 100, 255));
    CreditButton.setPosition(1300.f, 700.f);
    CreditButton.setOutlineColor(Color(0, 0, 0));
    CreditButton.setOutlineThickness(1.f);

    Text CreditText;
    CreditText.setFont(arial);
    CreditText.setString("Credits");
    CreditText.setCharacterSize(50.f);
    CreditText.setFillColor(Color::Black);
    CreditText.setPosition(1320.f, 760.f);

    switch(menubuttoncheck(mousex, mousey)){
        case 1:
            StartButton.setOutlineThickness(4.f);
            StartButton.setFillColor(Color(255, 100, 100));
            if(clicking){
                StartButton.setOutlineThickness(1.f);
                StartButton.setFillColor(Color(200, 0, 0));
            }
            break;
        case 2:
            InfoButton.setOutlineThickness(4.f);
            InfoButton.setFillColor(Color(100, 255, 100));
            if(clicking){
                InfoButton.setOutlineThickness(1.f);
                InfoButton.setFillColor(Color(0, 200, 0));
            }
            break;
        case 3:
            CreditButton.setOutlineThickness(4.f);
            CreditButton.setFillColor(Color(200, 200, 255));
            if(clicking){
                CreditButton.setOutlineThickness(1.f);
                CreditButton.setFillColor(Color(0, 0, 255));
            }
            break;
    }


    window.draw(StartButton);
    window.draw(InfoButton);
    window.draw(CreditButton);
    window.draw(text);
    window.draw(StartText);
    window.draw(InfoText);
    window.draw(CreditText);
}
void screens::eggscreen(sf::RenderWindow &window, bool &clicking, int &activescreen){

    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int mousex = localPosition.x;    
    int mousey = localPosition.y;

    //Setup event managing system
    Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed){
                window.close();
            }
            // If left mouse button is pressed, notify
            if (event.type == Event::MouseButtonPressed){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    clicking = true;
                }
            }
            //If a mouse button is released, check where the mouse is and apply activescreen appropriately.
            if(event.type == Event::MouseButtonReleased){
                if (clicking){
                    activescreen = menubuttoncheck(mousex, mousey);
                }
                clicking = false;
            }
        }

    window.clear(Color(255, 100, 100));

    Font font;

    if (!font.loadFromFile("Bradley Hand Bold.ttf"))
    {
        window.close();
    }
    Font arial;

    if(!arial.loadFromFile("Arial.ttf")){
        window.close();
    }

    Text text;
    text.setFont(font);
    text.setString("Surprise!");
    text.setCharacterSize(220.f);
    text.setFillColor(Color(0, 0, 0));
    text.setPosition(100.f, 100.f);

    CircleShape StartButton(100.f);
    StartButton.setPosition(500.f, 700.f);
    StartButton.setFillColor(Color(255, 0, 0));
    StartButton.setOutlineThickness(1.f);
    StartButton.setOutlineColor(Color(0, 0, 0));

    Text StartText;
    StartText.setFont(arial);
    StartText.setString("Start");
    StartText.setCharacterSize(50.f);
    StartText.setFillColor(Color::Black);
    StartText.setPosition(540.f, 760.f);


    CircleShape InfoButton(100.f);
    InfoButton.setFillColor(Color(0, 255, 0));
    InfoButton.setPosition(900.f, 700.f);
    InfoButton.setOutlineColor(Color(0, 0, 0));
    InfoButton.setOutlineThickness(1.f);

    Text InfoText;
    InfoText.setFont(arial);
    InfoText.setString("Info");
    InfoText.setCharacterSize(50.f);
    InfoText.setFillColor(Color::Black);
    InfoText.setPosition(960.f, 760.f);

    
    CircleShape CreditButton(100.f);
    CreditButton.setFillColor(Color(100, 100, 255));
    CreditButton.setPosition(1300.f, 700.f);
    CreditButton.setOutlineColor(Color(0, 0, 0));
    CreditButton.setOutlineThickness(1.f);

    Text CreditText;
    CreditText.setFont(arial);
    CreditText.setString("Credits");
    CreditText.setCharacterSize(50.f);
    CreditText.setFillColor(Color::Black);
    CreditText.setPosition(1320.f, 760.f);

    switch(menubuttoncheck(mousex, mousey)){
        case 1:
            StartButton.setOutlineThickness(4.f);
            StartButton.setFillColor(Color(255, 100, 100));
            if(clicking){
                StartButton.setOutlineThickness(1.f);
                StartButton.setFillColor(Color(200, 0, 0));
            }
            break;
        case 2:
            InfoButton.setOutlineThickness(4.f);
            InfoButton.setFillColor(Color(100, 255, 100));
            if(clicking){
                InfoButton.setOutlineThickness(1.f);
                InfoButton.setFillColor(Color(0, 200, 0));
            }
            break;
        case 3:
            CreditButton.setOutlineThickness(4.f);
            CreditButton.setFillColor(Color(200, 200, 255));
            if(clicking){
                CreditButton.setOutlineThickness(1.f);
                CreditButton.setFillColor(Color(0, 0, 255));
            }
            break;
    }


    window.draw(StartButton);
    window.draw(InfoButton);
    window.draw(CreditButton);
    window.draw(text);
    window.draw(StartText);
    window.draw(InfoText);
    window.draw(CreditText);
}

