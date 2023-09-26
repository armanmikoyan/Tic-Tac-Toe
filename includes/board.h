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
    std::vector<std::vector<Cell *>> get_board();
    void set_cell(size_t, size_t, Cell*);
private:
    std::vector<std::vector<Cell*>> m_board;
};


#endif //BOARD_H