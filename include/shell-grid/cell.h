#ifndef H_SHELL_GRID_CELL_INCLUDED
#define H_SHELL_GRID_CELL_INCLUDED

namespace ShellGrid
{
    class Cell
    {
    public:
        virtual std::string Output() = 0;
    };

    class CellNull : public Cell
    {
    public:
        CellNull();
        std::string Output() final;
    };

    class CellNumeric : public Cell
    {
    public:
        CellNumeric(int digit);
        std::string Output() final;
    private:
        int digit;
    };
}

#endif
