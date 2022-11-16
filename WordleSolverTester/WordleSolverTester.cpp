#include "pch.h"
#include "CppUnitTest.h"
#include "../WordleSolver/WordleSolver.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordleSolverTester
{



	TEST_CLASS(WordleSolverTester)
	{
	public:
		void testAreDifferent(uint32_t binA, uint32_t binB, bool expected)
		{
			Assert::AreEqual(areDifferent(binA, binB), expected);
		}

		TEST_METHOD(AreDifferentTesterA)
		{
			testAreDifferent(2, 4, true);
		}
		TEST_METHOD(AreDifferentTesterB)
		{
			testAreDifferent(16, 32, true);
		}
		TEST_METHOD(AreDifferentTesterC)
		{
			testAreDifferent(2, 3, false);
		}
		TEST_METHOD(AreDifferentTesterD)
		{
			testAreDifferent(16, 17, false);
		}

	};
}
