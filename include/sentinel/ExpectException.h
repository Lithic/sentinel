#pragma once

namespace lithic {
    namespace sentinel {
        class ExpectException {
        public:
            std::string message;
            ExpectException(std::string s) : message(s) {};
        };
    }
}
