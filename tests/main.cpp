#include <cpp-unit-test.h>
#include <shell-grid.h>

CppUnitTest::TestCase* testGrid_SimpleData_Positive()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("001-simple-test");
    t->printTitle();

    ShellGrid::Grid grid(6, 4);

    t->finish();
    return t;
}

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(testGrid_SimpleData_Positive());

    testSuite.printTotal();
    return 0;
}
