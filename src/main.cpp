#include <iostream>
#include "SFML/Graphics.hpp"
#include "Props.hpp"
#include "Game.hpp"
using namespace sf;


int main(){
    Clock tile_drop_speed;
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
                        game.MoveRight();
                    else if(Keyboard::isKeyPressed(Keyboard::Left))
                        game.MoveLeft();
                    else if(Keyboard::isKeyPressed(Keyboard::Space))
                        game.RotateTile();
                    else if(Keyboard::isKeyPressed(Keyboard::Down))
                        game.MoveToLowest();
                    break;
                }
                default:
                    break;
            }
        }
        if(tile_drop_speed.getElapsedTime().asMilliseconds() >= 550)
        {
            tile_drop_speed.restart();
            game.LowerTile();
        }
        game.Run();
        window.clear();
        game.Draw(window);
        window.display();
    }
    return 0;
}
