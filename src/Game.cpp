#include "Game.hpp"

Game::Game()
{
    game_state = GameState::MAIN_MENU;
    saved = false;
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

    pause_text.setString("PAUSE");
    pause_text.setCharacterSize(28);
    pause_text.setFont(text_font);
    pause_text.setPosition(Vector2f(WINDOW_WIDTH / 2 - pause_text.getLocalBounds().getSize().x / 2, 10 * texture_size));

    main_menu = new MainMenu(text_font, texture_size);
}
Game::~Game()
{
    delete background;
    delete current_tile;
    delete next_tiles[0];
    delete next_tiles[1];
    delete next_tiles[2];
    delete dialog_box;
    delete nickname;
    delete main_menu;
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

void Game::Run(const Time timer)
{
    if(game_state == GameState::INPUT_SCREEN)
        dialog_box->UpdateActionsText(std::string("Menu[M]  Save[ENTER]  Retry[R]"));
    if(game_state == GameState::LOSE_SCREEN)
    {
        if(saved)
            dialog_box->UpdateActionsText(std::string("Menu[M]     Saved     Retry[R]"));
    }
    if(game_state != GameState::GAME)
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
        game_state = GameState::LOSE_SCREEN;
    
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

void Game::ModifyTileSpeed(const int value)
{
    tile_drop_speed = value; 
}

void Game::ResetGame()
{
    game_state = GameState::GAME;
    saved = false;
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

    pause_text.setString("PAUSE");
    pause_text.setCharacterSize(28);
    pause_text.setFont(text_font);
    pause_text.setPosition(Vector2f(WINDOW_WIDTH / 2 - pause_text.getLocalBounds().getSize().x / 2, 10 * texture_size));
}

void Game::PauseGame()
{
    if(game_state != GameState::PAUSE)
        game_state = GameState::PAUSE;
    else
        game_state = GameState::GAME;
}

void Game::InputNickname()
{
    nickname = new Textbox(text_font, texture_size);
    game_state = GameState::INPUT_SCREEN;
}


void Game::AddToNickname(const char c)
{
    nickname->AddToNickname(c, texture_size);
}

void Game::RemFromNickname()
{
    nickname->RemFromNickname(texture_size);
}

void Game::SaveScore()
{
    std::ofstream leaderboard_out("../data/LeaderBoard.log",std::ios::app);
    leaderboard_out<<" <n> "<<nickname->GetNickname() << " <s> " << score;
    saved = true;
    game_state = GameState::LOSE_SCREEN;
}

bool Game::HasScoreBeenSaved()
{
    return saved;
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
                                    //value = 1;
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
    if(game_state != GameState::GAME)
        return;
    if (current_tile->CheckForRotation(tile_reg))
        current_tile->Rotate();
}

void Game::LowerTile()
{
    if(game_state != GameState::GAME)
        return;
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
    if(game_state != GameState::GAME)
        return;
    if(current_tile->CheckRight(tile_reg))
        current_tile->MoveRight();
}

void Game::MoveLeft()
{
    if(game_state != GameState::GAME)
        return;
    if(current_tile->CheckLeft(tile_reg))
        current_tile->MoveLeft();
}

void Game::MoveToLowest()
{
    if(game_state != GameState::GAME)
        return;
    score += 10;
    while(current_tile->CheckUnder(tile_reg))
    {
        this->LowerTile();
    }
}

void Game::Animate(const Time text_box_parity)
{
    if(game_state == GameState::INPUT_SCREEN)
        nickname->Animate(text_box_parity);
}


void Game::StartGame()
{
    game_state = GameState::GAME;
}

void Game::GoToMainMenu()
{
    delete dialog_box;
    game_state = GameState::MAIN_MENU;
}

void Game::GoToLeaderboard()
{
    leaderboard = new LeaderBoard(text_font, texture_size);
    game_state = GameState::LEADERBOARD;
}

bool Game::AreWeIn(int game_state)
{
    return game_state == this->game_state;
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
    if(game_state == GameState::LOSE_SCREEN || game_state == GameState::INPUT_SCREEN)
        dialog_box->Draw(window);
    if(game_state == GameState::PAUSE)
        window.draw(pause_text);
    if(game_state == GameState::INPUT_SCREEN)
        nickname->Draw(window);
    if(game_state == GameState::MAIN_MENU)
        main_menu->Draw(window);
    if(game_state == GameState::LEADERBOARD)
        leaderboard->Draw(window);
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

LoseScreen::LoseScreen(const Font& font, const float texture_size, const std::string score)
{
    score_text.setString("Score");
    score_text.setCharacterSize(22);
    score_text.setFont(font);
    score_text.setPosition(Vector2f(WINDOW_WIDTH / 2 - score_text.getLocalBounds().getSize().x/2, 9 * texture_size));

    score_value.setString(score);
    score_value.setCharacterSize(22);
    score_value.setFont(font);
    score_value.setPosition(Vector2f(WINDOW_WIDTH / 2 - score_value.getLocalBounds().getSize().x/2, 10 * texture_size));
    
    actions.setString("Menu[M] Save Score[S] Retry[R]");
    actions.setCharacterSize(22);
    actions.setFont(font);
    actions.setPosition(Vector2f(WINDOW_WIDTH / 2 - actions.getLocalBounds().getSize().x/2, 12 * texture_size));
    

    lose_screen_texture.loadFromFile("../assets/lose_screen.png");
    lose_screen.setSize(Vector2f(14 * texture_size, 6 * texture_size));
    lose_screen.setPosition(Vector2f(WINDOW_WIDTH / 4, 8 * texture_size));
    lose_screen.setTexture(&lose_screen_texture);
}

void LoseScreen::UpdateActionsText(const std::string str)
{
    actions.setString(str);
}

void LoseScreen::Draw(RenderWindow &window)
{
    window.draw(lose_screen);
    window.draw(score_text);
    window.draw(score_value);
    window.draw(actions);
}

Textbox::Textbox(const Font &font, const float texture_size)
{
    last_parity = 0;
    nickname_string = "_";
    nickname.setString(nickname_string);
    nickname.setCharacterSize(22);
    nickname.setFont(font);
    nickname.setPosition(Vector2f(WINDOW_WIDTH / 2 - nickname.getLocalBounds().getSize().x/2, 11 * texture_size));

}

std::string Textbox::GetNickname()
{
    return nickname_string;
}

void Textbox::AddToNickname(const char c, const float texture_size)
{
    if(nickname_string.length() >= 50)
        return;
    if(last_parity == 1)
        nickname_string.push_back(c);
    else
    {
        nickname_string.pop_back();
        nickname_string.push_back(c);
        nickname_string.push_back('_');
    }
    nickname.setString(nickname_string);
    nickname.setPosition(Vector2f(WINDOW_WIDTH / 2 - nickname.getLocalBounds().getSize().x/2, 11 * texture_size));
}

void Textbox::RemFromNickname(const float texture_size)
{
    if(nickname_string.length() <= 1)
        return;
    if(last_parity == 1)
        nickname_string.pop_back();
    else
    {
        nickname_string.pop_back();
        nickname_string.pop_back();
        nickname_string.push_back('_');
    }
    nickname.setString(nickname_string);
    nickname.setPosition(Vector2f(WINDOW_WIDTH / 2 - nickname.getLocalBounds().getSize().x/2, 11 * texture_size));
}

void Textbox::Animate(const Time text_box_parity)
{
    int time_value = int(text_box_parity.asSeconds());
    if(time_value % 2 != last_parity)
    {
        if(time_value % 2 == 1)
            nickname_string.pop_back();
        else if(time_value % 2 == 0)
            nickname_string.push_back('_');
    }
    nickname.setString(nickname_string);
    last_parity = time_value % 2;
}

void Textbox::Draw(RenderWindow &window)
{
    window.draw(nickname);
}

MainMenu::MainMenu(const Font &font, const float texture_size)
{
    start.setString("Start[S]");
    start.setCharacterSize(22);
    start.setFont(font);
    start.setPosition(Vector2f(WINDOW_WIDTH / 2 - start.getLocalBounds().getSize().x/2, 9 * texture_size));

    leaderboard.setString("Leaderboard[L]");
    leaderboard.setCharacterSize(22);
    leaderboard.setFont(font);
    leaderboard.setPosition(Vector2f(WINDOW_WIDTH / 2 - leaderboard.getLocalBounds().getSize().x/2, 10 * texture_size));
    
    exit_game.setString("Exit[Q]");
    exit_game.setCharacterSize(22);
    exit_game.setFont(font);
    exit_game.setPosition(Vector2f(WINDOW_WIDTH / 2 - exit_game.getLocalBounds().getSize().x/2, 11 * texture_size));
    

    menu_screen_texture.loadFromFile("../assets/lose_screen.png");
    menu_screen.setSize(Vector2f(14 * texture_size, 5 * texture_size));
    menu_screen.setPosition(Vector2f(WINDOW_WIDTH / 4, 8 * texture_size));
    menu_screen.setTexture(&menu_screen_texture);
}

void MainMenu::Draw(RenderWindow &window)
{
    window.draw(menu_screen);
    window.draw(start);
    window.draw(leaderboard);
    window.draw(exit_game);
}

LeaderBoard::LeaderBoard(const Font &font, const float texture_size)
{
    std::vector<std::pair<std::string, unsigned int>> stats;
    std::ifstream leaderboard_in("../data/LeaderBoard.log");
    short last_token = 0;
    std::string temp_token;
    std::string nickname_to_store = "";
    unsigned int score_to_store = 0;
    while(leaderboard_in >> temp_token)
    {
        if(temp_token == "<n>")
        {
            last_token = 1;
        }
        else if(temp_token == "<s>")
            last_token = 2;
        else
        {
            if(last_token == 1)
            {
                nickname_to_store += temp_token;
            }
            else if(last_token == 2)
            {
                for(int i = 0; i < temp_token.length(); i++)
                {
                    score_to_store = score_to_store * 10 + temp_token[i] - '0';
                }
                stats.push_back(std::pair<std::string, unsigned int>(nickname_to_store, score_to_store));
                nickname_to_store = "";
                score_to_store = 0;
            }
        }
    }
    bool swapped;
    do
    {
        swapped = false;
        for(int i = 0; i < stats.size() - 1; i++)
        {
            if(stats[i].second < stats[i + 1].second)
            {
                std::swap(stats[i], stats[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
    for(int i = 0; i < stats.size() - 1; i++)
        for(int j = i + 1; j < stats.size(); j++)
            if(stats[i].first == stats[j].first)
                stats.erase(stats.begin() + j);
    for(int i = 10; i < stats.size(); i++)
        stats.erase(stats.begin() + i);
    for(int i = 0; i < std::min((int)10, (int)stats.size()); i++)
    {
        std::string temp_string = stats[i].first;
        leaderboard_display[i].setCharacterSize(22);
        leaderboard_display[i].setFont(font);
        do
        {
            temp_string += ' ';
           leaderboard_display[i].setString(temp_string + std::to_string(stats[i].second));
        } while (leaderboard_display[i].getLocalBounds().getSize().x <= 12 * texture_size);
        
        leaderboard_display[i].setPosition(Vector2f(WINDOW_WIDTH / 2 - leaderboard_display[i].getLocalBounds().getSize().x/2, 5 * texture_size + i * texture_size));
    }
    action.setString("Back[M]");
    action.setCharacterSize(22);
    action.setFont(font);
    action.setPosition(Vector2f(WINDOW_WIDTH / 2 - action.getLocalBounds().getSize().x/2, 16 * texture_size));


    leaderboard_screen_texture.loadFromFile("../assets/lose_screen.png");
    leaderboard_screen.setSize(Vector2f(14 * texture_size, 14 * texture_size));
    leaderboard_screen.setPosition(Vector2f(WINDOW_WIDTH / 4, 4 * texture_size));
    leaderboard_screen.setTexture(&leaderboard_screen_texture);
}

void LeaderBoard::Draw(RenderWindow &window)
{
    window.draw(leaderboard_screen);
    for(int i = 0; i < 10; i++)
        window.draw(leaderboard_display[i]);
    window.draw(action);
}
