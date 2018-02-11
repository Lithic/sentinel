#pragma once

#include <functional>
#include "ExpectException.h"

#include <iostream>

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
					std::cout << "throwing" << std::endl;
					throw ExpectException("Expected function not to throw exception: " + std::string(e.what()));
				}
				catch (...) {
					std::cout << "catchall?" << std::endl;
				}
			}
		};
	}
}
