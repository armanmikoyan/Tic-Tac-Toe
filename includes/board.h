#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include "vector"

#define SIZE 3

class Board {
public:
    Board();
   ~Board();

public:
    Cell** get_board();
    void set_cell(size_t, size_t, const Cell&);
private:
    Cell** m_board; 
};


#endif //BOARD_H