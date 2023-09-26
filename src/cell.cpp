#include "cell.h"

Cell::Cell(char value)
: m_value{value}
{
}

char Cell::get_value()
{
    return m_value;
}

Xcell::Xcell()
: Cell{'X'}
{
}

Ocell::Ocell()
: Cell{'O'}
{
}

Emptycell::Emptycell()
: Cell{' '}
{
}


