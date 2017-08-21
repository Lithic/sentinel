#include "sentinel/UnitTest.h"

using namespace lithic::sentinel;
using namespace std;

UnitTest::UnitTest() {
	expect = new Expect();
	name = __func__;
}

void UnitTest::beforeAll(std::function<void()> beforeAllFunction) {
	_beforeAllFunction = beforeAllFunction;
}

void UnitTest::beforeEach(std::function<void()> beforeEachFunction) {
	_beforeEachFunction = beforeEachFunction;
}

void UnitTest::afterAll(std::function<void()> afterAllFunction) {
	_afterAllFunction = afterAllFunction;
}

void UnitTest::afterEach(std::function<void()> afterEachFunction) {
	_afterEachFunction = afterEachFunction;
}

void UnitTest::test(std::string name, std::function<void()> testFunction) {
	_testFunctions[name] = testFunction;
}

int UnitTest::run() {
	if (_beforeAllFunction) {
		_beforeAllFunction();
	}
	for (auto test : _testFunctions) {
		if (_beforeEachFunction) {
			_beforeEachFunction();
		}
		string name = test.first;
		test.second();
		if (_afterEachFunction) {
			_afterEachFunction();
		}
	}
	if (_afterAllFunction) {
		_afterAllFunction();
	}
}
