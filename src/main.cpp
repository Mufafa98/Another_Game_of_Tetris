#include <iostream>
#include "SFML/Graphics.hpp"
#include "Props.hpp"
#include "Game.hpp"
using namespace sf;


int main(){
    Clock tile_drop_speed;
    Clock text_box_parity;
    Game game;
    std::cout<<sizeof(game);
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
                    if(game.CheckLose() && game.CheckInputNickname() && !game.HasScoreBeenSaved())
                    {
                        switch (window_event.key.code)
                        {
                            case Keyboard::BackSpace:
                            {
                                game.RemFromNickname();
                                break;
                            }
                            case Keyboard::Enter:
                            {
                                game.SaveScore();
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    if(game.CheckLose())
                    {
                        switch (window_event.key.code)
                        {
                            case Keyboard::Q:
                            {
                                window.close();
                                break;
                            }
                            case Keyboard::R:
                            {
                                game.ResetGame();
                                break;
                            }
                            case Keyboard::S:
                            {
                                game.InputNickname();
                                break;
                            }
                            default:
                                break;
                        }     
                    }
                    else
                    {
                        switch (window_event.key.code)
                        {
                            case Keyboard::Space:
                            {
                                game.RotateTile();
                                break;
                            }
                            case Keyboard::Enter:
                            {
                                game.MoveToLowest();
                                break;
                            }
                            case Keyboard::P:
                            {
                                game.PauseGame();
                                break;
                            }
                            case Keyboard::A:
                            {
                                game.MoveLeft();
                                break;
                            }
                            case Keyboard::S:
                            {
                                game.ModifyTileSpeed(70);
                                break;
                            }
                            case Keyboard::D:
                            {
                                game.MoveRight();
                                break;
                            }
                            case Keyboard::Left:
                            {
                                game.MoveLeft();
                                break;
                            }
                            case Keyboard::Down:
                            {
                                game.ModifyTileSpeed(70);
                                break;
                            }
                            case Keyboard::Right:
                            {
                                game.MoveRight();
                                break;
                            }
                            default:
                                break;
                        }                         
                    }

                    break;
                }
                case Event::TextEntered:
                {
                    if(game.CheckLose() && game.CheckInputNickname() && !game.HasScoreBeenSaved())
                    {
                        auto key_pressed = window_event.text.unicode;
                        if(key_pressed >= 32)
                            game.AddToNickname(key_pressed);
                    }
                    break;
                }
                default:
                    break;
            }
        }

        if(game.TimerNeedRestart())
            tile_drop_speed.restart();
        game.Animate(text_box_parity.getElapsedTime());
        game.Run(tile_drop_speed.getElapsedTime());

        window.clear();

        game.Draw(window);

        window.display();
    }
    return 0;
}
