#include <shell-grid.h>
#include <list>
#include <iostream>

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
        (*this->getPointerCell(row, column)) = cell;
    }

    Cell* Grid::Get(int row, int column)
    {
        return *this->getPointerCell(row, column);
    }

    RowData::iterator Grid::getPointerCell(int row, int column)
    {
        RowData* rowData = this->getRow(row);

        int curCol = 0;
        RowData::iterator itCols;

        for (itCols = rowData->begin(); itCols != rowData->end(); ++itCols) {
            if (curCol == column) {
                break;
            }
            curCol++;
        }

        if (itCols == rowData->end()) {
            itCols--;
            for (int i = curCol; i < column + 1; ++i) {
                rowData->push_back(new CellNull());
                itCols++;
            }
        }

        return itCols;
    }

    RowData* Grid::getRow(int row)
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
            for (int i = curRow; i < row + 1; ++i) {
                rowData = new RowData;
                this->data.push_back(rowData);
            }
        } else {
            rowData = *itRows;
        }

        return rowData;
    }

    std::string* Grid::Output()
    {
        std::list<RowData*>::iterator itRow;
        for (itRow = this->data.begin(); itRow != this->data.end(); ++itRow) {
            RowData::iterator itCell;
            for (itCell = (*itRow)->begin(); itCell != (*itRow)->end(); ++itCell) {
                std::cout << (*itCell)->Output() << std::endl;
            }
            std::cout << std::endl;
        }
        return nullptr;
    }
}
