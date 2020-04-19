#include <shell-grid.h>
#include <list>

namespace ShellGrid
{
    Grid::Grid(int rows, int columns)
    {
        this->data = std::list<RowData*>();
        this->nRows = rows;
        this->nColumns = columns;
    }

    void Grid::Set(int row, int column, class ShellGrid::Cell* cell)
    {

    }
}
