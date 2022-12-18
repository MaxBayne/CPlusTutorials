#include <iostream>
#include "LinkedList.h"
#include "FixedStack.h"
#include "DynamicStack.h"
#include "FixedSimpleQueue.h"

using namespace std;



int main()
{
#pragma region FixedSimpleQueue

	//Simple Queue Implemented by Array so its Fixed Size

	
	FixedSimpleQueue<int,5> fixedSimpleQueue;
	/*
	fixedSimpleQueue.EnQueue(100);
	fixedSimpleQueue.EnQueue(200);
	fixedSimpleQueue.EnQueue(300);
	fixedSimpleQueue.EnQueue(400);
	*/
	//cout << "Top Value = " << fixedStackList.Peak() <<"\n";
	

#pragma endregion

#pragma region DynamicStack

	//Stack List Implemented by LinkedList so its Dynamic Size

	/*
	DynamicStack<int> stackList;

	stackList.Push(100);
	stackList.Push(200);
	stackList.Push(300);
	stackList.Push(400);

	//cout << "Top Value = " << stackList.Peak() <<"\n";
	stackList.PrintAll();
	
	cout << "\nPop = " << stackList.Pop() << "\n\n";
	

	stackList.PrintAll();
	*/

#pragma endregion

#pragma region FixedStack

	//Stack List Implemented by Array so its Fixed Size

	/*
	FixedStack<int,5> fixedStackList;

	fixedStackList.Push(100);
	fixedStackList.Push(200);
	fixedStackList.Push(300);
	fixedStackList.Push(400);
	
	cout << "Top Value = " << fixedStackList.Peak() <<"\n";
	*/

#pragma endregion

#pragma region LinkedList

/*
LinkedList<string> linkedList;

linkedList.InsertNode("Mohammed");
linkedList.InsertNode("Salah");
linkedList.InsertNode("Hello");
linkedList.InsertNode("World");

linkedList.InsertNodeAtBegin("My Name is :");

linkedList.PrintAll();

*/


#pragma endregion

	return 0;
}
