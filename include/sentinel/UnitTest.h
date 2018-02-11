#pragma once

#include <map>
#include <string>
#include "Expect.h"

namespace lithic {
	namespace sentinel {
		class UnitTest {
		private:
			std::function<void()> _beforeAllFunction = NULL;
			std::function<void()> _beforeEachFunction = NULL;
			std::function<void()> _afterAllFunction = NULL;
			std::function<void()> _afterEachFunction = NULL;
			std::map<std::string, std::function<void()>> _testFunctions;
		protected:
			lithic::sentinel::Expect* expect = NULL;
		public:
			std::string name;

			UnitTest();
			void beforeAll(std::function<void()> beforeAllFunction);
			void beforeEach(std::function<void()> beforeEachFunction);
			void afterAll(std::function<void()> afterAllFunction);
			void afterEach(std::function<void()> afterEachFunction);
			void test(std::string name, std::function<void()> testFunction);
			void printName(std::string name);
			void printPassed();
			void printFailed(std::string explanation);
			bool run();
		};
	}
}
