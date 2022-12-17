#include "LinkedList.h"

#ifndef DYNAMICSTACKLIST_H_
#define DYNAMICSTACKLIST_H_
/*
* ################### Information #################
* Define Stack List Powered By LinkedList
* Dynamic List Items
* push item to stack
* pop item from stack
* peak current top item
* we will push item at the begin of stack
* we will pop item from the begin of stack
*/

/*
* ################### Delecrations #################
*/


template <typename T>
class DynamicStackList
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
	DynamicStackList();

	//Destrcutor
	~DynamicStackList();



	//Push Item inside StackList
	void Push(T data);

	//Pop Item from StackList
	T Pop();

	//Peak Top Item from StackList
	T Peak();

	//Print All Items
	void PrintAll();




	//Get the Top Item inside StackList
	T Top();

	//Get the Bottom Item inside StackList
	T Bottom();

	//Get the Count of Items inside StackList
	int Count();

};


/*
* ################### Definitions #################
*/



//Constructor
template <typename T>
DynamicStackList<T>::DynamicStackList()
{
	_Top = nullptr;
	_Bottom = nullptr;
}

//Desctructor
template <typename T>
DynamicStackList<T>::~DynamicStackList()
{
	//Empty Arrays From Memory
	/*if (_Array != NULL)
	{
		free(_Array);
	}
	*/
}




//Get the Count of Items inside DynamicStackList
template <typename T>
int DynamicStackList<T>::Count()
{
	return _LinkedList.Count();
}


//Get the Top Item inside DynamicStackList
template <typename T>
T DynamicStackList<T>::Top()
{
	return *_Top->Data;
}

//Get the Bottom Item inside DynamicStackList
template <typename T>
T DynamicStackList<T>::Bottom()
{
	return *_Bottom->Data;
}



//Push Item inside StackList
template <typename T>
void DynamicStackList<T>::Push(T data)
{
	//Store the data inside begin of LinkedList
	_LinkedList.InsertNodeAtBegin(data);


	//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
	_Top = _LinkedList.FirstNode();
	_Bottom = _LinkedList.LastNode();
}

//Pop Item from StackList
template <typename T>
T DynamicStackList<T>::Pop()
{
	//check if stack reach to lower count or not
	if (_LinkedList.Count() == 0)
	{
		std::cout << "Stack underflow \n";
		return -1;
	}

	T topValue = _Top->Data;

	//Remove the first Node inside LinkedList
	_LinkedList.DeleteNodeAtBegin();

	//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
	_Top = _LinkedList.FirstNode();
	

	if (_LinkedList.Count() == 0)
	{
		_Top = NULL;
		_Bottom = NULL;
	}

	//Reteurn the Value of Top Item
	return topValue;
}

//Peak Top Item from StackList
template <typename T>
T DynamicStackList<T>::Peak()
{
	return _Top->Data;
}

//Print All Items
template <typename T>
void DynamicStackList<T>::PrintAll()
{

	if (_LinkedList.Count() == 0)
	{
		std::cout << "List is Empty";
	}
	else
	{ 
		_LinkedList.PrintAll();
	}

}


#endif // !DYNAMICSTACKLIST_H_


