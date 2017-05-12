#include "sentinel/ExpectTest.h"

int main() {
	Sentinel* sentinel = new Sentinel();
	sentinel->add(new ExpectTest());

	return sentinel->runTests();
}