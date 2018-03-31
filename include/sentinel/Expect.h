#pragma once

#include <functional>
#include "ExpectException.h"

namespace lithic {
	namespace sentinel {
		class Expect {
		private:
			template <class T>
			std::string toString(T a) {
				return std::to_string(a);
			}

			std::string toString(const char* a) {
				return std::string(a);
			}
		public:
			template <class T>
			void toEqual(T a, T b) {
				if (a != b) {
					throw ExpectException("Expected: " + toString(a) + " to equal: " + toString(b));
				}
			}

			template <class T>
			void notToEqual(T a, T b) {
				if (a == b) {
					throw ExpectException("Expected: " + toString(a) + " not to equal: " + toString(b));
				}
			}

			template <class T>
			void toBeLessThan(T a, T b) {
				if (a >= b) {
					throw ExpectException("Expected: " + std::to_string(a) + " to be less than: " + std::to_string(b));
				}
			}

			template <class T>
			void toBeLessThanOrEqualTo(T a, T b) {
				if (a > b) {
					throw ExpectException("Expected: " + std::to_string(a) + " to be less than or equal to: " + std::to_string(b));
				}
			}

			template <class T>
			void toBeGreaterThan(T a, T b) {
				if (a <= b) {
					throw ExpectException("Expected: " + std::to_string(a) + " to be greater than: " + std::to_string(b));
				}
			}

			template <class T>
			void toBeGreaterThanOrEqualTo(T a, T b) {
				if (a < b) {
					throw ExpectException("Expected: " + std::to_string(a) + " to be greater than or equal to: " + std::to_string(b));
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

			template <class T>
			void toBeNull(T a) {
				size_t addr = (size_t)a;
				if (a != NULL) {
					throw ExpectException("Expected: " + toString(addr) + " to be NULL");
				}
			}

			template <class T>
			void notToBeNull(T a) {
				size_t addr = (size_t)a;
				if (a == NULL) {
					throw ExpectException("Expected: " + toString(addr) + " not to be NULL");
				}
			}

			void toThrowException(std::function<void()> f) {
				try {
					f();
				}
				catch (...) {
					return;
				}
				throw ExpectException("Expected function to throw exception");
			}

			void notToThrowException(std::function<void()> f) {
				try {
					f();
				}
				catch (const std::exception& e) {
					throw ExpectException("Expected function not to throw exception: " + std::string(e.what()));
				}
			}
		};
	}
}
