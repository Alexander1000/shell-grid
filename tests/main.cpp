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

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(testGrid_SimpleData_Positive());

    testSuite.addTestCase(testGrid_SimpleData2_Positive());

    testSuite.printTotal();
    return 0;
}
