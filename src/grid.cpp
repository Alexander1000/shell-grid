#include <shell-grid.h>
#include <list>
#include <map>
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

    ColumnWidthMap* Grid::getColumnWidthMap()
    {
        // N column => Width
        ColumnWidthMap* columnWidthMap;
        columnWidthMap = new ColumnWidthMap;

        std::list<RowData*>::iterator itRow;
        itRow = this->data.begin();
        for (int numRow = 0; numRow < this->nRows; ++numRow) {
            if (itRow != this->data.end()) {
                RowData::iterator itCell;

                itCell = (*itRow)->begin();
                for (int colNum = 0; colNum < this->nColumns; ++colNum) {
                    int columnWidth = 0;

                    if (itCell != (*itRow)->end()) {
                        columnWidth = strlen((*itCell)->Output().c_str());
                    }

                    ColumnWidthMap::iterator itColumnWidth = columnWidthMap->find(colNum);
                    if (itColumnWidth != columnWidthMap->end()) {
                        if (itColumnWidth->second < columnWidth) {
                            itColumnWidth->second = columnWidth;
                        }
                    } else {
                        columnWidthMap->insert(std::pair<int, int>(colNum, columnWidth));
                    }

                    if (itCell != (*itRow)->end()) {
                        itCell++;
                    }
                }
            } else {
                for (int numCol = 0; numCol < this->nColumns; ++numCol) {
                    ColumnWidthMap::iterator itColumnWidth = columnWidthMap->find(numCol);
                    if (itColumnWidth != columnWidthMap->end()) {
                        continue;
                    } else {
                        columnWidthMap->insert(std::pair<int, int>(numCol, 0));
                    }
                }
            }

            if (itRow != this->data.end()) {
                itRow++;
            }
        }

        return columnWidthMap;
    }

    void Grid::printBorder(ColumnWidthMap* columnWidthMap, char* leftBorder, char* innerBorder, char* splitBorder, char* rightBorder)
    {
        std::cout << leftBorder;

        ColumnWidthMap::iterator itColumnWidth, itNextColumnWidth;
        for (itColumnWidth = columnWidthMap->begin(); itColumnWidth != columnWidthMap->end(); ++itColumnWidth) {
            for (int i = 0; i < itColumnWidth->second; ++i) {
                std::cout << innerBorder;
            }

            itNextColumnWidth = itColumnWidth;
            itNextColumnWidth++;
            if (itNextColumnWidth != columnWidthMap->end()) {
                std::cout << splitBorder;
            }
        }

        std::cout << rightBorder;
    }

    void Grid::Output()
    {
        // N column => Width
        ColumnWidthMap* columnWidthMap = this->getColumnWidthMap();

        // head
        this->printBorder(columnWidthMap, (char*) "\u250C", (char*) "\u2500", (char*) "\u252C", (char*) "\u2510");
        std::cout << std::endl;

        ColumnWidthMap::iterator itColumnWidth, itNextColumnWidth;

        // body, inner part
        std::list<RowData*>::iterator itRow;
        itRow = this->data.begin();
        for (int numRow = 0;  numRow != this->nRows; ++numRow) {
            // print data
            std::cout << "\u2502";

            int colNum = 0;

            if (itRow != this->data.end()) {
                RowData::iterator itCell;
                for (itCell = (*itRow)->begin(); itCell != (*itRow)->end(); ++itCell) {
                    std::string out = (*itCell)->Output();
                    std::cout << out;
                    itColumnWidth = columnWidthMap->find(colNum);
                    if (itColumnWidth->second > strlen(out.c_str())) {
                        for (int j = strlen(out.c_str()); j < itColumnWidth->second; ++j) {
                            std::cout << "\x20";
                        }
                    }

                    RowData::iterator itCellNext = itCell;
                    itCellNext++;

                    if (colNum < this->nColumns - 1) {
                        std::cout << "\u2502";
                    }
                    colNum++;
                }
            }

            if (colNum < this->nColumns) {
                for (int j = colNum; j < this->nColumns; ++j) {
                    itColumnWidth = columnWidthMap->find(j);
                    for (int k = 0; k < itColumnWidth->second; ++k) {
                        std::cout << "\x20";
                    }
                    if (j != this->nColumns - 1) {
                        std::cout << "\u2502";
                    }
                }
            }
            std::cout << "\u2502";
            std::cout << std::endl;

            // print border

            std::list<RowData*>::iterator itRowNext = itRow;
            itRowNext++;

            if (numRow < this->nRows - 1) {

                this->printBorder(columnWidthMap, (char*) "\u251C", (char*) "\u2500", (char*) "\u253C", (char*) "\u2524");
                std::cout << std::endl;
            }

            if (itRow != this->data.end()) {
                itRow++;
            }
        }

        // footer
        this->printBorder(columnWidthMap, (char*) "\u2514", (char*) "\u2500", (char*) "\u2534", (char*) "\u2518");
        std::cout << std::endl;
    }
}
