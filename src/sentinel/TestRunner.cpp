#include "sentinel/TestRunner.h"

using namespace std;
using namespace lithic::sentinel;

void TestRunner::add(UnitTest* test) {
    _tests.push_back(test);
}

int TestRunner::run() {
    int status = 0;
    for (auto test : _tests) {
        if (!test->run()) {
            status = 1;
        }
    }
    return status;
}
