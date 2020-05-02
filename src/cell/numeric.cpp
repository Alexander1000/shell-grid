#include <shell-grid.h>

#include <string>
#include <sstream>

namespace ShellGrid
{
    CellNumeric::CellNumeric(int digit)
    {
        this->digit = digit;
    }

    std::string CellNumeric::Output()
    {
        std::stringstream ss;
        ss << this->digit;
        return ss.str();
    }
}
