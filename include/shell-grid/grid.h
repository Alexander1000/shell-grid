#ifndef H_SHELL_GRID_GRID_INCLUDED
#define H_SHELL_GRID_GRID_INCLUDED

#include <list>
#include <map>
#include <shell-grid/cell.h>

typedef std::list<ShellGrid::Cell*> RowData;
typedef std::map<int, int> ColumnWidthMap;

namespace ShellGrid
{
    class Grid
    {
    public:
        Grid(int rows, int columns);
        void Set(int row, int column, Cell* cell);
        Cell* Get(int row, int column);
        void Output();
    private:
         std::list<RowData*> data;

         int nRows;
         int nColumns;

         RowData* getRow(int row);
         RowData::iterator getPointerCell(int row, int column);
         ColumnWidthMap* getColumnWidthMap();
    };
}

#endif
