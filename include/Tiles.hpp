#pragma once
#include <cmath>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Props.hpp"
#include "Colors.hpp"
using namespace sf;
//  Tile type:      1.      2.      3.      4.      5.      6.      7.
//                  ....    #...    ....    ....    ....    ....    ....
//                  ....    #...    #...    #...    .#..    #...    .#..
//                  ##..    #...    ##..    #...    .#..    ##..    ##..
//                  ##..    #...    #...    ##..    ##..    .#..    #...

const bool no1[4][4] = 
{
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {1, 1, 0, 0},
};
const bool no2[2][4][4] = 
{
    {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
    }
};
const bool no3[4][4][4] =
{
    {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
    }
};
const bool no4[4][4][4] =
{
    {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
    },
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {1, 0, 0, 0},
    }
};
const bool no5[4][4][4] =
{
    {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
    },
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
    }
};
const bool no6[2][4][4] =
{
    {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
    }
};
const bool no7[2][4][4] =
{
    {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
    }
};


class Tiles{
protected:
    short y_pos = -4;
    short x_pos = 6;
    short tile_type;
    short state;
    short color_idx;
    float texture_size;
    Vector2f possition;
    RectangleShape graphical_shape[4][4];
    Color current_color;
    Texture current_texture;
public:
    virtual void Rotate() = 0;
    void FitOnX();
    bool CheckUnder(int tile_reg[21][12]);
    bool CheckLeft(int tile_reg[21][12]);
    bool CheckRight(int tile_reg[21][12]);
    bool CheckForRotation(int tile_reg[21][12]);

    short GetX();
    short GetY();
    short GetMaxX();
    short GetType();
    short GetState();
    short GetColorIdx();

    void LowerTile();
    void MoveRight();
    void MoveLeft();

    void DrawAt(RenderWindow& window, Vector2f at);
    void Draw(RenderWindow& window);
};
class No1 : public Tiles{
public:
    No1(const float texture_size, const Texture texture);
    void Rotate(){};
};
class No2 : public Tiles{
public:
    No2(const float texture_size, const Texture texture);
    void Rotate();
};
class No3 : public Tiles{
public:
    No3(const float texture_size, const Texture texture);
    void Rotate();
};
class No4 : public Tiles{
public:
    No4(const float texture_size, const Texture texture);
    void Rotate();
};
class No5 : public Tiles{
public:
    No5(const float texture_size, const Texture texture);
    void Rotate();
};
class No6 : public Tiles{
public:
    No6(const float texture_size, const Texture texture);
    void Rotate();
};
class No7 : public Tiles{
public:
    No7(const float texture_size, const Texture texture);
    void Rotate();
};






