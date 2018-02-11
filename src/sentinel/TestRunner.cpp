#include "sentinel/TestRunner.h"

using namespace std;
using namespace lithic::sentinel;

void TestRunner::add(UnitTest* test) {
    _tests.push_back(test);
}

bool TestRunner::run() {
    bool success = true;
    for (auto test : _tests) {
        if (!test->run()) {
            success = false;
        }
    }
    return success;
}
