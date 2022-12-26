#include "LinkedList.h"

#ifndef DynamicStack_H_
#define DynamicStack_H_

/*
* ################### Information #################
* Define Stack List Powered By LinkedList
* Implement Rule Last in First Out (LIFO)
* Dynamic List Items
* push item to stack
* pop item from stack
* peak current top item
* we will push item at the begin of stack
* we will pop item from the begin of stack
*/

namespace DataStructures
{

#pragma region Decleration

template <typename T>
class DynamicStack
{
private:

	//Linked List To Store Items of StackList
	LinkedList<T> _LinkedList;

	//Pointer For the Top Item inside StackList
	Node<T>* _Top;
	//Pointer For the Bottom Item inside StackList
	Node<T>* _Bottom;

public:

	//Constructor
	DynamicStack();

	//Destrcutor
	~DynamicStack();



	//Push Item inside StackList
	void Push(T data);

	//Pop Item from StackList
	T Pop();

	//Peak Top Item from StackList
	T Peak();

	//Print All Items in order of pop
	void Display();

	//Print All Items in order of push
	void DisplayReverse();


	//Get the Top Item inside StackList
	T Top();

	//Get the Bottom Item inside StackList
	T Bottom();

	//Get the Count of Items inside StackList
	int Count();

	//check if stack is Empty
	bool IsEmpty();

	//check if stack has item value or not
	bool IsExist(T data);

};

#pragma endregion

#pragma region Definations

//Constructor
template <typename T>
DynamicStack<T>::DynamicStack()
{
	_Top = nullptr;
	_Bottom = nullptr;
}

//Desctructor
template <typename T>
DynamicStack<T>::~DynamicStack()
{
	//Empty Arrays From Memory
	/*if (_Array != NULL)
	{
		free(_Array);
	}
	*/
}




//Get the Count of Items inside DynamicStack
template <typename T>
int DynamicStack<T>::Count()
{
	return _LinkedList.getCount();
}


//Get the Top Item inside DynamicStack
template <typename T>
T DynamicStack<T>::Top()
{
	if (_Top != NULL) {
		return _Top->Value;
	}
	else {
		return NULL;
	}
}

//Get the Bottom Item inside DynamicStack
template <typename T>
T DynamicStack<T>::Bottom()
{
	if (_Bottom != NULL) {
		return _Bottom->Value;
	}
	else {
		return NULL;
	}


	
}



//Push Item inside StackList
template <typename T>
void DynamicStack<T>::Push(T data)
{
	//Store the data inside begin of LinkedList
	_LinkedList.InsertBegin(data);


	//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
	_Top = _LinkedList.FirstNode();
	_Bottom = _LinkedList.LastNode();
}

//Pop Item from StackList
template <typename T>
T DynamicStack<T>::Pop()
{
	//check if stack reach to lower count or not
	if (IsEmpty())
	{
		std::cout << "Stack underflow \n";
		return -1;
	}

	T topValue = _Top->Value;

	//Remove the first Node inside LinkedList
	_LinkedList.DeleteBegin();

	//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
	_Top = _LinkedList.FirstNode();
	

	if (IsEmpty())
	{
		_Top = NULL;
		_Bottom = NULL;
	}

	//Reteurn the Value of Top Item
	return topValue;
}

//Peak Top Item from StackList
template <typename T>
T DynamicStack<T>::Peak()
{
	if (_Top != NULL) {
		return _Top->Value;
	}
	else {
		return NULL;
	}


	
}

//Print All Items
template <typename T>
void DynamicStack<T>::Display()
{

	if (IsEmpty())
	{
		std::cout << "List is Empty";
	}
	else
	{ 
		_LinkedList.Display();
	}

}


//Print All Items in order of push
template <typename T>
void DynamicStack<T>::DisplayReverse()
{
	if (IsEmpty())
	{
		std::cout << "List is Empty";
	}
	else
	{
		_LinkedList.DisplayReverse();
	}
}

//check if stack is Empty
template <typename T>
bool DynamicStack<T>::IsEmpty()
{
	return _LinkedList.isEmpty();
}


//check if stack has item value or not
template <typename T>
bool DynamicStack<T>::IsExist(T data)
{
	return _LinkedList.isExist(data);
}


#pragma endregion

}

#endif // !DynamicStack_H_


