#pragma once

#include <functional>
#include <vector>
#include "Expect.h"
#include "TestController.h"

namespace sentinel {
	class UnitTest : public TestController {
	private:
		Expect* expect = NULL;
	public:
		std::string name;

		UnitTest();
		void beforeAll(std::function<void()> beforeAllFunction);
		void beforeEach(std::function<void()> beforeEachFunction);
		void test(std::string name, std::function<void()> testFunction);
	};
}