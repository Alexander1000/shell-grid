#include <cpp-unit-test.h>
#include <shell-grid.h>

CppUnitTest::TestCase* testGrid_SimpleData_Positive()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("001-simple-test");
    t->printTitle();

    ShellGrid::Grid grid(6, 4);

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            grid.Set(i, j, new ShellGrid::CellNumeric(i * j));
        }
    }

    t->finish();
    return t;
}

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(testGrid_SimpleData_Positive());

    testSuite.printTotal();
    return 0;
}
