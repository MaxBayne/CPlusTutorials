#ifndef FIXEDSTACK_H_
#define FIXEDSTACK_H_
/*
* ################### Information #################
* Define Stack List Powered By Arrays
* Fixed List Items
* push item to stack
* pop item from stack
* peak current top item
*/

/*
* ################### Delecrations #################
*/


template <typename T,int MAXCOUNT>
class FixedStack
{
private:

	//Array To Store Items of StackList
	T _Array[MAXCOUNT];

	//Pointer For the Top Item inside StackList
	T* _Top;
	//Pointer For the Bottom Item inside StackList
	T* _Bottom;

	//Current Items Count inside StackList
	int _Count;

public:

	//Constructor
	FixedStack();

	//Destrcutor
	~FixedStack();



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

	//get the Max Count that can store inside StackList
	int MaxCount();
};


/*
* ################### Definitions #################
*/



//Constructor
template <typename T, int MAXCOUNT>
FixedStack<T,MAXCOUNT>::FixedStack()
{
	_Count = -1;
	_Top = nullptr;
	_Bottom = nullptr;
}

//Desctructor
template <typename T, int MAXCOUNT>
FixedStack<T,MAXCOUNT>::~FixedStack()
{
	//Empty Arrays From Memory
	/*if (_Array != NULL) 
	{
		free(_Array);
	}
	*/
}




//Get the Count of Items inside FixedStack
template <typename T, int MAXCOUNT>
int FixedStack<T, MAXCOUNT>::Count()
{
	return _Count+1;
}

//get the Max Count that can store inside StackList
template <typename T, int MAXCOUNT>
int FixedStack<T, MAXCOUNT>::MaxCount()
{
	return MAXCOUNT;
}

//Get the Top Item inside FixedStack
template <typename T, int MAXCOUNT>
T FixedStack<T, MAXCOUNT>::Top()
{
	return *_Top;
}

//Get the Bottom Item inside FixedStack
template <typename T, int MAXCOUNT>
T FixedStack<T, MAXCOUNT>::Bottom()
{
	return *_Bottom;
}



//Push Item inside StackList
template <typename T, int MAXCOUNT>
void FixedStack<T, MAXCOUNT>::Push(T data)
{
	//Update Counter of Items
	_Count++;

	//check if stack reach to max count or not
	if (_Count == MAXCOUNT) 
	{
		std::cout << "Stack Overflow \n";
		return;
	}

	//Store the data inside Array inside position count
	_Array[_Count] = data;

	//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
	_Top = &_Array[_Count];
	_Bottom = &_Array[0];
}

//Pop Item from StackList
template <typename T, int MAXCOUNT>
T FixedStack<T, MAXCOUNT>::Pop()
{
	//check if stack reach to lower count or not
	if (_Count == -1)
	{
		std::cout << "Stack underflow \n";
		return -1;
	}

	T* top = _Top;


	//Update Counter of Items
	_Count--;

	//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
	_Top = &_Array[_Count];
	_Bottom = &_Array[0];

	if (_Count == -1) 
	{
		_Top = NULL;
		_Bottom = NULL;
	}

	//Reteurn the Value of Top Item
	return *top;
}

//Peak Top Item from StackList
template <typename T, int MAXCOUNT>
T FixedStack<T, MAXCOUNT>::Peak()
{
	return *_Top;
}

//Print All Items
template <typename T, int MAXCOUNT>
void FixedStack<T, MAXCOUNT>::PrintAll()
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


#endif // !FIXEDSTACK_H_


