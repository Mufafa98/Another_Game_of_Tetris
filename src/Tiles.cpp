#include "Tiles.hpp"

void Tiles::Draw(RenderWindow &window)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            window.draw(graphical_shape[i][j]);
}

No1::No1(const float texture_size, const Texture texture)
{
    current_texture = texture;
    current_color = tile_color[rand() % number_of_tile_colors];
    possition = Vector2f(WINDOW_WIDTH/4 + texture_size, 0);
    this->texture_size = texture_size;
    bool temp[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        };
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
    current_texture = texture;
    current_color = tile_color[rand() % number_of_tile_colors];
    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + texture_size, 0);
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
                graphical_shape[i][j].setFillColor(Color(0,0,0));
        }
}

No3::No3(const float texture_size, const Texture texture)
{
    current_texture = texture;
    current_color = tile_color[rand() % number_of_tile_colors];
    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + texture_size, 0);
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
                graphical_shape[i][j].setFillColor(Color(0,0,0));
        }
}

No4::No4(const float texture_size, const Texture texture)
{
    current_texture = texture;
    current_color = tile_color[rand() % number_of_tile_colors];
    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + texture_size, 0);
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
                graphical_shape[i][j].setFillColor(Color(0,0,0));
        }
}

No5::No5(const float texture_size, const Texture texture)
{
    current_texture = texture;
    current_color = tile_color[rand() % number_of_tile_colors];
    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + texture_size, 0);
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
                graphical_shape[i][j].setFillColor(Color(0,0,0));
        }
}

No6::No6(const float texture_size, const Texture texture)
{
    current_texture = texture;
    current_color = tile_color[rand() % number_of_tile_colors];
    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + texture_size, 0);
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
                graphical_shape[i][j].setFillColor(Color(0,0,0));
        }
}

No7::No7(const float texture_size, const Texture texture)
{
    current_texture = texture;
    current_color = tile_color[rand() % number_of_tile_colors];
    state = 0;
    possition = Vector2f(WINDOW_WIDTH/4 + texture_size, 0);
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
                graphical_shape[i][j].setFillColor(Color(0,0,0));
        }
}


