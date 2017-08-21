#pragma once
#include <vector>
#include "UnitTest.h"

namespace lithic {
    namespace sentinel {
        class TestRunner {
        private:
            std::vector<UnitTest*> _tests;
        public:
            void add(UnitTest* test);
            int run();
        };
    }
}
