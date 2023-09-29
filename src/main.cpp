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
                    if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
                        game.MoveRight();
                    else if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
                        game.MoveLeft();
                    else if(Keyboard::isKeyPressed(Keyboard::Space))
                        game.RotateTile();
                    else if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
                        game.ModifyTileSpeed(70);
                    else if(Keyboard::isKeyPressed(Keyboard::Enter))
                        game.MoveToLowest();
                    else if(game.CheckLose() && Keyboard::isKeyPressed(Keyboard::Q))
                        window.close();
                    else if(game.CheckLose() && Keyboard::isKeyPressed(Keyboard::R))
                        game.ResetGame();
                    break;
                }
                default:
                    break;
            }
        }
        if(game.TimerNeedRestart())
            tile_drop_speed.restart();
        game.Run(tile_drop_speed.getElapsedTime());
        window.clear();
        game.Draw(window);
        window.display();
    }
    return 0;
}
