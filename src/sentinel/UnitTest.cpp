#include "sentinel/UnitTest.h"
#include <iostream>
#include <gloss/gloss.h>

using namespace lithic::sentinel;
using namespace std;
using namespace gloss;

UnitTest::UnitTest() {
	expect = new Expect();
	name = __func__;
}

void UnitTest::beforeAll(function<void()> beforeAllFunction) {
	_beforeAllFunction = beforeAllFunction;
}

void UnitTest::beforeEach(function<void()> beforeEachFunction) {
	_beforeEachFunction = beforeEachFunction;
}

void UnitTest::afterAll(function<void()> afterAllFunction) {
	_afterAllFunction = afterAllFunction;
}

void UnitTest::afterEach(function<void()> afterEachFunction) {
	_afterEachFunction = afterEachFunction;
}

void UnitTest::test(string name, function<void()> testFunction) {
	_testFunctions[name] = testFunction;
}

void UnitTest::printName(string testName) {
	cout << "[" << name << "." << testName << "]: ";
}

void UnitTest::printPassed() {
	cout << green("SUCCESS") << endl;
}

void UnitTest::printFailed(string explanation) {
	cout << red("FAILURE: ") << explanation << endl;
}

bool UnitTest::run() {
	bool runSuccess = true;
	if (_beforeAllFunction) {
		_beforeAllFunction();
	}
	for (auto test : _testFunctions) {
		if (_beforeEachFunction) {
			_beforeEachFunction();
		}
		string name = test.first;
		printName(name);
		bool passed = true;
		try {
			test.second();
		} catch (ExpectException e) {
			passed = false;
			printFailed(e.what());
		}
		if (passed) {
			printPassed();
		}
		else {
			runSuccess = false;
		}
		if (_afterEachFunction) {
			_afterEachFunction();
		}
	}
	if (_afterAllFunction) {
		_afterAllFunction();
	}
	return runSuccess;
}
