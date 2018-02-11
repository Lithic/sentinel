#pragma once

namespace lithic {
    namespace sentinel {
        class ExpectException : public std::exception {
        private:
        	std::string _message;
        public:
            ExpectException(std::string s) : std::exception() {
            	_message = s;
            };
            virtual const char* what() const noexcept {
            	return _message.c_str();
            }
        };
    }
}
