#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_5.5_C++/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
	TEST_CLASS(UnitTest54)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int b = 3;
			int actual = stupid_dobutok(10, 10, b);
			int expected = 100;
			Assert::AreEqual(actual, expected);
		}
	};
}
