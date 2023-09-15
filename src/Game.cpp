#include "Game.hpp"

Game::Game()
{
    current_tile_type = 0;
    tile_texture.loadFromFile("../assets/tetris_tile_100_b90.png");
    background = new GameBackground(tile_texture, texture_size);
    for(int i = 0; i < size_tile_reg_height; i++)
        for(int j = 0; j< size_tile_reg_width; j++)
            tile_reg[i][j] = 0;

    current_tile[0] = new No1(texture_size, tile_texture);
    current_tile[1] = new No2(texture_size, tile_texture);
    current_tile[2] = new No3(texture_size, tile_texture);
    current_tile[3] = new No4(texture_size, tile_texture);
    current_tile[4] = new No5(texture_size, tile_texture);
    current_tile[5] = new No6(texture_size, tile_texture);
    current_tile[6] = new No7(texture_size, tile_texture);
}

Game::~Game()
{
    delete background;
    delete[] current_tile;
}

void Game::NewTile()
{
    current_tile_type++;
    current_tile_type %= 7;
}

void Game::RotateTile()
{
    current_tile[current_tile_type]->Rotate();
}

void Game::Draw(RenderWindow &window)
{
    background->Draw(window);
    current_tile[current_tile_type]->Draw(window);
}

GameBackground::GameBackground(const Texture& tile_texture, const float texture_size)
{
    for(int i = 0; i < size_border; i++)
    {
        border[i].setTexture(&tile_texture);
        border[i].setSize(Vector2f(texture_size, texture_size));
        border[i].setFillColor(Color(122,122,122));
        if(i == 0)
        {
            border[i].setPosition(Vector2f(WINDOW_WIDTH / 4, 0));
        }
        else if(i < 23)
        {
            border[i].setPosition(Vector2f(WINDOW_WIDTH / 4, i * texture_size));
        }
        else if(i < 35)
        {
            border[i].setPosition(Vector2f((i - 22) * texture_size + WINDOW_WIDTH / 4, WINDOW_HEIGHT - texture_size));
        }
        else
        {
            border[i].setPosition(Vector2f(WINDOW_WIDTH / 4 + 13 * texture_size, WINDOW_HEIGHT - (i - 34) * texture_size));
        }
    }
}

void GameBackground::Draw(RenderWindow &window)
{
    for(int i = 0; i < size_border; i++)
    {
        window.draw(border[i]);
    }
}
