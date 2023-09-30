#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class Colors{
    static const Color cyan;
    static const Color yellow;
    static const Color red;
    static const Color green;
    static const Color orange;
    static const Color blue;
    static const Color purple;
public:
    static Color ReturnByIndex(const int idx);
};

