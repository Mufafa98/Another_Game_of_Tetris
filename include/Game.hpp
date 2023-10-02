#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <map>
#include "SFML/Graphics.hpp"
#include "Props.hpp"
#include "Tiles.hpp"
using namespace sf;

class GameBackground{
private:
    static const int size_border = 57;
    RectangleShape border[size_border];
public:
    GameBackground(const Texture& tile_texture, const float texture_size);

    void Draw(RenderWindow& window);
};
class LoseScreen{
private:
    Text score_text;
    Text score_value;
    Text actions;
    RectangleShape lose_screen;
    Texture lose_screen_texture;
public:
    LoseScreen(const Font& font, const float texture_size, const std::string score);
    void UpdateActionsText(const std::string str);
    void Draw(RenderWindow& window);
};
class Textbox{
private:
    bool last_parity;
    std::string nickname_string;
    Text nickname;
public:
    Textbox(const Font& font, const float texture_size);
    std::string GetNickname();
    void AddToNickname(const char c, const float texture_size);
    void RemFromNickname(const float texture_size);
    void Animate(const Time text_box_parity);
    void Draw(RenderWindow& window);
};
class MainMenu{
    private:
    Text start;
    Text leaderboard;
    Text exit_game;
    
    RectangleShape menu_screen;
    Texture menu_screen_texture;
    public:
    MainMenu(const Font& font, const float texture_size);
    void Draw(RenderWindow& window);
};
class LeaderBoard{
    private:
    Text leaderboard_display[10];
    Text action;
    RectangleShape leaderboard_screen;
    Texture leaderboard_screen_texture;
    public:
    LeaderBoard(const Font& font, const float texture_size);
    void Draw(RenderWindow& window);};
class Game{
private:
    bool saved;
    bool need_restart;
    short game_state;
    short tile_reg[size_tile_reg_height][size_tile_reg_width];
    short tile_drop_speed;
    unsigned int score;
    const float texture_size = (float)WINDOW_HEIGHT / 22;
    const Vector2f next_tile_pos = Vector2f(75 * (float)WINDOW_WIDTH / 88, 3 * (float)WINDOW_HEIGHT / 22);
    Tiles* current_tile;
    Tiles* next_tiles[3];
    GameBackground *background;
    LoseScreen *dialog_box;
    MainMenu* main_menu;
    LeaderBoard* leaderboard;
    Textbox *nickname;
    RectangleShape tile_reg_display[size_tile_reg_height][size_tile_reg_width];
    Text score_title;
    Text score_value;
    Text pause_text;
    Texture tile_texture;
    Font text_font;
    
public:
    enum GameState {
        MAIN_MENU,
        LEADERBOARD,
        GAME,
        PAUSE,
        LOSE_SCREEN,
        INPUT_SCREEN
    };
    Game();
    ~Game();

    short CheckLinesClear();
    void ClearLines();

    void UpdateScore();

    void Run(const Time timer);
    bool CheckLose();
    bool TimerNeedRestart();
    void ModifyTileSpeed(const int value);
    void ResetGame();
    void PauseGame();
    void InputNickname();
    void AddToNickname(const char c);
    void RemFromNickname();
    void SaveScore();
    bool HasScoreBeenSaved();
    void StartGame();
    void GoToMainMenu();
    void GoToLeaderboard();
    bool AreWeIn(int game_state);

    void NewTile();
    Tiles* GenerateTile();
    void RotateTile();
    void LowerTile();
    void MoveRight();
    void MoveLeft();
    void MoveToLowest();

    void Draw(RenderWindow& window);
    void Animate(const Time text_box_parity);
};