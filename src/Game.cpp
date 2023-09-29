#include "Game.hpp"

Game::Game()
{
    running = true;
    tile_drop_speed = 550;
    score = 0;
    current_tile_type = 0;
    tile_texture.loadFromFile("../assets/tetris_tile_100_b90.png");
    background = new GameBackground(tile_texture, texture_size);
    for(int i = 0; i < size_tile_reg_height; i++)
        for(int j = 0; j< size_tile_reg_width; j++)
        {
            tile_reg[i][j] = 0;
            tile_reg_display[i][j].setSize(Vector2f(texture_size, texture_size));
            tile_reg_display[i][j].setTexture(&tile_texture);
            tile_reg_display[i][j].setPosition(Vector2f(WINDOW_WIDTH / 4 + j * texture_size + texture_size, i * texture_size));
            tile_reg_display[i][j].setFillColor(Color(122,122,122,122));
        }


    current_tile = GenerateTile();
    next_tiles[0] = GenerateTile();
    next_tiles[1] = GenerateTile();
    next_tiles[2] = GenerateTile();

    text_font.loadFromFile("../assets/PixeloidMono-d94EV.ttf");
    score_title.setString("Score:\n");
    score_title.setCharacterSize(24);
    score_title.setFont(text_font);
    score_value.setString("000000000\n");
    score_value.setCharacterSize(24);
    score_value.setFont(text_font);
    score_value.setPosition(Vector2f(score_title.getPosition().x, score_title.getPosition().y + 24));

    
    
}
Game::~Game()
{
    delete background;
    delete current_tile;
    delete next_tiles[0];
    delete next_tiles[1];
    delete next_tiles[2];
    delete dialog_box;
}

short Game::CheckLinesClear()
{
    short result = 0;
    for(int i = 0; i < size_tile_reg_height; i++)
    {
        bool clear_line = true;
        for(int j = 0; j < size_tile_reg_width; j++)
            if(tile_reg[i][j] == 0)
                clear_line = false;
        if(clear_line)
        {
            result += 1;
            for(int j = 0; j < size_tile_reg_width; j++)
            {
                tile_reg[i][j] = 7;
                tile_reg_display[i][j].setFillColor(Colors::ReturnByIndex(tile_reg[i][j]));
            }
        }
    }
    return result;
}

void Game::ClearLines()
{
    for(int i = 0; i < size_tile_reg_height; i++)
    {
        if(tile_reg[i][0] == 7)
        {
            for(int k = i; k > 0; k--)
            {
                for(int j = 0; j < size_tile_reg_width; j++)
                {
                    tile_reg[k][j] = tile_reg[k - 1][j];
                    tile_reg_display[k][j].setFillColor(tile_reg_display[k - 1][j].getFillColor());
                }
            }
        }
    }
}

void Game::UpdateScore()
{
    std::string temp_score = std::to_string(score);
    std::string last_score ="";
    int control = 9;
    while(control - temp_score.length() > 0)
    {
        last_score += "0";
        control--;
    }
    last_score += temp_score;
    score_value.setString(last_score);
}

void Game::Run(Time timer)
{
    if(!running)
        return;

        
    if(timer.asMilliseconds() >= tile_drop_speed)
    {
        
        LowerTile();
        need_restart = true;
    }
    else
        need_restart = false;
     
    tile_drop_speed = 550;

    short no_of_lines = CheckLinesClear();
    if(no_of_lines)
    {
        ClearLines();
        score += 100 * std::pow(2, no_of_lines - 1);
    }
    UpdateScore();
    if(CheckLose())
    {
        running = false;
    }
}

bool Game::CheckLose()
{
    bool result = false;
    for(int i = 0; i < size_tile_reg_width; i++)
        if(tile_reg[1][i])
            result = true;
    if(result)
        dialog_box = new LoseScreen(text_font, texture_size, score_value.getString());
    return result;
}

bool Game::TimerNeedRestart()
{
    return need_restart;
}

void Game::ModifyTileSpeed(int value)
{
    tile_drop_speed = value; 
}

void Game::ResetGame()
{
    running = true;
    tile_drop_speed = 550;
    score = 0;
    current_tile_type = 0;
    for(int i = 0; i < size_tile_reg_height; i++)
        for(int j = 0; j< size_tile_reg_width; j++)
        {
            tile_reg[i][j] = 0;
            tile_reg_display[i][j].setSize(Vector2f(texture_size, texture_size));
            tile_reg_display[i][j].setTexture(&tile_texture);
            tile_reg_display[i][j].setPosition(Vector2f(WINDOW_WIDTH / 4 + j * texture_size + texture_size, i * texture_size));
            tile_reg_display[i][j].setFillColor(Color(122,122,122,122));
        }


    current_tile = GenerateTile();
    next_tiles[0] = GenerateTile();
    next_tiles[1] = GenerateTile();
    next_tiles[2] = GenerateTile();

    score_title.setString("Score:\n");
    score_title.setCharacterSize(24);
    score_title.setFont(text_font);
    score_value.setString("000000000\n");
    score_value.setCharacterSize(24);
    score_value.setFont(text_font);
    score_value.setPosition(Vector2f(score_title.getPosition().x, score_title.getPosition().y + 24));

}

void Game::NewTile()
{
    current_tile = next_tiles[0];
    next_tiles[0] = next_tiles[1];
    next_tiles[1] = next_tiles[2];
    next_tiles[2] = GenerateTile();
}

Tiles *Game::GenerateTile()
{
    int value = rand() % 7 + 1;
                                    //value = 2;
    switch (value)
    {
        case 1:
            return new No1(texture_size, tile_texture);
            break;
        case 2:
            return new No2(texture_size, tile_texture);
            break;
        case 3:
            return new No3(texture_size, tile_texture);
            break;
        case 4:
            return new No4(texture_size, tile_texture);
            break;
        case 5:
            return new No5(texture_size, tile_texture);
            break;
        case 6:
            return new No6(texture_size, tile_texture);
            break;
        case 7:
            return new No7(texture_size, tile_texture);
            break;
        
        default:
            break;
    }
    return new No1(texture_size, tile_texture);
}

void Game::RotateTile()
{
    if (current_tile->CheckForRotation(tile_reg))
        current_tile->Rotate();
}

void Game::LowerTile()
{
    if(current_tile->CheckUnder(tile_reg))
        current_tile->LowerTile();
    else
    {
        short i = current_tile->GetY();
        short j = current_tile->GetX() - 1;
        short last_i = i + 4;
        short last_j = j + 4;
        short tile_type = current_tile->GetType();
        short tile_state = current_tile->GetState();
        short temp_i = 0;
        short temp_j = 0;
        short color_idx = current_tile->GetColorIdx();
        while(i < last_i)
        {
            j = current_tile->GetX() - 1;
            temp_j = 0;
            while(j < last_j)
            {
                if(j >= size_tile_reg_width)
                    break;
                switch (tile_type)
                {
                    case 1:
                    {
                        if(no1[temp_i][temp_j])
                        {
                            tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] = 1;
                            Color tile_color = Colors::ReturnByIndex(color_idx);
                            tile_color.a = tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] * 255;
                            tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(tile_color);
                            if(tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] == 0)
                                tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(Color(122,122,122,122));
                        }
                        break;
                    }
                    case 2:
                    {
                        if(no2[tile_state][temp_i][temp_j])
                        {
                            tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] = 1;
                            Color tile_color = Colors::ReturnByIndex(color_idx);
                            tile_color.a = tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] * 255;
                            tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(tile_color);
                            if(tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] == 0)
                                tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(Color(122,122,122,122));
                        }
                        break;
                    }
                    case 3:
                    {
                        if(no3[tile_state][temp_i][temp_j])
                        {
                            tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] = 1;
                            Color tile_color = Colors::ReturnByIndex(color_idx);
                            tile_color.a = tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] * 255;
                            tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(tile_color);
                            if(tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] == 0)
                                tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(Color(122,122,122,122));
                        }
                        break;
                    }
                    case 4:
                    {
                        if(no4[tile_state][temp_i][temp_j])
                        {
                            tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] = 1;
                            Color tile_color = Colors::ReturnByIndex(color_idx);
                            tile_color.a = tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] * 255;
                            tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(tile_color);
                            if(tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] == 0)
                                tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(Color(122,122,122,122));
                        }
                        break;
                    }
                    case 5:
                    {
                        if(no5[tile_state][temp_i][temp_j])
                        {
                            tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] = 1;
                            Color tile_color = Colors::ReturnByIndex(color_idx);
                            tile_color.a = tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] * 255;
                            tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(tile_color);
                            if(tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] == 0)
                                tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(Color(122,122,122,122));
                        }
                        break;
                    }
                    case 6:
                    {
                        
                        if(no6[tile_state][temp_i][temp_j])
                        {
                            tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] = 1;
                            Color tile_color = Colors::ReturnByIndex(color_idx);
                            tile_color.a = tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] * 255;
                            tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(tile_color);
                            if(tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] == 0)
                                tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(Color(122,122,122,122));
                        }
                        break;
                    }
                    case 7:
                    {
                        if(no7[tile_state][temp_i][temp_j])
                        {
                            tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] = 1;
                            Color tile_color = Colors::ReturnByIndex(color_idx);
                            tile_color.a = tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] * 255;
                            tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(tile_color);
                            if(tile_reg[std::max((int)i, 0)][std::max((int)j, 0)] == 0)
                                tile_reg_display[std::max((int)i, 0)][std::max((int)j, 0)].setFillColor(Color(122,122,122,122));
                        }
                        break;
                    }
                    default:
                        break;
                }
                j++;
                temp_j++;
            }
            if(i >= size_tile_reg_height)
                break;
            i++;
            temp_i++;
        }
        
        this->NewTile();
    }
    
}

void Game::MoveRight()
{
    if(current_tile->CheckRight(tile_reg))
        current_tile->MoveRight();
}

void Game::MoveLeft()
{
    if(current_tile->CheckLeft(tile_reg))
        current_tile->MoveLeft();
}

void Game::MoveToLowest()
{
    score += 10;
    while(current_tile->CheckUnder(tile_reg))
    {
        this->LowerTile();
    }
}

void Game::Draw(RenderWindow &window)
{
    background->Draw(window);
    for(int i = 0; i < size_tile_reg_height; i++)
    {
        for(int j = 0; j<size_tile_reg_width; j++)
        {
            window.draw(tile_reg_display[i][j]);
        }
    }
    current_tile->Draw(window);
    window.draw(score_title);
    window.draw(score_value);
    for(int i = 0; i < 3; i++)
    {
        next_tiles[i]->DrawAt(window,Vector2f(next_tile_pos.x, next_tile_pos.y + 6 * i * texture_size));
    }
    if(!running)
        dialog_box->Draw(window);
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

LoseScreen::LoseScreen(Font& font, float texture_size, std::string score)
{
    score_text.setString("Score");
    score_text.setCharacterSize(22);
    score_text.setFont(font);
    score_text.setPosition(Vector2f(WINDOW_WIDTH / 2 - score_text.getLocalBounds().getSize().x/2, 9 * texture_size));

    score_value.setString(score);
    score_value.setCharacterSize(22);
    score_value.setFont(font);
    score_value.setPosition(Vector2f(WINDOW_WIDTH / 2 - score_value.getLocalBounds().getSize().x/2, 10 * texture_size));
    
    actions.setString("Exit[Q] Save Score[S] Retry[R]");
    actions.setCharacterSize(22);
    actions.setFont(font);
    actions.setPosition(Vector2f(WINDOW_WIDTH / 2 - actions.getLocalBounds().getSize().x/2, 12 * texture_size));
    

    lose_screen_texture.loadFromFile("../assets/lose_screen.png");
    lose_screen.setSize(Vector2f(14 * texture_size, 6 * texture_size));
    lose_screen.setPosition(Vector2f(WINDOW_WIDTH / 4, 8 * texture_size));
    lose_screen.setTexture(&lose_screen_texture);
}

void LoseScreen::Draw(RenderWindow &window)
{
    window.draw(lose_screen);
    window.draw(score_text);
    window.draw(score_value);
    window.draw(actions);
}
