#include "board.h"


Board::Board()
:   m_board{new Cell*[SIZE]}
{
    for (int i = 0; i < SIZE; ++i)
    {
        m_board[i] = new Emptycell[SIZE];
    }
}

Board::~Board()
{
    for (int i = 0; i < SIZE; ++i)
    {
        delete  m_board[i];
    } 
    delete[] m_board;
}

Cell** Board::get_board()
{
    return m_board;
}

void Board::set_cell(size_t row, size_t col, const Cell& cell)
{
    if (row >= SIZE || col >= SIZE)
    {
       throw std::out_of_range("Out of Bounds");  
    }
    Emptycell* tmp = dynamic_cast<Emptycell*>(&m_board[row][col]);
    if (tmp)
    {
        std::cout << typeid(tmp).name() << " ";
        m_board[row][col] = cell;
        std::cout << m_board[row][col].get_value();
    }
    else
    {
        throw std::out_of_range("Cell is not empty");  
    }
}