#pragma once

#include "sentinel/UnitTest.h"

namespace sentinel {
	class DummyTestController : public TestController {
	public:
		bool failed = false;
		virtual void failure(std::string message) {
			failed = true;
		}
	};

	class ExpectTest : UnitTest {
	private:
		DummyTestController* _controller = NULL;
		Expect* _expect = NULL;
	public:
		ExpectTest();
	};
}