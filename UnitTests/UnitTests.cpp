#include "pch.h"
#include "CppUnitTest.h"
#include "../ecovis_sdl1/Misc/StaticDequeue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestEmptyAndFullMember)
		{
			// See https://stackoverflow.com/questions/655065/when-should-i-use-the-new-keyword-in-c
			// Also look at smart pointers etc.
			StaticDequeue<int,3> queue;
			Assert::AreEqual(true,queue.empty());
			queue.push_front(1);
			Assert::AreEqual(false,queue.empty());
			queue.push_back(2);
			Assert::AreEqual(false,queue.full());
			queue.push_front(3);
			Assert::AreEqual(true,queue.full());
			int first = queue.pop_front();
			Assert::AreEqual(false,queue.full());
			int second = queue.pop_front();
			Assert::AreEqual(false, queue.empty());
			int third = queue.pop_front();
			Assert::AreEqual(true, queue.empty());
		}
	};
}
