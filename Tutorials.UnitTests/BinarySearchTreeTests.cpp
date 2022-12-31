#include "pch.h"
#include "CppUnitTest.h"
#include "../C++Tutorials/BinarySearchTree.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace DataStructures;

namespace TutorialsUnitTests
{
	TEST_CLASS(BinarySearchTreeTests)
	{
	public:

		TEST_METHOD(Insert_Node_Inside_BinaryTree)
		{
			//Arrange
			BinarySearchTree<int> binaryTree;

			//Act
			binaryTree.Insert(50);


			//Assert
			Assert::IsTrue(binaryTree.Search(50));
		}

		TEST_METHOD(Get_Min_Value_Inside_BinaryTree)
		{
			//Arrange
			BinarySearchTree<int> binaryTree;

			//Act
			binaryTree.Insert(45);
			binaryTree.Insert(15);
			binaryTree.Insert(79);
			binaryTree.Insert(90);
			binaryTree.Insert(10);
			binaryTree.Insert(55);
			binaryTree.Insert(12);
			binaryTree.Insert(20);
			binaryTree.Insert(50);

			TreeNode<int>* actual = binaryTree.Min(binaryTree.RootNode());



			//Assert
			Assert::AreEqual(10, actual->Value);
		}

		TEST_METHOD(Get_Max_Value_Inside_BinaryTree)
		{
			//Arrange
			BinarySearchTree<int> binaryTree;

			//Act
			binaryTree.Insert(45);
			binaryTree.Insert(15);
			binaryTree.Insert(79);
			binaryTree.Insert(90);
			binaryTree.Insert(10);
			binaryTree.Insert(55);
			binaryTree.Insert(12);
			binaryTree.Insert(20);
			binaryTree.Insert(50);

			TreeNode<int>* actual = binaryTree.Max(binaryTree.RootNode());



			//Assert
			Assert::AreEqual(90, actual->Value);
		}

	};
}
