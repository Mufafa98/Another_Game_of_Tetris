#include <iostream>
#include "SFML/Graphics.hpp"
#include "Props.hpp"
#include "Game.hpp"
using namespace sf;


int main(){
    Game game;
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Another_Game_of_Tetris", Style::Close | Style::Titlebar);
    window.setVerticalSyncEnabled(true);
    while(window.isOpen()){
        Event window_event;
        while(window.pollEvent(window_event)){
            switch (window_event.type){
                case Event::Closed:
                {
                    window.close();
                    break;
                }
                case Event::KeyPressed:
                {
                    if(Keyboard::isKeyPressed(Keyboard::Right))
                        game.NewTile();
                    else if(Keyboard::isKeyPressed(Keyboard::Space))
                        game.RotateTile();
                    break;
                }
                default:
                    break;
            }
        }
        window.clear();
        game.Draw(window);
        window.display();
    }
    return 0;
}
