#include <iostream>
#include "LinkedList.h"
#include "FixedStack.h"
#include "DynamicStack.h"
#include "FixedSimpleQueue.h"
#include "FixedCircularQueue.h"
#include "DynamicQueue.h"
#include "ArrayList.h"

using namespace std;
using namespace DataStructures;


int main()
{
#pragma region ArrayList

	/*
	ArrayList<int> myArray(3);

	myArray.Insert(10);
	myArray.Insert(20);
	myArray.Insert(30);


	myArray.Display();

	cout << "Array Length = " << myArray.getLength() << endl;
	cout << "Array Size = " << myArray.getSize() << endl;
	*/

#pragma endregion

#pragma region DynamicQueue

	//Dynamic Queue Implemented by Linked List
	/*
	DynamicQueue<int> dynamicQueue;

	dynamicQueue.Enqueue(100);
	dynamicQueue.Enqueue(200);
	dynamicQueue.Enqueue(300);
	dynamicQueue.Enqueue(400);
	dynamicQueue.Enqueue(500);


	cout << "----------------- \n";
	dynamicQueue.PrintAll();
	cout << "----------------- \n";

	cout << "DeQueue = " << dynamicQueue.Dequeue() << "\n";
	cout << "DeQueue = " << dynamicQueue.Dequeue() << "\n";

	cout << "----------------- \n";
	dynamicQueue.PrintAll();
	cout << "----------------- \n";


	cout << "Count = " << dynamicQueue.Count() <<"\n";
	cout << "Peak = " << dynamicQueue.Peak() << "\n";
	cout << "Front = " << dynamicQueue.Front() << "\n";
	cout << "Rear = " << dynamicQueue.Rear() << "\n";
	
	
	*/

#pragma endregion

#pragma region FixedCircularQueue

	//Circular Queue Implemented by Array so its Fixed Size

	/*
	
	FixedCircularQueue<int,5> fixedCircularQueue;

	fixedCircularQueue.EnQueue(100);
	fixedCircularQueue.EnQueue(200);
	fixedCircularQueue.EnQueue(300);
	fixedCircularQueue.EnQueue(400);
	fixedCircularQueue.EnQueue(500);
	

	cout << "DeQueue = " << fixedCircularQueue.DeQueue() << "\n";
	fixedCircularQueue.EnQueue(600);
	cout << "----------------- \n";
	fixedCircularQueue.PrintAll();
	cout << "----------------- \n";

	cout << "Count = " << fixedCircularQueue.Count() <<"\n";
	cout << "Peak = " << fixedCircularQueue.Peak() << "\n";
	cout << "Front = " << fixedCircularQueue.Front() << "\n";
	cout << "Rear = " << fixedCircularQueue.Rear() << "\n";

	*/

#pragma endregion

#pragma region FixedSimpleQueue

	//Simple Queue Implemented by Array so its Fixed Size

	/*
	FixedSimpleQueue<int,5> fixedSimpleQueue;

	fixedSimpleQueue.EnQueue(100);
	fixedSimpleQueue.EnQueue(200);
	fixedSimpleQueue.EnQueue(300);
	fixedSimpleQueue.EnQueue(400);
	fixedSimpleQueue.EnQueue(500);
	
	cout << "DeQueue = " << fixedSimpleQueue.DeQueue() << "\n";
	
	cout << "----------------- \n";
	fixedSimpleQueue.PrintAll();
	cout << "----------------- \n";

	cout << "Count = " << fixedSimpleQueue.Count() <<"\n";
	cout << "Front = " << fixedSimpleQueue.Front() << "\n";
	cout << "Rear = " << fixedSimpleQueue.Rear() << "\n";
	cout << "Peak = " << fixedSimpleQueue.Peak() << "\n";
	*/
	
	

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
