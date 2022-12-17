#include <iostream>
#include "LinkedList.h"
#include "FixedStackList.h"
#include "DynamicStackList.h"
using namespace std;



int main()
{

#pragma region DynamicStackList

	//Stack List Implemented by LinkedList so its Dynamic Size

	
	DynamicStackList<int> stackList;

	stackList.Push(100);
	stackList.Push(200);
	stackList.Push(300);
	stackList.Push(400);

	//cout << "Top Value = " << stackList.Peak() <<"\n";
	stackList.PrintAll();
	
	cout << "\nPop = " << stackList.Pop() << "\n\n";
	

	stackList.PrintAll();


#pragma endregion

#pragma region FixedStackList

	//Stack List Implemented by Array so its Fixed Size

	/*
	FixedStackList<int,5> fixedStackList;

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
