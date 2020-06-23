// BinaryTreeStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
// when to use binary tree
// for example, when we want to store files in Hiearchy Structure
//                   File System
//                    /    \
//                  ...    Home
//                  /  \      \
//             Upgrade ...    course
//                             /  \
//                          cs101 cs201
#include "TSBinaryTree.h"
using namespace std;

int main()
{
	TSBinaryTree binaryTree = TSBinaryTree();

	binaryTree.Insert(50);                 
	binaryTree.Insert(30);
	binaryTree.Insert(20);
	binaryTree.Insert(40);
	binaryTree.Insert(35);
	binaryTree.Insert(45);
	binaryTree.Insert(70);
	binaryTree.Insert(60);
	binaryTree.Insert(80);

	/*
						50
					20
				      40
				     35 45
	*/

	vector<int> inorderList = binaryTree.GetPreOrderList();


	std::cout << "List capacity: " << inorderList.capacity() << std::endl;

	for (int i = 0; i < inorderList.capacity(); i++)
	{
		std::cout << inorderList[i] << std::endl;
	}

	Node* deleteNode = binaryTree.DeleteFromTree(30);

	
	vector<int> inorderList2 = binaryTree.GetPreOrderList();

	std::cout << "List capacity: " << inorderList2.capacity() << std::endl;

	for (int i = 0; i < inorderList2.capacity(); i++)
	{
		std::cout << inorderList2[i] << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
