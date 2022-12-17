#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
/*
* ################### Information #################
* Define Nodes
* Dynamic List
* Dynamic Types
* its more power full than array but array is the fastest way
* easy insert , remove nodes from list
*/

/*
* ################### Delecrations #################
*/

template <typename T>
struct Node
{
	T Data;

	Node<T>* PreviousNode;
	Node<T>* NextNode;
};


template <typename T>
class LinkedList
{
private:

	//Pointer For the First Node inside LinkedList
	Node<T>* _FirstNode;

	//Pointer For the Last Node inside LinkedList
	Node<T>* _LastNode;

	//Hold Nodes Count inside LinkedList
	int _Count;


public:

	//Constructor
	LinkedList();

	//Destrcutor
	~LinkedList();


	//Insert New Node inside LinkedList
	void InsertNode(T data);

	//Insert New Node at Begin of LinkedList
	void InsertNodeAtBegin(T data);

	//Delete Node inside LinkedList
	void DeleteNode(T data);

	//Delete Node At Begin of LinkedList
	void DeleteNodeAtBegin();

	//Print All Nodes
	void PrintAll();


	//Get the Count of Nodes inside LinkedList
	int Count();

	//Get the First Node inside LinkedList
	Node<T>* FirstNode();

	//Get the Last Node inside LinkedList
	Node<T>* LastNode();

};


/*
* ################### Definitions #################
*/



//Constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	_FirstNode = nullptr;
	_LastNode = nullptr;

	_Count = 0;
}



//Desctructor
template <typename T>
LinkedList<T>::~LinkedList()
{

}



//Get the Count of Nodes inside LinkedList
template <typename T>
int LinkedList<T>::Count()
{
	return _Count;
}


//Get the First Node inside LinkedList
template <typename T>
Node<T>* LinkedList<T>::FirstNode()
{
	return _FirstNode;
}


//Get the Last Node inside LinkedList
template <typename T>
Node<T>* LinkedList<T>::LastNode()
{
	return _LastNode;
}



//Insert New Node inside LinkedList
template <typename T>
void LinkedList<T>::InsertNode(T data)
{
	//Create New Node inside Memory and Save its Address inside Pointer newNode
	Node<T>* newNodePtr = new Node<T>();

	newNodePtr->Data = data;
	newNodePtr->NextNode = nullptr;
	newNodePtr->PreviousNode = _LastNode;


	//Link New Node to the Last Node inside Linked List

	if (_LastNode == nullptr)
	{
		//if the node is the first node inside LinkedList
		_FirstNode = newNodePtr;
		_LastNode = newNodePtr;
	}
	else
	{
		//if new node not the first node inside LinkedList

		//Update the NextNode inside the last Node
		_LastNode->NextNode = newNodePtr;

		//Make Last Node Refere to the new last Node
		_LastNode = newNodePtr;
	}

	//Increase the Counter of Nodes
	_Count++;
}

//Insert New Node at Begin of LinkedList
template <typename T>
void LinkedList<T>::InsertNodeAtBegin(T data)
{
	//Create New Node inside Memory and Save its Address inside Pointer newNode
	Node<T>* newNodePtr = new Node<T>();

	newNodePtr->Data = data;
	newNodePtr->NextNode = _FirstNode;
	newNodePtr->PreviousNode = nullptr;


	//Link New Node to the First Node inside Linked List

	if (_FirstNode == nullptr)
	{
		//if the node is the first node inside LinkedList
		_FirstNode = newNodePtr;
		_LastNode = newNodePtr;
	}
	else
	{
		//if new node not the first node inside LinkedList

		//Update the Previous inside the Old First Node
		_FirstNode->PreviousNode = newNodePtr;

		//Make First Node Refere to the new last Node
		_FirstNode = newNodePtr;
	}

	//Increase the Counter of Nodes
	_Count++;
}

//Delete Node inside LinkedList
template <typename T>
void LinkedList<T>::DeleteNode(T data)
{
	//Search For data inside All Nodes
	Node<T>* currentNode = _FirstNode;
	Node<T>* previousNode = NULL;
	Node<T>* nextNode = _FirstNode->NextNode;

	//Loop All Nodes Until Found the Node
	while (currentNode->Data != data)
	{
		currentNode = currentNode->NextNode;
		previousNode = currentNode->PreviousNode;
		nextNode = currentNode->NextNode;

		//When Reached to Last Node
		if (currentNode == NULL)
		{
			break;
		}
	}

	//If not Found the Node to be Deleted
	if (currentNode == NULL)
	{
		std::cout << "Node Not Exist \n";
		return;
	}



	if (currentNode->Data == _FirstNode->Data)
	{
		//If Found Node is First Node

		_FirstNode = nextNode;
		nextNode->PreviousNode = NULL;
	}
	else if (currentNode->Data == _LastNode->Data)
	{
		//If Found Node is Last Node
		_LastNode = previousNode;
		previousNode->NextNode = NULL;
	}
	else
	{
		previousNode->NextNode = nextNode;
		nextNode->PreviousNode = previousNode;
	}

	//Delete Current Node From Memory
	free(currentNode);
}

//Delete Node At Begin of LinkedList
template <typename T>
void LinkedList<T>::DeleteNodeAtBegin()
{
	DeleteNode(_FirstNode->Data);
}

//Print All Nodes
template <typename T>
void LinkedList<T>::PrintAll()
{
	if (_Count == 0)
	{
		std::cout << "List is Empty";
	}
	else
	{
		Node<T>* currentNode = _FirstNode;

		while (currentNode != NULL)
		{
			std::cout << currentNode->Data << "\n";

			currentNode = currentNode->NextNode;
		}
	}

}


#endif // !LINKEDLIST_H_


