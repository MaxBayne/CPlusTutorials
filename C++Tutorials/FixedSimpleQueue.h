#ifndef FIXEDSIMPLEQUEUE_H_
#define FIXEDSIMPLEQUEUE_H_
/*
* ################### Information #################
* Implement Rule First In - First Out
* Define Simple Queue Powered By Arrays
* Fixed Items
* Enqueue Item inside Queue
* Dequeue Item from Queue
* Hold First Item by Front
* Hold Last Item by Rear
*/

/*
* ################### Delecrations #################
*/


template <typename T, int MAXCOUNT>
class FixedSimpleQueue
{
private:

	//Array To Store Items of FixedSimpleQueue
	T _Array[MAXCOUNT];

	//Pointer For the First Item inside FixedSimpleQueue
	T* _Front;
	//Pointer For the Last Item inside FixedSimpleQueue
	T* _Rear;

	//Front Index
	int _FrontIndex;

	//Rear Index
	int _RearIndex;

	//Current Items Count inside FixedSimpleQueue
	int _Count;

public:

	//Constructor
	FixedSimpleQueue();

	//Destrcutor
	~FixedSimpleQueue();



	//Add Item inside FixedSimpleQueue
	void EnQueue(T data);

	//Out Item from FixedSimpleQueue
	T DeQueue();

	//Peak Front Item from FixedSimpleQueue
	T Peak();

	//Print All Items
	void PrintAll();




	//Get the Front Item inside FixedSimpleQueue
	T Front();

	//Get the Bottom Item inside FixedSimpleQueue
	T Rear();

	//Get the Count of Items inside FixedSimpleQueue
	int Count();

	//get the Max Count that can store inside FixedSimpleQueue
	int MaxCount();
};


/*
* ################### Definitions #################
*/



//Constructor
template <typename T, int MAXCOUNT>
FixedSimpleQueue<T, MAXCOUNT>::FixedSimpleQueue()
{
	_Count = 0;
	_Front = nullptr;
	_Rear = nullptr;
	_FrontIndex = -1;
	_RearIndex = -1;
}

//Desctructor
template <typename T, int MAXCOUNT>
FixedSimpleQueue<T, MAXCOUNT>::~FixedSimpleQueue()
{
	//Empty Arrays From Memory
	/*if (_Array != NULL)
	{
		free(_Array);
	}
	*/
}




//Get the Count of Items inside FixedSimpleQueue
template <typename T, int MAXCOUNT>
int FixedSimpleQueue<T, MAXCOUNT>::Count()
{
	return _Count;
}

//get the Max Count that can store inside FixedSimpleQueue
template <typename T, int MAXCOUNT>
int FixedSimpleQueue<T, MAXCOUNT>::MaxCount()
{
	return MAXCOUNT;
}

//Get the Front Item inside FixedSimpleQueue
template <typename T, int MAXCOUNT>
T FixedSimpleQueue<T, MAXCOUNT>::Front()
{
	return *_Front;
}

//Get the Rear Item inside FixedSimpleQueue
template <typename T, int MAXCOUNT>
T FixedSimpleQueue<T, MAXCOUNT>::Rear()
{
	return *_Rear;
}



//Peak Top Item from FixedSimpleQueue
template <typename T, int MAXCOUNT>
T FixedSimpleQueue<T, MAXCOUNT>::Peak()
{
	return *_Front;
}

//Push Item inside FixedSimpleQueue
template <typename T, int MAXCOUNT>
void FixedSimpleQueue<T, MAXCOUNT>::EnQueue(T data)
{
	//Update Counter of Items
	_Count++;

	//Update Index 
	_FrontIndex++;

	//check if Queue reach to max count or not
	if (_Count+1 == MAXCOUNT)
	{
		std::cout << "Queue Overflow \n";
		return;
	}

	//Store the data inside Array inside position count
	_Array[_Count] = data;

	//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
	_Front = &_Array[_Count];
	_Rear = &_Array[0];
}

//Pop Item from FixedSimpleQueue
template <typename T, int MAXCOUNT>
T FixedSimpleQueue<T, MAXCOUNT>::DeQueue()
{
	//check if stack reach to lower count or not
	if (_Count == -1)
	{
		std::cout << "Stack underflow \n";
		return -1;
	}

	T* top = _Front;


	//Update Counter of Items
	_Count--;

	//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
	_Front = &_Array[_Count];
	_Rear = &_Array[0];

	if (_Count == -1)
	{
		_Front = NULL;
		_Rear = NULL;
	}

	//Reteurn the Value of Top Item
	return *top;
}

//Print All Items
template <typename T, int MAXCOUNT>
void FixedSimpleQueue<T, MAXCOUNT>::PrintAll()
{

	if (_Count < 0)
	{
		std::cout << "List is Empty";
	}
	else
	{
		for (size_t i = 0; i <= _Count; i++)
		{
			std::cout << _Array[i] << "\n";
		}
	}


}


#endif // !FIXEDSIMPLEQUEUE_H_


