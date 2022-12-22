#include "LinkedList.h"

#ifndef DynamicQueue_H_
#define DynamicQueue_H_

/*
* ################### Information #################
* Define Queue List Powered By LinkedList
* Dynamic List Items
* Enqueue item to End (Rear) of Queue
* Dequeue item from Front of Queue
* peak current Front item
* No Limits for items count
* Implement Rule of First-In First-Out
* Work Like Simple Queue but with no limits
*/

namespace DataStructures
{

#pragma region Decleration

	template <typename T>
	class DynamicQueue
	{
	private:

		//Linked List To Store Items of Queue
		LinkedList<T> _LinkedList;

		//Pointer For the Front (First) Item inside Queue
		Node<T>* _FrontPtr;
		//Pointer For the Rear (Last) Item inside Queue
		Node<T>* _RearPtr;

	public:

		//Constructor
		DynamicQueue();

		//Destrcutor
		~DynamicQueue();



		//Push Item inside End of Queue
		void Enqueue(T data);

		//Pop Item from start of Queue
		T Dequeue();

		//Get Front Item Value from Queue
		T Peak();

		//Print All Items Order by the Dequeue sorting
		void PrintAll();



		//Get the Top Item inside Queue
		T Front();

		//Get the Bottom Item inside Queue
		T Rear();

		//Get the Count of Items inside Queue
		int Count();

		//Check if Queue is Empty
		bool IsEmpty();

	};

#pragma endregion

#pragma region Definations

	//Constructor
	template <typename T>
	DynamicQueue<T>::DynamicQueue()
	{
		_FrontPtr = nullptr;
		_RearPtr = nullptr;
	}

	//Desctructor
	template <typename T>
	DynamicQueue<T>::~DynamicQueue()
	{
		//Empty Arrays From Memory
		/*if (_Array != NULL)
		{
			free(_Array);
		}
		*/
	}




	//Get the Count of Items inside DynamicQueue
	template <typename T>
	int DynamicQueue<T>::Count()
	{
		return _LinkedList.Count();
	}


	//Get the Top Item inside DynamicQueue
	template <typename T>
	T DynamicQueue<T>::Front()
	{
		if (_FrontPtr != NULL) {
			return _FrontPtr->Data;
		}
		else {
			return NULL;
		}

		
	}

	//Get the Bottom Item inside DynamicQueue
	template <typename T>
	T DynamicQueue<T>::Rear()
	{
		if (_RearPtr != NULL) {
			return _RearPtr->Data;
		}
		else {
			return NULL;
		}

	}

	//Check if Queue is Empty
	template <typename T>
	bool DynamicQueue<T>::IsEmpty()
	{
		return _LinkedList.Count() == 0;
	}

	//Push Item inside Queue
	template <typename T>
	void DynamicQueue<T>::Enqueue(T data)
	{
		//Store the data inside LinkedList
		_LinkedList.InsertNode(data);


		//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
		_FrontPtr = _LinkedList.FirstNode();
		_RearPtr = _LinkedList.LastNode();
	}

	//Pop Item from Queue
	template <typename T>
	T DynamicQueue<T>::Dequeue()
	{
		//check if queue reach to lower count or not
		if (IsEmpty())
		{
			std::cout << "Queue Empty \n";
			return -1;
		}

		T topValue = _FrontPtr->Data;

		//Remove the first Node inside LinkedList
		_LinkedList.DeleteNodeAtBegin();

		//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
		_FrontPtr = _LinkedList.FirstNode();


		if (IsEmpty())
		{
			_FrontPtr = NULL;
			_RearPtr = NULL;
		}

		//Reteurn the Value of Top Item
		return topValue;
	}

	//Peak Top Item from Queue
	template <typename T>
	T DynamicQueue<T>::Peak()
	{
		if (_FrontPtr != NULL) 
		{
			return _FrontPtr->Data;
		}
		return NULL;
	}

	//Print All Items
	template <typename T>
	void DynamicQueue<T>::PrintAll()
	{

		if (IsEmpty())
		{
			std::cout << "Queue is Empty";
		}
		else
		{
			_LinkedList.PrintAll();
		}

	}

#pragma endregion

}

#endif // !DynamicQueue_H_


