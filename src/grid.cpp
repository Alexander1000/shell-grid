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
        Cell* cur = Get(row, column);
        *cur = cell;
    }

    Cell* Grid::Get(int row, int column)
    {
        int curRow = 0;
        std::list<RowData*>::iterator itRows;
        for (itRows = this->data.begin(); itRows != this->data.end(); ++itRows) {
            if (curRow == row) {
                break;
            }
            curRow++;
        }

        RowData* rowData = nullptr;

        if (itRows == this->data.end()) {
            // not found row, then generate new
            for (int i = curRow; i < row; ++i) {
                rowData = new RowData;
                this->data.push_back(rowData);
            }
        } else {
            rowData = *itRows;
        }

        if (rowData == nullptr) {
            // @todo: throw exception
            return nullptr;
        }

        // rowData - current need row for insert

        int curCol = 0;
        RowData::iterator itCols;

        for (itCols = rowData->begin(); itCols != rowData->end(); ++itCols) {
            if (curCol == column) {
                break;
            }
            curCol++;
        }

        Cell* cell = nullptr;

        if (itCols == rowData->end()) {
            for (int i = curCol; i < column; ++i) {
                // @todo cell null pointer
                rowData->push_back(new CellNumeric(0));
            }
        } else {
            cell = *itCols;
        }

        return cell;
    }
}
