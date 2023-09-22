#include "Tiles.hpp"
void Tiles::FitOnX()
{
    float end_of_game_screen = WINDOW_WIDTH / 4 + 14 * texture_size;
    if(tile_type == 1)
    {
        if(possition.x > end_of_game_screen - 3 * texture_size)
            possition.x = end_of_game_screen - 3 * texture_size;
    }
    if(tile_type == 2)
    {
        if(state == 0)
        {
            if(possition.x > end_of_game_screen - 2 * texture_size)
                possition.x = end_of_game_screen - 2 * texture_size;
        }
        else
        {
            if(possition.x > end_of_game_screen - 5 * texture_size)
            {
                possition.x = end_of_game_screen - 5 * texture_size;
                x_pos = 9;
            }
        }
    }
    else
    {
        if(state % 2 == 0)
        {
            if(possition.x > end_of_game_screen - 3 * texture_size)
                possition.x = end_of_game_screen - 3 * texture_size;
        }
        else
        {
            if(possition.x > end_of_game_screen - 4 * texture_size)
            {
                possition.x = end_of_game_screen - 4 * texture_size;
                x_pos = 10;
            }
        }
    }
}
//to do check on right and left
bool Tiles::CheckUnder(int tile_reg[21][12])
{
    if(y_pos == 17)
        return false;
    switch (tile_type)
    {
        case 1:
        {
            if(tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 4][x_pos - 1])
                return false;
            return true;
            break;
        }
        case 2:
        {
            if(state == 0)
            {
                if(tile_reg[y_pos + 4][x_pos - 1])
                    return false;
                return true;
            }
            else
            {
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 4][x_pos + 1] || tile_reg[y_pos + 4][x_pos + 2])
                    return false;
                return true;
            }
        }
        case 3:
        {
            if(state == 0)
            {
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 3][x_pos])
                    return false;
                return true;
            }else if(state == 1){
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 4][x_pos + 1])
                    return false;
                return true;
            }else if(state == 2){
                if(tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 3][x_pos - 1])
                    return false;
                return true;
            }else{
                if(tile_reg[y_pos + 3][x_pos - 1] || tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 3][x_pos + 1])
                    return false;
                return true;
            }
            break;
        }
        case 4:
        {
            if(state == 0)
            {
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 4][x_pos])
                    return false;
                return true;
            }else if(state == 1){
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 4][x_pos + 1])
                    return false;
                return true;
            }else if(state == 2){
                if(tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 2][x_pos - 1])
                    return false;
                return true;
            }else{
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 3][x_pos] || tile_reg[y_pos + 3][x_pos + 1])
                    return false;
                return true;
            }
            break;
        }
        case 5:
        {
            if(state == 0)
            {
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 4][x_pos])
                    return false;
                return true;
            }else if(state == 1){
                if(tile_reg[y_pos + 4][x_pos + 1] || tile_reg[y_pos + 3][x_pos - 1] || tile_reg[y_pos + 3][x_pos])
                    return false;
                return true;
            }else if(state == 2){
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 2][x_pos])
                    return false;
                return true;
            }else{
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 4][x_pos + 1])
                    return false;
                return true;
            }
            break;
        }
        case 6:
        {
            if(state == 0)
            {
                if(tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 3][x_pos - 1])
                    return false;
                return true;
            }else if(state == 1){
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 3][x_pos + 1])
                    return false;
                return true;
            }
            break;
        }
        case 7:
        {
            if(state == 0)
            {
                if(tile_reg[y_pos + 4][x_pos - 1] || tile_reg[y_pos + 3][x_pos])
                    return false;
                return true;
            }else if(state == 1){
                if(tile_reg[y_pos + 4][x_pos] || tile_reg[y_pos + 4][x_pos + 1] || tile_reg[y_pos + 3][x_pos - 1])
                    return false;
                return true;
            }
            break;
        }
        default:
            return true;
            break;
    }
}

short Tiles::GetX()
{
    return x_pos;
}

short Tiles::GetY()
{
    return y_pos;
}

short Tiles::GetMaxX()
{
    if(tile_type == 1)
        return 11;
    else if(tile_type == 2)
    {
        if(state == 0)
            return 12;
        return 9;
    }
    else
    {
        if(state % 2 == 0)
            return 11;
        return 10;
    }
}

short Tiles::GetType()
{
    return tile_type;
}

short Tiles::GetState()
{
    return state;
}

short Tiles::GetColorIdx()
{
    return color_idx;
}

void Tiles::LowerTile()
{
    if(possition.y > WINDOW_HEIGHT - 4 * texture_size)
        return;
    possition.y = possition.y + texture_size;
    y_pos++;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
}

void Tiles::MoveRight()
{
    
    possition.x = possition.x + texture_size;
    x_pos = std::min(x_pos + 1 , (int)GetMaxX());
    this->FitOnX();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));

}

void Tiles::MoveLeft()
{
    if(possition.x < WINDOW_WIDTH / 4 + texture_size)
        return;
    x_pos--;
    possition.x = possition.x - texture_size;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));

}

void Tiles::Draw(RenderWindow &window)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            window.draw(graphical_shape[i][j]);
}

No1::No1(const float texture_size, const Texture texture)
{
    tile_type = 1;
    current_texture = texture;
    color_idx = rand() % 7;
    current_color = Colors::ReturnByIndex(color_idx);
    possition = Vector2f(WINDOW_WIDTH/4 + 6 * texture_size, -4 * texture_size);
    this->texture_size = texture_size;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no1[i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
        }
}

No2::No2(const float texture_size, const Texture texture)
{
    tile_type = 2;
    current_texture = texture;
    color_idx = rand() % 7;
    current_color = Colors::ReturnByIndex(color_idx);    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + 6 * texture_size, -4 * texture_size);
    this->texture_size = texture_size;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no2[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);

            }
        }
}
void No2::Rotate()
{
    state++;
    state %= 2;

    this->FitOnX();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no2[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
            else
                graphical_shape[i][j].setFillColor(Color(0,0,0,0));
        }
}

No3::No3(const float texture_size, const Texture texture)
{
    tile_type = 3;
    current_texture = texture;
    color_idx = rand() % 7;
    current_color = Colors::ReturnByIndex(color_idx);    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + 6 * texture_size, -4 * texture_size);
    this->texture_size = texture_size;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no3[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
        }
}
void No3::Rotate()
{
    state++;
    state %= 4;
    this->FitOnX();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no3[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
            else
                graphical_shape[i][j].setFillColor(Color(0,0,0,0));
        }
}

No4::No4(const float texture_size, const Texture texture)
{
    tile_type = 4;
    current_texture = texture;
    color_idx = rand() % 7;
    current_color = Colors::ReturnByIndex(color_idx);    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + 6 * texture_size, -4 * texture_size);
    this->texture_size = texture_size;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no4[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
        }
}
void No4::Rotate()
{
    state++;
    state %= 4;
    this->FitOnX();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no4[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
            else
                graphical_shape[i][j].setFillColor(Color(0,0,0,0));
        }
}

No5::No5(const float texture_size, const Texture texture)
{
    tile_type = 5;
    current_texture = texture;
    color_idx = rand() % 7;
    current_color = Colors::ReturnByIndex(color_idx);    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + 6 * texture_size, -4 * texture_size);
    this->texture_size = texture_size;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no5[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
        }
}
void No5::Rotate()
{
    state++;
    state %= 4;
    this->FitOnX();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no5[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
            else
                graphical_shape[i][j].setFillColor(Color(0,0,0,0));
        }
}

No6::No6(const float texture_size, const Texture texture)
{
    tile_type = 6;
    current_texture = texture;
    color_idx = rand() % 7;
    current_color = Colors::ReturnByIndex(color_idx);    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + 6 * texture_size, -4 * texture_size);
    this->texture_size = texture_size;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no6[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
        }
}
void No6::Rotate()
{
    state++;
    state %= 2;
    this->FitOnX();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no6[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
            else
                graphical_shape[i][j].setFillColor(Color(0,0,0,0));
        }
}

No7::No7(const float texture_size, const Texture texture)
{
    tile_type = 7;
    current_texture = texture;
    color_idx = rand() % 7;
    current_color = Colors::ReturnByIndex(color_idx);    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + 6 * texture_size, -4 * texture_size);
    this->texture_size = texture_size;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no7[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
        }
}
void No7::Rotate()
{
    state++;
    state %= 2;
    this->FitOnX();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(no7[state][i][j])
            {
                graphical_shape[i][j].setSize(Vector2f(texture_size, texture_size));
                graphical_shape[i][j].setPosition(Vector2f(possition.x + j * texture_size, possition.y + i * texture_size));
                graphical_shape[i][j].setFillColor(current_color);
                graphical_shape[i][j].setTexture(&current_texture);
            }
            else
                graphical_shape[i][j].setFillColor(Color(0,0,0,0));
        }
}


