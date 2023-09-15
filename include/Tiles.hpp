#pragma once
#include <cmath>
#include "SFML/Graphics.hpp"
#include "Props.hpp"
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

const static short int number_of_tile_colors = 7;
const Color tile_color[number_of_tile_colors] = {
    Color(0, 238, 255),
    Color(0, 0, 255),
    Color(255, 162, 0),
    Color(238, 255, 5),
    Color(5, 250, 17),
    Color(129, 5, 252),
    Color(255, 0, 0)
};

class Tiles{
protected:
    float texture_size;
    Vector2f possition;
    RectangleShape graphical_shape[4][4];
    Color current_color;
    Texture current_texture;
public:
    virtual void Rotate() = 0;
    virtual void Draw(RenderWindow& window);
};
class No1 : public Tiles{
public:
    No1(const float texture_size, const Texture texture);
    void Rotate(){};
};
class No2 : public Tiles{
    short state;
public:
    No2(const float texture_size, const Texture texture);
    void Rotate();
};
class No3 : public Tiles{
    short state;
public:
    No3(const float texture_size, const Texture texture);
    void Rotate();
};
class No4 : public Tiles{
    short state;
public:
    No4(const float texture_size, const Texture texture);
    void Rotate();
};
class No5 : public Tiles{
    short state;
public:
    No5(const float texture_size, const Texture texture);
    void Rotate();
};
class No6 : public Tiles{
    short state;
public:
    No6(const float texture_size, const Texture texture);
    void Rotate();
};
class No7 : public Tiles{
    short state;
public:
    No7(const float texture_size, const Texture texture);
    void Rotate();
};






