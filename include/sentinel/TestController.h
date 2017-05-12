#pragma once

#include <string>

namespace sentinel {
	class TestController {
	public:
		virtual void failure(std::string message) {};
	};
}