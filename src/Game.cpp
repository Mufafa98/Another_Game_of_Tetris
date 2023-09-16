#include "Game.hpp"

Game::Game()
{
    current_tile_type = 0;
    tile_texture.loadFromFile("../assets/tetris_tile_100_b90.png");
    background = new GameBackground(tile_texture, texture_size);
    for(int i = 0; i < size_tile_reg_height; i++)
        for(int j = 0; j< size_tile_reg_width; j++)
            tile_reg[i][j] = 0;

    current_tile = new No2(texture_size, tile_texture);
}

Game::~Game()
{
    delete background;
    delete current_tile;
}

void Game::NewTile()
{
    current_tile_type++;
    current_tile_type %= 7;
}

void Game::RotateTile()
{
    current_tile->Rotate();
}

void Game::LowerTile()
{
    current_tile->LowerTile();
}

void Game::MoveRight()
{
    current_tile->MoveRight();
}

void Game::MoveLeft()
{
    current_tile->MoveLeft();
}

void Game::Draw(RenderWindow &window)
{
    background->Draw(window);
    current_tile->Draw(window);
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
