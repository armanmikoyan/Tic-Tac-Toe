#include "board.h"


Board::Board()
:   m_board(SIZE, std::vector<Cell*>(SIZE, nullptr))
{
    for (int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            m_board[i][j] = new Emptycell;
        }
       
    }
}

Board::~Board()
{
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            delete m_board[i][j]; 
        }
    } 
}

std::vector<std::vector<Cell *>> Board::get_board()
{
    return  m_board;
}

void Board::set_cell(size_t row, size_t col, Cell* cell)
{
    if (row >= SIZE || col >= SIZE)
    {
       std::cout << "Out of Bounds" ;  
    }
    Emptycell* tmp = dynamic_cast<Emptycell*>(m_board[row][col]);
    if (tmp)
    {
        delete tmp;
        m_board[row][col] = cell;
    }
    else
    {
        std::cout << "Cell is not empty";  
    }
}