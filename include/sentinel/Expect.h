#pragma once

#include <functional>
#include "ExpectException.h"

namespace lithic {
	namespace sentinel {
		class Expect {
		public:
			Expect() {}

			template <class T>
			void toEqual(T a, T b) {
				if (a != b) {
					throw ExpectException("Expected: " + std::to_string(a) + " to equal: " + std::to_string(b));
				}
			}

			template <class T>
			void notToEqual(T a, T b) {
				if (a == b) {
					throw ExpectException("Expected: " + std::to_string(a) + " not to equal: " + std::to_string(b));
				}
			}

			void toBeTrue(bool x) {
				if (!x) {
					throw ExpectException("Expected: " + std::string(x ? "true" : "false") + " to be true");
				}
			}

			void toBeFalse(bool x) {
				if (x) {
					throw ExpectException("Expected: " + std::string(x ? "true" : "false") + " to be false");
				}
			}

			void toThrowException(std::function<void()> f) {
				bool threw = false;
				try {
					f();
				}
				catch (...) {
					threw = true;
				}
				if (!threw) {
					throw ExpectException("Expected function to throw exception");
				}
			}
		};
	}
}
