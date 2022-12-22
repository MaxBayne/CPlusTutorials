#ifndef FIXEDCIRCULARQUEUE_H_
#define FIXEDCIRCULARQUEUE_H_

/*
* ################### Information #################
* Implement Rule First In - First Out
* Define Circular Queue Powered By Arrays
* Fixed Items
* Heal All Issues inside FixedSimpleQueue
* Reuse Empty Position inside Array
* Enqueue Item inside Queue
* Dequeue Item from Queue
* Hold First Item by Front
* Hold Last Item by Rear
*/


namespace DataStructures
{
	
#pragma region Decleration

	template <typename T, int MAXCOUNT>
	class FixedCircularQueue
	{
	private:

		//Array To Store Items of FixedCircularQueue
		T _Array[MAXCOUNT];

		//Pointer For the First Item inside FixedCircularQueue
		T* _Front;
		//Pointer For the Last Item inside FixedCircularQueue
		T* _Rear;

		//Front Index
		int _FrontIndex;

		//Rear Index
		int _RearIndex;

		//Current Items Count inside FixedCircularQueue
		int _Count;

	public:

		//Constructor
		FixedCircularQueue();

		//Destrcutor
		~FixedCircularQueue();



		//Add Item to Last FixedCircularQueue
		void EnQueue(T data);

		//Out Item from Front FixedCircularQueue
		T DeQueue();

		//Peak Front Item from FixedCircularQueue
		T Peak();

		//Print All Items Order by Out Position
		void PrintAll();




		//Get the Front Item inside FixedCircularQueue
		T Front();

		//Get the Bottom Item inside FixedCircularQueue
		T Rear();

		//Get the Count of Items inside FixedCircularQueue
		int Count();

		//get the Max Count that can store inside FixedCircularQueue
		int MaxCount();

		//Check if Queue is Empty , mean Count = 0
		bool IsEmpty();

		//Check if Queue is Full , mean Count = MaxCount
		bool IsFull();

		//Check if Rear Point to the End of Queue
		bool IsRearAtEndOfQueue();
	};

#pragma endregion

#pragma region Definations

	//Constructor
	template <typename T, int MAXCOUNT>
	FixedCircularQueue<T, MAXCOUNT>::FixedCircularQueue()
	{
		_Count = 0;
		_Front = nullptr;
		_Rear = nullptr;
		_FrontIndex = -1;
		_RearIndex = -1;
	}

	//Desctructor
	template <typename T, int MAXCOUNT>
	FixedCircularQueue<T, MAXCOUNT>::~FixedCircularQueue()
	{
		//Empty Arrays From Memory
		/*if (_Array != NULL)
		{
			free(_Array);
		}
		*/
	}


	//Get the Count of Items inside FixedCircularQueue
	template <typename T, int MAXCOUNT>
	int FixedCircularQueue<T, MAXCOUNT>::Count()
	{
		return _Count;
	}

	//get the Max Count that can store inside FixedCircularQueue
	template <typename T, int MAXCOUNT>
	int FixedCircularQueue<T, MAXCOUNT>::MaxCount()
	{
		return MAXCOUNT;
	}

	//Get the Front Item inside FixedCircularQueue
	template <typename T, int MAXCOUNT>
	T FixedCircularQueue<T, MAXCOUNT>::Front()
	{
		if (_Front != NULL) {
			return *_Front;
		}
		else {
			return NULL;
		}

		
	}

	//Get the Rear Item inside FixedCircularQueue
	template <typename T, int MAXCOUNT>
	T FixedCircularQueue<T, MAXCOUNT>::Rear()
	{
		if (_Rear != NULL) {
			return *_Rear;
		}
		else {
			return NULL;
		}

		
	}

	//Peak Top Item from FixedCircularQueue
	template <typename T, int MAXCOUNT>
	T FixedCircularQueue<T, MAXCOUNT>::Peak()
	{
		if (IsEmpty()) {
			std::cout << "Queue is EMpty \n";
			return -1;
		}


		if (_Front != NULL) {
			return *_Front;
		}
		else {
			return NULL;
		}


		
	}

	//Push Item inside the End of FixedCircularQueue
	template <typename T, int MAXCOUNT>
	void FixedCircularQueue<T, MAXCOUNT>::EnQueue(T data)
	{
		//if queue is reached to the max capicty
		if (IsFull())
		{
			//std::cout << "Queue Overflow \n";

			throw std::overflow_error::overflow_error("Queue Overflow");

			return;
		}

		//if queue is empty
		if (IsEmpty())
		{
			//Update Index
			_FrontIndex = 0;
			_RearIndex = 0;

			//Update Pointer
			_Front = &_Array[_FrontIndex];
			_Rear = &_Array[_RearIndex];

			//Store the data inside Array inside position Rear Index
			_Array[_RearIndex] = data;

			//Update Counter
			_Count++;
		}
		else
		{
			//if queue has space inside it


			//check if rear at end of queue mean will be moved to the front of queue because this is circular queue

			if (IsRearAtEndOfQueue()) 
			{
				//Update Index
				_RearIndex = 0;
			}
			else
			{
				//Update Index
				_RearIndex++; //Index of the last Item Inserted inside queue

			}
			
			//Store the data inside Array inside position Rear Index
			_Array[_RearIndex] = data;

			//Update Pointer
			_Rear = &_Array[_RearIndex];

			//Update Counter
			_Count++;

		}
		
	}

	//Pop Item from the begin of FixedCircularQueue
	template <typename T, int MAXCOUNT>
	T FixedCircularQueue<T, MAXCOUNT>::DeQueue()
	{
		//check if stack reach to lower count or not
		if (IsEmpty())
		{
			std::cout << "Queue is Empty \n";
			return -1;
		}

		//Store First item inside Queue
		T frontValue = *_Front;

		//Clear Front Item by Zero
		*_Front = 0;

		//Update Counter of Items
		_Count--;

		//Update Index
		if (IsEmpty())
		{
			//Queue become Empty
			_FrontIndex=-1;
			_RearIndex = -1;

			_Front = NULL;
			_Rear = NULL;
		}
		else 
		{
			//queue still has value
			_FrontIndex++;

			//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
			 _Front= &_Array[_FrontIndex];
		}
		

		

		//Reteurn the Value of Front Item
		return frontValue;
	}

	//Print All Items
	template <typename T, int MAXCOUNT>
	void FixedCircularQueue<T, MAXCOUNT>::PrintAll()
	{

		if (IsEmpty())
		{
			std::cout << "List is Empty";
		}
		else
		{
			if (_FrontIndex <= _RearIndex) 
			{
				for (size_t i = _FrontIndex; i <= _RearIndex; i++)
				{
					std::cout << _Array[i] << " [" << i << "]" << "\n";
				}
			}
			else 
			{
				for (size_t i = _FrontIndex; i < MAXCOUNT; i++)
				{
					std::cout << _Array[i] << " [" << i << "]" << "\n";
				}

				for (size_t i = 0; i <= _RearIndex; i++)
				{
					std::cout << _Array[i] << " [" << i << "]" << "\n";
				}
			}
			
		}

	}


	//Check if Queue is Empty , mean Count = 0
	template <typename T, int MAXCOUNT>
	bool FixedCircularQueue<T, MAXCOUNT>::IsEmpty()
	{
		return _Count == 0;

	}

	//Check if Queue is Full , mean Count = MaxCount
	template <typename T, int MAXCOUNT>
	bool FixedCircularQueue<T, MAXCOUNT>::IsFull()
	{
		return _Count == MAXCOUNT;
	}

	//Check if Rear Point to the End of Queue
	template <typename T, int MAXCOUNT>
	bool FixedCircularQueue<T, MAXCOUNT>::IsRearAtEndOfQueue()
	{
		return _RearIndex == MAXCOUNT - 1;
	}

#pragma endregion

}

#endif // !FIXEDCIRCULARQUEUE_H_


