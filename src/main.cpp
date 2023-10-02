#include <iostream>
#include "SFML/Graphics.hpp"
#include "Props.hpp"
#include "Game.hpp"
using namespace sf;


int main(){
    Clock tile_drop_speed;
    Clock text_box_parity;
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
                    if(game.AreWeIn(Game::GameState::LEADERBOARD) && window_event.key.code == Keyboard::M)
                        game.GoToMainMenu();
                    if(game.AreWeIn(Game::GameState::MAIN_MENU))
                    {
                        switch (window_event.key.code)
                        {
                            case Keyboard::S:
                            {
                                game.StartGame();
                                break;
                            }
                            case Keyboard::L:
                            {
                                game.GoToLeaderboard();
                                break;
                            }
                            case Keyboard::Q:
                            {
                                window.close();
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    else if(game.AreWeIn(Game::GameState::INPUT_SCREEN) && !game.HasScoreBeenSaved())
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
                    else if(game.AreWeIn(Game::GameState::LOSE_SCREEN))
                    {
                        switch (window_event.key.code)
                        {
                            case Keyboard::M:
                            {
                                game.ResetGame();
                                game.GoToMainMenu();
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
                    if(game.AreWeIn(Game::GameState::INPUT_SCREEN) && !game.HasScoreBeenSaved())
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
