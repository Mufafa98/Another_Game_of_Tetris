#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
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
    LoseScreen(Font& font, float texture_size, std::string score);
    void Draw(RenderWindow& window);
};

class Game{
private:
    bool running;
    bool need_restart;
    const float texture_size = (float)WINDOW_HEIGHT / 22;
    //                             Vector2f((float)WINDOW_WIDTH / 4 + 14 * (float)WINDOW_HEIGHT / 22 + ((float)WINDOW_WIDTH - ((float)WINDOW_WIDTH / 4 + 14 * (float)WINDOW_HEIGHT / 22)) / 2 - 1 * (float)WINDOW_HEIGHT / 22, 0);
    const Vector2f next_tile_pos = Vector2f(75 * (float)WINDOW_WIDTH / 88, 3 * (float)WINDOW_HEIGHT / 22);
    static const int size_tile_reg_height = 21;
    static const int size_tile_reg_width = 12;
    int tile_drop_speed;
    int tile_reg[size_tile_reg_height][size_tile_reg_width];
    RectangleShape tile_reg_display[size_tile_reg_height][size_tile_reg_width];
    
    LoseScreen *dialog_box;
    
    int current_tile_type;
    Tiles* current_tile;
    Tiles* next_tiles[3];
    Texture tile_texture;
    GameBackground *background;
    Font text_font;
    Text score_title;
    unsigned int score;
    Text score_value;
public:
    Game();
    ~Game();

    short CheckLinesClear();
    void ClearLines();

    void UpdateScore();

    void Run(Time timer);
    bool CheckLose();
    bool TimerNeedRestart();
    void ModifyTileSpeed(int value);
    void ResetGame();

    void NewTile();
    Tiles* GenerateTile();
    void RotateTile();
    void LowerTile();
    void MoveRight();
    void MoveLeft();
    void MoveToLowest();

    void Draw(RenderWindow& window);
};