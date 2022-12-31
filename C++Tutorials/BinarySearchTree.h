#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

/*
* ################### Information #################
* Binary Search Tree
* Fast Method For Search Numbers
* Fast Insert , Delete Than Array , BinarySearchTree
* One Root For Tree
* Each TreeNode has one or two Child and Maximum two child
* TreeNode Consist of Value , Left Ptr , Right Ptr
* Left Child TreeNode Value is Less then Parent
* Right Child TreeNode Value is Equal or Greater than Parent TreeNode
*/

namespace DataStructures
{

#pragma region Declearation

	template <typename T>
	class TreeNode
	{
	public:

		TreeNode()
		{
			Value = 0;
			LeftNodePtr = nullptr;
			RightNodePtr = nullptr;
		}
		TreeNode(T value)
		{
			Value = value;
			LeftNodePtr = nullptr;
			RightNodePtr = nullptr;
		}

		T Value;

		TreeNode<T>* LeftNodePtr;
		TreeNode<T>* RightNodePtr;
	};

	enum SortTypeEnum
	{
		//Root->Left->Right
		PreOrder,
		//Left->Root->Right
		InOrder,
		//Left->Right->Root
		PostOrder
	};

	template <typename T>
	class BinarySearchTree
	{
	private:

		//Pointer For the First TreeNode inside BinarySearchTree (Root)
		TreeNode<T>* _RootNode;

		//Hold Levels Count inside BinarySearchTree
		int _Levels;

		//Insert New TreeNode with value inside Parent TreeNode
		TreeNode<T>* Insert(TreeNode<T>* parentNode, T value);

		//Display Nodes inside Tree as (Root > Left > Right)
		void DisplayPreOrder(TreeNode<T>* parentNode);

		//Display Nodes inside Tree as (Left > Root > Right)
		void DisplayInOrder(TreeNode<T>* parentNode);

		//Display Nodes inside Tree as (Left > Right > Root)
		void DisplayPostOrder(TreeNode<T>* parentNode);

		//search for node
		TreeNode<T>* Search(TreeNode<T>* node, T data);

		

	public:

		//Constructor
		BinarySearchTree();

		//Destrcutor
		~BinarySearchTree();

		
		//Insert New TreeNode inside BinarySearchTree
		void Insert(T data);
		
		//Delete TreeNode inside BinarySearchTree
		void Delete(T data);

		//Print All Nodes
		void Display(TreeNode<T>* node,SortTypeEnum sort);

		//Clear All Items Inside BinarySearchTree
		void Clear();

		//Get the First TreeNode inside BinarySearchTree
		TreeNode<T>* RootNode();

		//Check if BinarySearchTree is Empty
		bool isEmpty();

		//search for node
		bool Search(T data);

		//Get the  Min Value inside Tree
		TreeNode<T>* Min(TreeNode<T>* node);

		//Get the  Max Value inside Tree
		TreeNode<T>* Max(TreeNode<T>* node);
	};

#pragma endregion

#pragma region Defination

	//[Tested]
	//Constructor
	template <typename T>
	BinarySearchTree<T>::BinarySearchTree()
	{
		_RootNode = nullptr;

		_Levels = 0;
	}

	//Desctructor
	template <typename T>
	BinarySearchTree<T>::~BinarySearchTree()
	{

	}

	//[Tested]
	//Insert New TreeNode with value inside Parent TreeNode
	template <typename T>
	TreeNode<T>* BinarySearchTree<T>::Insert(TreeNode<T>* parentNode, T value)
	{
		//check if parentNode is Null this mean its root of tree
		if (parentNode == nullptr) 
		{
			//Create Root TreeNode
			parentNode= new TreeNode<T>(value);
		}
		else if(value<parentNode->Value)
		{
			//Create Child TreeNode To Left Side because value is less then parent value
			parentNode->LeftNodePtr = Insert(parentNode->LeftNodePtr,value);
		}
		else
		{
			//Create Child TreeNode To Right Side because value is greater or equal to parent value
			parentNode->RightNodePtr = Insert(parentNode->RightNodePtr, value);
		}

		return parentNode;
	}
	
	//[Tested]
	//Insert New TreeNode inside BinarySearchTree
	template <typename T>
	void BinarySearchTree<T>::Insert(T data)
	{
		_RootNode = Insert(_RootNode,data);
	}

	//Delete TreeNode inside BinarySearchTree
	template <typename T>
	void BinarySearchTree<T>::Delete(T data)
	{
		

	}

	//Clear All Items Inside BinarySearchTree
	template <typename T>
	void BinarySearchTree<T>::Clear()
	{
		
	}
	
	//[Tested]
	//Print All Nodes
	template <typename T>
	void BinarySearchTree<T>::Display(TreeNode<T>* node,SortTypeEnum sort)
	{
		

		if (sort == SortTypeEnum::PreOrder)
		{
			std::cout << "BinarySearchTree PreOrder (Root->Left->Right)" << std::endl;
			std::cout << "===========================" << std::endl;

			DisplayPreOrder(node);
		}
		else if (sort == SortTypeEnum::InOrder)
		{
			std::cout << "BinarySearchTree InOrder (Left->Root->Right)" << std::endl;
			std::cout << "===========================" << std::endl;

			DisplayInOrder(node);
		}
		else if (sort == SortTypeEnum::PostOrder)
		{
			std::cout << "BinarySearchTree PostOrder (Left->Right->Root)" << std::endl;
			std::cout << "============================" << std::endl;

			DisplayPostOrder(node);
		}

		std::cout << "\n";
	}

	//[Tested]
	//Display Nodes inside Tree as PreOrder (Root > Left > Right)
	template <typename T>
	void BinarySearchTree<T>::DisplayPreOrder(TreeNode<T>* parentNode)
	{
		if (parentNode == NULL)
			return;

		//Display Root Data
		std::cout << parentNode->Value << "\n";

		//Display Left Data
		DisplayPreOrder(parentNode->LeftNodePtr);

		//Display Right Data
		DisplayPreOrder(parentNode->RightNodePtr);


	}

	//[Tested]
	//Display Nodes inside Tree as (Left > Root > Right)
	template <typename T>
	void BinarySearchTree<T>::DisplayInOrder(TreeNode<T>* parentNode)
	{
		if (parentNode == NULL)
			return;

		//Display Left Data
		DisplayInOrder(parentNode->LeftNodePtr);

		//Display Root Data
		std::cout << parentNode->Value << "\n";

		//Display Right Data
		DisplayInOrder(parentNode->RightNodePtr);


	}

	//[Tested]
	//Display Nodes inside Tree as (Left > Right > Root)
	template <typename T>
	void BinarySearchTree<T>::DisplayPostOrder(TreeNode<T>* parentNode)
	{
		if (parentNode == NULL)
			return;

		
		//Display Left Data
		DisplayPostOrder(parentNode->LeftNodePtr);

		//Display Right Data
		DisplayPostOrder(parentNode->RightNodePtr);

		//Display Root Data
		std::cout << parentNode->Value << "\n";


	}

	//[Tested]
	//Get the First TreeNode inside BinarySearchTree
	template <typename T>
	TreeNode<T>* BinarySearchTree<T>::RootNode()
	{
		return _RootNode;
	}


	//[Tested]
	//Check if BinarySearchTree is Empty
	template <typename T>
	bool BinarySearchTree<T>::isEmpty()
	{
		return _RootNode == nullptr;
	}



	//[Tested]
	//Search for key value inside Tree
	template <typename T>
	TreeNode<T>* BinarySearchTree<T>::Search(TreeNode<T>* node,T data)
	{
		if (node == NULL) 
		{
			return NULL;
		}
		else if (node->Value == data) 
		{
			return node;
		}
		else if (data < node->Value)
		{
			return Search(node->LeftNodePtr,data);
		}
		else if (data >= node->Value) 
		{
			return Search(node->RightNodePtr, data);
		}

	}
	
	//[Tested]
	//Search for key value inside Tree
	template <typename T>
	bool BinarySearchTree<T>::Search(T data)
	{
		TreeNode<T>* result = Search(_RootNode,data);

		return result != NULL;
	}

	//[Tested]
	//Get the Min Value inside Tree
	template <typename T>
	TreeNode<T>* BinarySearchTree<T>::Min(TreeNode<T>* node)
	{
		if (node == NULL)
			return NULL;
		else if (node->LeftNodePtr == NULL)
			return node;
		else
		return Min(node->LeftNodePtr);
	}

	//[Tested]
	//Get the Max Value inside Tree
	template <typename T>
	TreeNode<T>* BinarySearchTree<T>::Max(TreeNode<T>* node)
	{
		if (node == NULL)
			return NULL;
		else if (node->RightNodePtr == NULL)
			return node;
		else
			return Max(node->RightNodePtr);
	}


#pragma endregion

}

#endif // !BINARYSEARCHTREE_H_


