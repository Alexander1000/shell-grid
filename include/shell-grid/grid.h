#ifndef H_SHELL_GRID_GRID_INCLUDED
#define H_SHELL_GRID_GRID_INCLUDED

#include <list>
#include <shell-grid/cell.h>

typedef std::list<*Cell> RowData;

namespace ShellGrid
{
    class Grid
    {
    public:
        Grid();
        Grid(int rows, int columns);
    private:
         std::list<*RowData> data;
    };
}

#endif
