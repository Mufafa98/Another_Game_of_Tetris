#include "Colors.hpp"
const Color Colors::cyan = Color(0, 255, 255);
const Color Colors::yellow = Color(255, 255, 0);
const Color Colors::red = Color(255, 0, 0);
const Color Colors::green = Color(0, 255, 0);
const Color Colors::orange = Color(255, 128, 0);
const Color Colors::blue = Color(0, 0, 255);
const Color Colors::purple = Color(127, 0, 255);

Color Colors::ReturnByIndex(int idx)
{
    switch (idx)
    {
        case 1 :
        {   
            return cyan;
            break;
        }
        case 2 :
        {   
            return yellow;
            break;
        }
        case 3 :
        {   
            return red;
            break;
        }
        case 4 :
        {   
            return green;
            break;
        }
        case 5 :
        {   
            return orange;
            break;
        }
        case 6 :
        {   
            return blue;
            break;
        }
        case 7 :
        {   
            return purple;
            break;
        }
    
        default:
            return Color(255,255,255);
            break;
    }
};