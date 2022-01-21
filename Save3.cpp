#include<iostream>
#include "SFML/Graphics.hpp"
using namespace std;

enum DIRECTIONS { LEFT, RIGHT, UP, DOWN }; //left is 0, right is 1, up is 2, down is 3

int main() {
	//game set up (you'll need these lines in every game)
    sf::RenderWindow screen(sf::VideoMode(1050,1000), "pACmAN"); //set up screen
    sf::Event event; //set up event queue
    sf::Clock clock; //set up the clock (needed for game timing)
    const float FPS = 60.0f; //FPS
    screen.setFramerateLimit(FPS); //set FPS

    //load in images
    sf::Texture brick;
    brick.loadFromFile("brick.png");
    sf::Sprite wall;
    wall.setTexture(brick);

    sf::Texture stone;
    stone.loadFromFile("stone.png");
    sf::Sprite shelf;
    shelf.setTexture(stone);

    sf::Texture pacman;
    pacman.loadFromFile("pac.png");
    sf::IntRect pac(0, 0, 50, 50);
    sf::Sprite playerImg(pacman, pac);
    int ticker = 0;
    int frameNum = 0;
    int rowNum = 0;

    int map[20][21] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,1,
        1,1,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,1,0,2,0,0,0,0,2,2,2,2,2,0,0,0,0,0,2,1,1,
        1,0,0,2,2,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,1,
        1,0,0,0,2,2,2,0,0,0,2,0,0,0,0,2,2,2,2,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
        1,0,0,0,0,2,2,2,0,2,2,2,0,2,2,2,0,0,0,0,1,
        1,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,2,2,0,2,0,2,2,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1

    };

    //player setup
    int xpos = 500;
    int ypos = 500;
    int vx = 0;
    int vy = 0;
    playerImg.setPosition(xpos, ypos); //top left "corner" of circle (not center!)
    bool keys[] = { false, false, false, false };

    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (screen.isOpen()) {//keep window open until user shuts it down

        while (screen.pollEvent(event)) { //look for events-----------------------

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)//sususususususususususususususu
                screen.close();

            //KEYBOARD INPUT 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                keys[LEFT] = true;
            }
            else keys[LEFT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                keys[RIGHT] = true;
            }
            else keys[RIGHT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                keys[UP] = true;
            }
            else keys[UP] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                keys[DOWN] = true;
            }
            else keys[DOWN] = false;

        }//end event loop---------------------------------------------------------------

          //move Mr. Pac
        if (keys[LEFT] == true) {
            vx = -5;
     
        }
           
        else if (keys[RIGHT] == true) {
            vx = 5;

        }
           
        else if (keys[UP] == true) {
            vy = -5;

        }

        else if (keys[DOWN] == true) {
            vy = 5;

        }

        else {
            vx = 0;
            vy = 0;
        }
        xpos += vx;
        ypos += vy;
        playerImg.setPosition(xpos, ypos);

                //render section-----------------------------------------
        screen.clear(); //wipes screen, without this things smear
        for (int rows = 0; rows<20; rows++)
            for (int cols = 0; cols < 21; cols++) {
                if (map[rows][cols] == 1) {
                    wall.setPosition(cols*50, rows*50);
                    screen.draw(wall);
                }
                if (map[rows][cols] == 2) {
                    shelf.setPosition(cols * 50, rows * 50);
                    screen.draw(shelf);
                }
            }
        screen.draw(playerImg); //draw player
        screen.display(); //flips memory drawings onto screen

    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
} //end of main
