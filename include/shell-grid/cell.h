#ifndef H_SHELL_GRID_CELL_INCLUDED
#define H_SHELL_GRID_CELL_INCLUDED

#include <shell-grid/cell-type.h>

namespace ShellGrid
{
    class Cell
    {
    public:
        virtual CellType GetType() = 0;
        std::string* Output();
    };
}

#endif
