#include "sentinel/TestRunner.h"
#include "sentinel/ExpectTest.h"

using namespace lithic::sentinel;

int main() {
	TestRunner* testRunner = new TestRunner();
	testRunner->add(new ExpectTest());

	return testRunner->run() ? 0 : 1;
}
