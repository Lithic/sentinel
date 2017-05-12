#include "sentinel/ExpectTest.h"

using namespace sentinel;

ExpectTest::ExpectTest() : UnitTest() {
	beforeAll([=]() {
		_controller = new DummyTestController();
		_expect = new Expect(_controller);
	});

	beforeEach([=] {
		_controller->failed = false;
	});

	test("toEqual", [=]() {

	});
}