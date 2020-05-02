#include <cpp-unit-test.h>
#include <shell-grid.h>

CppUnitTest::TestCase* testGrid_SimpleData_Positive()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("001-simple-test");
    t->printTitle();

    int nRows = 6, nCols = 4;

    ShellGrid::Grid grid(nRows, nCols);

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            grid.Set(i, j, new ShellGrid::CellNumeric(i * nCols + j));
        }
    }

    grid.Output();

    t->finish();
    return t;
}

CppUnitTest::TestCase* testGrid_SimpleData2_Positive()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("002-simple-test");
    t->printTitle();

    int nRows = 6, nCols = 8;

    ShellGrid::Grid grid(nRows, nCols);

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            if (i % 2 == 0 || j % 2 == 0) {
                grid.Set(i, j, new ShellGrid::CellNumeric(i * nCols + j));
            }
        }
    }

    grid.Output();

    t->finish();
    return t;
}

CppUnitTest::TestCase* testGrid_SimpleData3_Positive()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("003-simple-test");
    t->printTitle();

    int nRows = 6, nCols = 8;

    ShellGrid::Grid grid(nRows, nCols);

    for (int i = 0; i < nRows - 1; ++i) {
        if (i == 0 || i == 2) {
            continue;
        }
        for (int j = 0; j < nCols; ++j) {
            if (j == 2 || j == nCols - 1) {
                continue;
            }
            if (i % 2 == 0 || j % 2 == 0) {
                grid.Set(i, j, new ShellGrid::CellNumeric(i * nCols + j));
            }
        }
    }

    grid.Output();

    t->finish();
    return t;
}

CppUnitTest::TestCase* testGrid_SingleItem_Positive()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("004-single-item-test");
    t->printTitle();

    int nRows = 6, nCols = 8;

    ShellGrid::Grid grid(nRows, nCols);

    grid.Set(4, 4, new ShellGrid::CellNumeric(666));

    grid.Output();

    t->finish();
    return t;
}

CppUnitTest::TestCase* testGrid_EmptyGrid_Positive()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("005-empty-grid-test");
    t->printTitle();

    int nRows = 4, nCols = 4;

    ShellGrid::Grid grid(nRows, nCols);

    grid.Output();

    t->finish();
    return t;
}

CppUnitTest::TestCase* testGrid_GridWithString_Positive()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("006-grid-with-string-test");
    t->printTitle();

    int nRows = 4, nCols = 4;

    ShellGrid::Grid grid(nRows, nCols);

    for (int i = 1; i < nRows; ++i) {
        for (int j = 1; j < nCols; ++j) {
            grid.Set(i, j, new ShellGrid::CellNumeric((10 - i) * nCols + (i * j)));
        }
    }

    grid.Set(0, 1, new ShellGrid::CellString("Column A"));
    grid.Set(0, 2, new ShellGrid::CellString("Column B"));
    grid.Set(0, 3, new ShellGrid::CellString("Column C"));

    grid.Set(1, 0, new ShellGrid::CellString("Row I"));
    grid.Set(2, 0, new ShellGrid::CellString("Row II"));
    grid.Set(3, 0, new ShellGrid::CellString("Row III"));

    grid.Output();

    t->finish();
    return t;
}

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(testGrid_SimpleData_Positive());

    testSuite.addTestCase(testGrid_SimpleData2_Positive());

    testSuite.addTestCase(testGrid_SimpleData3_Positive());

    testSuite.addTestCase(testGrid_SingleItem_Positive());

    testSuite.addTestCase(testGrid_EmptyGrid_Positive());

    testSuite.addTestCase(testGrid_GridWithString_Positive());

    testSuite.printTotal();
    return 0;
}
