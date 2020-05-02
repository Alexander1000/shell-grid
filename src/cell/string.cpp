#include <shell-grid.h>
#include <string>

namespace ShellGrid
{
    CellString::CellString(std::string s)
    {
        this->value = s;
    }

    std::string CellString::Output()
    {
        return this->value;
    }
}
