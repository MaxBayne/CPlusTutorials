#ifndef ArrayList_H_
#define ArrayList_H_

/*
* ################### Information #################
* Define Items inside Array
* Dynamic Types
* Traversing
* Searching
* Sorting
* Merging
*/

namespace DataStructures
{

#pragma region Declearation

	template <typename T>
	class ArrayList
	{
	private:

		//Pointer of the Begin of Array
		T* _ArrayPtr;

		//Pointer For the First Item inside ArrayList
		T* _FirstPtr;

		//Pointer For the Last Item inside ArrayList
		T* _LastPtr;

		//Index Of First Item inside Array
		int _FirstIndex;

		//Index Of Last Item inside Array
		int _LastIndex;

		//Hold Items Count inside ArrayList
		int _Length;

		//Hold the Max Items can Array Hold
		int _Size;

	public:

		//Constructor
		ArrayList(int size);

		//Destrcutor
		~ArrayList();


		//Insert New Item inside ArrayList
		void Insert(T data);

		//Insert New Item inside ArrayList at Specific Index
		void Insert(int index,T data);

		//Delete Node inside ArrayList
		void DeleteByData(T data);

		//Delete item in specific index
		void DeleteByIndex(int index);

		//Print All Nodes
		void Display();

		//Resize Array Size
		void Enlarge(int newSize);

		//Merge Current Array with Another Array
		void Merge(ArrayList<T> other);



		//Search Item by Index and return the value , if not exist then return -1
		T SearchByIndex(int index);

		//Search Item by Value and return the index , if not exist then return -1
		T SearchByValue(T value);

		//Get the First Item inside ArrayList
		T* getFirst();

		//Get the Last Item inside ArrayList
		T* getLast();

		//Get the Count of Items inside ArrayList
		int getLength();

		//Get the Size of Array (Max Capacity)
		int getSize();

		//check if array is empty
		bool isEmpty();

		//check if array is Full
		bool isFull();
	};

#pragma endregion

#pragma region Defination

	//[Tested]
	//Constructor
	template <typename T>
	ArrayList<T>::ArrayList(int size)
	{
		_FirstPtr = nullptr;
		_LastPtr = nullptr;

		_FirstIndex = -1;
		_LastIndex = -1;

		_Size = size;
		_Length = 0;

		//Create Array by Dynamic Allocation Memory inside Heap Memory Section and Store Pointer to that array inside Stack Section

		_ArrayPtr = new T[size];
	}

	//[Tested]
	//Desctructor
	template <typename T>
	ArrayList<T>::~ArrayList()
	{
		if (_ArrayPtr != nullptr) 
		{
			//free(_ArrayPtr);
			//delete[]_ArrayPtr;
		}
	}


	//[Tested]
	//Insert New Item inside ArrayList
	template <typename T>
	void ArrayList<T>::Insert(T data)
	{
		//check if array full or not
		if (isFull()) 
		{
			std::cout << "Sorry Array overflow \n";
			return;
		}

		if (_Length<=0)
		{
			//if the item is the first item inside array
			_FirstPtr = _LastPtr;

			_FirstIndex = _LastIndex = 0;
		}
		else 
		{
			//if the item not the first item inside array

			_LastIndex++;
			
			_LastPtr = &_ArrayPtr[_LastIndex];

		}

		//Store data inside Array located inside Heap
		_ArrayPtr[_LastIndex] = data;

		//Increase the Length of Items
		_Length++;
	}

	//[Tested]
	//Insert New Item inside ArrayList at Specific Index
	template <typename T>
	void ArrayList<T>::Insert(int index, T data)
	{
		//check if array full or not
		if (isFull())
		{
			std::cout << "Sorry Array overflow \n";
			return;
		}

		//validate index number
		if (!(index >= 0 && index < _Size)) 
		{
			std::cout << "Sorry Invalid Index Number \n";
			return;
		}

		//Shift Right Items To Can Insert New data
		for (size_t i = _Length; i > index; i--)
		{
			_ArrayPtr[i] = _ArrayPtr[i - 1];
		}

		if (_Length <= 0)
		{
			//if the item is the first item inside array
			_FirstPtr = _LastPtr;

			_FirstIndex = _LastIndex = 0;
		}
		else
		{
			//if the item not the first item inside array

			_LastIndex++;

			_LastPtr = &_ArrayPtr[_LastIndex];

		}

		//Store data inside Array located inside Heap
		_ArrayPtr[index] = data;

		//Increase the Length of Items
		_Length++;
	}

	//[Tested]
	//Delete item inside ArrayList
	template <typename T>
	void ArrayList<T>::DeleteByData(T data)
	{
		//Search For data inside All Items
		for (size_t i = 0; i < _Length; i++)
		{
			if(_ArrayPtr[i]==data)
			{
				//Found Data index
				DeleteByIndex(i);

				return;
			}
		}
		
		std::cout << "Data not Exist \n";
	}

	//[Tested]
	//Delete item in specific index
	template <typename T>
	void ArrayList<T>::DeleteByIndex(int index)
	{
		
		//check if array empty or not
		if (isEmpty())
		{
			std::cout << "Sorry Array Empty \n";
			return;
		}

		//validate index number
		if (!(index >= 0 && index < _Size))
		{
			std::cout << "Sorry Invalid Index Number \n";
			return;
		}

		//Shift Left Items To Can Remove data
		for (size_t i = index; i < _Length-1; i++)
		{
			_ArrayPtr[i] = _ArrayPtr[i + 1];
		}

		if (_Length <= 0)
		{
			//if the item is the first item inside array
			_FirstPtr = _LastPtr;

			_FirstIndex = _LastIndex = 0;
		}
		else
		{
			//if the item not the first item inside array

			_LastIndex--;

			_LastPtr = &_ArrayPtr[_LastIndex];

		}

		//Decrease the Length of Items
		_Length--;

	}

	//[Tested]
	//Print All Nodes
	template <typename T>
	void ArrayList<T>::Display()
	{
		if (isEmpty())
		{
			std::cout << "Array is Empty";
		}
		else
		{
			std::cout << "Fixed Array Items \n";
			std::cout << "================= \n";

			for (size_t i = 0; i < _Length; i++)
			{
				std::cout << _ArrayPtr[i] << "\n";
			}
			
		}

	}

	//Increase the size of Array
	template <typename T>
	void ArrayList<T>::Enlarge(int newSize)
	{
		if (newSize <= 0 || newSize < _Size) 
		{
			std::cout << "Invalid new Size Range \n";
			return;
		}

		T* oldArrayPtr = _ArrayPtr;

		//Create new Dynamic Memory Allocation Array
		_ArrayPtr = new T[newSize];

		_Size = newSize;

		//Copy Old Array to New Array
		for (size_t i = 0; i < _Length; i++)
		{
			_ArrayPtr[i] = oldArrayPtr[i];
		}


		//Delete Old Array From Heap Memory
		delete[]oldArrayPtr;
	}

	//Merge Current Array with Another Array
	template <typename T>
	void ArrayList<T>::Merge(ArrayList<T> other)
	{
		//New Size
		int newSize = _Size + other.getSize();

		//Resize current array to carry its content and other content
		Enlarge(newSize);

		//Loop to store the other array content
		for (size_t i = 0; i < other.getLength(); i++)
		{
			Insert(other.SearchByIndex(i));
		}
	}




	//[Tested]
	//Search Item by Index and return the value , if not exist then return -1
	template <typename T>
	T ArrayList<T>::SearchByIndex(int index)
	{
		return _ArrayPtr[index];
	}

	//[Tested]
	//Search Item by Value and return the index , if not exist then return -1
	template <typename T>
	T ArrayList<T>::SearchByValue(T value)
	{
		for (size_t i = 0; i < _Length; i++)
		{
			if (_ArrayPtr[i] == value) 
			{
				//if value exist then return the index
				return i;
			}
		}

		//if not found then return -1
		return -1;
	}

	//[Tested]
	//Get the First Node inside ArrayList
	template <typename T>
	T* ArrayList<T>::getFirst()
	{
		return _FirstPtr;
	}

	//[Tested]
	//Get the Last Node inside ArrayList
	template <typename T>
	T* ArrayList<T>::getLast()
	{
		return _LastPtr;
	}


	//[Tested]
	//Get the Count of Nodes inside ArrayList
	template <typename T>
	int ArrayList<T>::getLength()
	{
		return _Length;
	}

	//[Tested]
	//Get the Size of Locations inside ArrayList
	template <typename T>
	int ArrayList<T>::getSize()
	{
		return _Size;
	}

	//[Tested]
	//check if array is empty
	template <typename T>
	bool ArrayList<T>::isEmpty()
	{
		return _Length <= 0;
	}

	//[Tested]
	//check if array is full
	template <typename T>
	bool ArrayList<T>::isFull()
	{
		return _Length == _Size;
	}

#pragma endregion

}

#endif // !ArrayList_H_


