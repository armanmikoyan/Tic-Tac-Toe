#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell {
public:
    Cell() = default;
    Cell(char value);

public:
    virtual char get_value();

private:   
    char m_value;
};

class Xcell : public Cell {
public:
    Xcell();
};

class Ocell : public Cell {
public:
    Ocell();
};

class Emptycell : public Cell {
public:
    Emptycell();
};

#endif // CELL_H