#include "sentinel/UnitTest.h"

using namespace sentinel;
using namespace std;

UnitTest::UnitTest() {
	expect = new Expect(this);
	name = __func__;
}
