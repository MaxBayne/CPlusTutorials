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

namespace DataStructures
{

#pragma region Declerations

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

#pragma endregion

#pragma region Defeinations

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
		if (_Front != NULL) {
			return *_Front;
		}
		else {
			return NULL;
		}


		
	}

	//Get the Rear Item inside FixedSimpleQueue
	template <typename T, int MAXCOUNT>
	T FixedSimpleQueue<T, MAXCOUNT>::Rear()
	{
		if (_Rear != NULL) {
			return *_Rear;
		}
		else {
			return NULL;
		}


		
	}

	//Peak Top Item from FixedSimpleQueue
	template <typename T, int MAXCOUNT>
	T FixedSimpleQueue<T, MAXCOUNT>::Peak()
	{
		if (_Count == 0) {
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

	//Push Item inside the End of FixedSimpleQueue
	template <typename T, int MAXCOUNT>
	void FixedSimpleQueue<T, MAXCOUNT>::EnQueue(T data)
	{
		if (_Count == 0)
		{

			//if queue is empty

			//Update Index
			_FrontIndex = 0;
			_RearIndex = 0;

			//Update Pointer
			_Front = &_Array[_FrontIndex];
			_Rear = &_Array[_RearIndex];

			//Update Counter
			_Count = 1;

		}
		else if (_Count == MAXCOUNT)
		{
			//if queue is reached to the max capicty
			std::cout << "Queue Overflow \n";
			return;
		}
		else
		{
			//if queue has space inside it

			//Update Index
			_RearIndex++; //Index of the last Item Inserted inside queue

			//Update Pointer
			_Rear = &_Array[_RearIndex];

			//Update Counter
			_Count++;
		}


		//Store the data inside Array inside position Rear Index
		_Array[_RearIndex] = data;
	}

	//Pop Item from the begin of FixedSimpleQueue
	template <typename T, int MAXCOUNT>
	T FixedSimpleQueue<T, MAXCOUNT>::DeQueue()
	{
		//check if stack reach to lower count or not
		if (_Count == 0)
		{
			std::cout << "Queue is Empty \n";
			return 0;
		}

		//Store First item inside Queue
		T frontValue = *_Front;

		//Clear Front Item by Zero
		*_Front = 0;

		//Update Counter of Items
		_Count--;

		//Update Index
		_FrontIndex++;

		//Update Pointer of Top,Bottom to Refere to the Top Item , Bottom Item
		_Front = &_Array[_FrontIndex];

		//Reteurn the Value of Front Item
		return frontValue;
	}

	//Print All Items
	template <typename T, int MAXCOUNT>
	void FixedSimpleQueue<T, MAXCOUNT>::PrintAll()
	{

		if (_Count == 0)
		{
			std::cout << "List is Empty";
		}
		else
		{
			for (size_t i = _FrontIndex; i <= _RearIndex; i++)
			{
				std::cout << _Array[i] << "\n";
			}
		}


	}

#pragma endregion

}

#endif // !FIXEDSIMPLEQUEUE_H_


