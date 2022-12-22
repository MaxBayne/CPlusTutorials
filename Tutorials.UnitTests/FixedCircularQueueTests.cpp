#include "pch.h"
#include "CppUnitTest.h"
#include "../C++Tutorials/FixedCircularQueue.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace DataStructures;

namespace TutorialsUnitTests
{
	TEST_CLASS(FixedCircularQueueTests)
	{
	public:
		
		TEST_METHOD(Queue_Is_Empty)
		{
			FixedCircularQueue<int, 5> fixedCircularQueue;

			Assert::IsTrue(fixedCircularQueue.IsEmpty());
		}

		TEST_METHOD(Queue_Is_Full)
		{
			FixedCircularQueue<int, 5> fixedCircularQueue;

			fixedCircularQueue.EnQueue(1);
			fixedCircularQueue.EnQueue(2);
			fixedCircularQueue.EnQueue(3);
			fixedCircularQueue.EnQueue(4);
			fixedCircularQueue.EnQueue(5);

			Assert::IsTrue(fixedCircularQueue.IsFull());
		}

		TEST_METHOD(Queue_Is_Not_Empty)
		{
			FixedCircularQueue<int, 5> fixedCircularQueue;

			fixedCircularQueue.EnQueue(1);
			fixedCircularQueue.EnQueue(2);


			Assert::IsFalse(fixedCircularQueue.IsEmpty());
		}

		TEST_METHOD(Queue_Is_Overflow)
		{
			Assert::ExpectException<std::overflow_error>([]() 
				{
					FixedCircularQueue<int, 2> fixedCircularQueue;

					fixedCircularQueue.EnQueue(1);
					fixedCircularQueue.EnQueue(2);
					fixedCircularQueue.EnQueue(3);
				});
		}

		TEST_METHOD(Is_Rear_At_End_Of_Queue)
		{
			FixedCircularQueue<int, 2> fixedCircularQueue;

			fixedCircularQueue.EnQueue(1);
			fixedCircularQueue.EnQueue(2);

			Assert::IsTrue(fixedCircularQueue.IsRearAtEndOfQueue());
		}

		
	};
}
