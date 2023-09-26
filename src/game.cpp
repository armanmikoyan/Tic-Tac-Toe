#include "game.h"

Game::Game()
{
    p1.turn = true;
    p2.turn = false;
}
  
void Game::draw_table()
{
    std::cout << "     0   1   2\n";
    std::cout << "   -------------\n";
    for (size_t i = 0; i < SIZE; ++i) 
    {
        std::cout << i << "  ";
        for (size_t j = 0; j < SIZE; ++j) 
        {
            std::cout << "| " << board.get_board()[i][j]->get_value() << " ";
        }
        std::cout << "|\n";
        std::cout << "   -------------\n" ;
    }
}

void Game::step()
{
    size_t row{};
    size_t col{};
    if (row >= SIZE || col >= SIZE)
    {
        std::cout << "out of bounds\n";
        return;
    }

    Cell* cell = nullptr;

    if (p1.turn)
    {
        //p2.controller.wait();
        //p1.controller.act();
        cell = new Xcell;
        p1.turn = false;
        p2.turn = true;
    }
    else
    {
        p1.controller.wait();
        p2.controller.act();
        cell = new Ocell;
        p2.turn = false;
        p1.turn = true;
    }
    board.set_cell(row, col, cell);
    draw_table();

//std::this_thread::sleep_for(std::chrono::seconds(13));
}


void Game::start()
{
    while (true)
    {
        step();
    }
}