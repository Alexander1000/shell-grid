# shell-grid

Library for draw grid in shell

For example:
Code:
```
#include <shell-grid.h>

int main() {
    int nRows = 6, nCols = 4;

    ShellGrid::Grid grid(nRows, nCols);

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            grid.Set(i, j, new ShellGrid::CellNumeric(i * nCols + j));
        }
    }

    grid.Output();

    return 0;
}

```

Out:
```
┌──┬──┬──┬──┐
│0 │1 │2 │3 │
├──┼──┼──┼──┤
│4 │5 │6 │7 │
├──┼──┼──┼──┤
│8 │9 │10│11│
├──┼──┼──┼──┤
│12│13│14│15│
├──┼──┼──┼──┤
│16│17│18│19│
├──┼──┼──┼──┤
│20│21│22│23│
└──┴──┴──┴──┘

```
