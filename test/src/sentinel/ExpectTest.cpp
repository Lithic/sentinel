#include "sentinel/ExpectTest.h"

using namespace lithic::sentinel;

ExpectTest::ExpectTest() : UnitTest() {
	name = __func__;

	test("toEqual", [=]() {
		expect->notToThrowException([=]() {
			expect->toEqual(true, true);
			expect->toEqual("one", "one");
		});
		expect->toThrowException([=]() {
			expect->toEqual(true, false);
			expect->toEqual("one", "two");
		});
	});

	test("notToEqual", [=]() {
		expect->notToThrowException([=]() {
			expect->notToEqual(true, false);
		});
		expect->toThrowException([=]() {
			expect->notToEqual(true, true);
		});
	});

	test("toBeLessThan", [=]() {
		expect->notToThrowException([=]() {
			expect->toBeLessThan(3, 4);
		});
		expect->toThrowException([=]() {
			expect->toBeLessThan(5, 5);
		});
	});
}
