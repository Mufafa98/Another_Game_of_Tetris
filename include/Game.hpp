#pragma once
#include <string>
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

class Game{
private:
    const float texture_size = (float)WINDOW_HEIGHT / 22;
    static const int size_tile_reg_height = 21;
    static const int size_tile_reg_width = 12;
    int tile_reg[size_tile_reg_height][size_tile_reg_width];
    RectangleShape tile_reg_display[size_tile_reg_height][size_tile_reg_width];
    int current_tile_type;
    Tiles* current_tile;
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

    void Run();

    void NewTile();
    void RotateTile();
    void LowerTile();
    void MoveRight();
    void MoveLeft();
    void MoveToLowest();

    void Draw(RenderWindow& window);
};