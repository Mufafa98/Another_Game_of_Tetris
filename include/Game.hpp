#pragma once
#include "SFML/Graphics.hpp"
#include "Props.hpp"
using namespace sf;

class GameBackground{
private:
    static const int size_border = 57;
    RectangleShape border[size_border];
public:
    GameBackground(const Texture& tile_texture);

    void Draw(RenderWindow& window);
};

class Game{
private:
    static const int size_tile_reg_height = 21;
    static const int size_tile_reg_width = 12;
    int tile_reg[size_tile_reg_height][size_tile_reg_width];
    Texture tile_texture;
    GameBackground *background;
public:
    Game();
    ~Game();

    void Draw(RenderWindow& window);
};