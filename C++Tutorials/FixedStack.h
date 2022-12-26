#ifndef FIXEDSTACK_H_
#define FIXEDSTACK_H_

/*
	* ################### Information #################
	* Define Stack List Powered By Arrays
	* Implement Rule Last in First Out (LIFO)
	* Fixed List Items
	* push item to stack
	* pop item from stack
	* peak current top item
*/


namespace DataStructures
{

#pragma region Decleration

	template <typename T, int MAXCOUNT>
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

		//get the Max Count that can store inside StackList
		int MaxCount();

		//check if stack is Empty
		bool IsEmpty();

		//check if stack is Full
		bool IsFull();

		//check if stack has item value or not
		bool IsExist(T data);
	};

#pragma endregion

#pragma region Definations

	//Constructor
	template <typename T, int MAXCOUNT>
	FixedStack<T, MAXCOUNT>::FixedStack()
	{
		_Count = 0;
		_Top = nullptr;
		_Bottom = nullptr;
	}

	//Desctructor
	template <typename T, int MAXCOUNT>
	FixedStack<T, MAXCOUNT>::~FixedStack()
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
		return _Count;
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
		if (_Top != NULL) {
			return *_Top;
		}
		else {
			return NULL;
		}
		
	}

	//Get the Bottom Item inside FixedStack
	template <typename T, int MAXCOUNT>
	T FixedStack<T, MAXCOUNT>::Bottom()
	{
		if (_Bottom != NULL) {
			return *_Bottom;
		}
		else {
			return NULL;
		}
		
	}


	//Push Item inside StackList
	template <typename T, int MAXCOUNT>
	void FixedStack<T, MAXCOUNT>::Push(T data)
	{
		//check if stack reach to max count or not
		if (IsFull())
		{
			std::cout << "Stack Overflow \n";
			return;
		}

		//Update Counter of Items
		_Count++;

		//Store the data inside Array inside position count
		_Array[_Count-1] = data;

		//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
		_Top = &_Array[_Count-1];
		_Bottom = &_Array[0];
	}

	//Pop Item from StackList
	template <typename T, int MAXCOUNT>
	T FixedStack<T, MAXCOUNT>::Pop()
	{
		//check if stack reach to lower count or not
		if (IsEmpty())
		{
			std::cout << "Stack underflow \n";
			return -1;
		}

		T* top = _Top;


		//Update Counter of Items
		_Count--;

		//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
		_Top = &_Array[_Count-1];
		_Bottom = &_Array[0];

		if (IsEmpty())
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
		if (_Top != NULL) {
			return *_Top;
		}
		else {
			return NULL;
		}

		
	}

	//Print All Items in order of push
	template <typename T, int MAXCOUNT>
	void FixedStack<T, MAXCOUNT>::DisplayReverse()
	{
		if (IsEmpty())
		{
			std::cout << "List is Empty";
		}
		else
		{
			for (int i = 0; i < _Count; i++)
			{
				std::cout << _Array[i] << "\n";
			}
		}
	}

	//Print All Items in order of pop
	template <typename T, int MAXCOUNT>
	void FixedStack<T, MAXCOUNT>::Display()
	{
		if (IsEmpty())
		{
			std::cout << "List is Empty";
		}
		else
		{
			for (int i = _Count-1; i >= 0; i--)
			{
				std::cout << _Array[i] << "\n";
			}
		}
	}

	//check if stack is Empty
	template <typename T, int MAXCOUNT>
	bool FixedStack<T, MAXCOUNT>::IsEmpty()
	{
		return _Count == 0;
	}

	//check if stack is Full
	template <typename T, int MAXCOUNT>
	bool FixedStack<T, MAXCOUNT>::IsFull()
	{
		return _Count == MAXCOUNT;
	}

	//check if stack has item value or not
	template <typename T, int MAXCOUNT>
	bool FixedStack<T, MAXCOUNT>::IsExist(T data)
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			for (int i = 0; i < _Count; i++)
			{
				if (_Array[i] == data)
					return true;
				
			}
		}

		return false;
	}

#pragma endregion

}

#endif // !FIXEDSTACK_H_


