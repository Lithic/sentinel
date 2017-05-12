#pragma once

#include "TestController.h"

namespace sentinel {
	class Expect {
	private:
		TestController* _controller = NULL;
	public:
		Expect(TestController* controller) : _controller(controller) {};

		template <class T>
		void toEqual(T a, T b) {
			if (a != b) {
				_controller->failure("Expected: " + std::to_string(a) + " to equal: " + std::to_string(b));
			}
		}

		template <class T>
		void notToEqual(T a, T b) {
			if (a == b) {
				_controller->failure("Expected: " + std::to_string(a) + " not to equal: " + std::to_string(b));
			}
		}

		void toBeTrue(bool x) {
			if (!x) {
				_controller->failure("Expected: " + std::string(x ? "true" : "false") + " to be true");
			}
		}

		void toBeFalse(bool x) {
			if (x) {
				_controller->failure("Expected: " + std::string(x ? "true" : "false") + " to be false");
			}
		}
	};
}