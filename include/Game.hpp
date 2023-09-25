#pragma once
#include <string>
#include <vector>
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
    //const Vector2f next_tile_pos = Vector2f((float)WINDOW_WIDTH / 4 + 14 * (float)WINDOW_HEIGHT / 22 + ((float)WINDOW_WIDTH - ((float)WINDOW_WIDTH / 4 + 14 * (float)WINDOW_HEIGHT / 22)) / 2 - 1 * (float)WINDOW_HEIGHT / 22, 0);
    const Vector2f next_tile_pos = Vector2f(75 * (float)WINDOW_WIDTH / 88, 3 * (float)WINDOW_HEIGHT / 22);
    static const int size_tile_reg_height = 21;
    static const int size_tile_reg_width = 12;
    int tile_reg[size_tile_reg_height][size_tile_reg_width];
    RectangleShape tile_reg_display[size_tile_reg_height][size_tile_reg_width];
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

    void Run();
    bool CheckLose();

    void NewTile();
    Tiles* GenerateTile();
    void RotateTile();
    void LowerTile();
    void MoveRight();
    void MoveLeft();
    void MoveToLowest();

    void Draw(RenderWindow& window);
};