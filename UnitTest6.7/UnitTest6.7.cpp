#include "pch.h"
#include "CppUnitTest.h"
#include "../oop6.7/oop6_7.cpp"
#include "D:\Student\oop6.7\oop6.7\Array.cpp"
#include "D:\Student\oop6.7\oop6.7\Functors.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest67
{
	TEST_CLASS(UnitTest67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array b;
			int t = b.size();
			Assert::AreEqual(t, 10);
		}
	};
}
