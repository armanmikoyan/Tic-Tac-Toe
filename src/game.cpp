#include "game.h"

Game::Game()
{
    board.read();
    draw_table();
    p1.turn = true;
    p2.turn = false;
}
  
void Game::draw_table()
{ 
    std::system("clear");
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
    std::cin >> row;
    std::cin >> col;
    if (row >= SIZE || col >= SIZE)
    {
        std::cout << "out of bounds\n";
        return;
    }

    Cell* cell = nullptr;

    if (p1.turn)
    {
        cell = new Xcell;
        p1.turn = false;
        p2.turn = true;
    }
    else
    {
        cell = new Ocell;
        p2.turn = false;
        p1.turn = true;
    }
    board.set_cell(row, col, cell);
    board.write();
}





void Game::start()
{
    std::thread drawThread(&Game::syncronization, this);
    while (true)
    {
        step();
    }
     drawThread.join();
}


void Game::syncronization()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        board.read();
        draw_table();
        board.write();      
    }
}






