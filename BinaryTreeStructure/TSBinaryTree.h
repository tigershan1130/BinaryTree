#pragma once
#include <iostream>
#include <vector>


struct Node
{
	int key;
	Node* left;
	Node* right;

	int height;
	//struct Node* parent;

	Node(int mkey)
	{
		key = mkey;
		left = nullptr;
		right = nullptr;
		height = -1;
		//parent = nullptr;
	}
};


class TSBinaryTree
{
public:
	Node* root; // size of root
	int capacity;  // sizeof(int) 32
	std::vector<int> sortedList;

	TSBinaryTree()
	{
		root = nullptr;
		capacity = 0;


		//std::cout << "Current Allocated Binary Tree Used Bytes: " << sizeof(root) + sizeof(capacity) << std::endl;
	}

	// Get InOrder List, smallest to greatest value using binary sort on binary tree 
	std::vector<int> GetInOrderList()
	{
		// clear our list.
		sortedList.clear();

		InOrder(root); //中序遍历		 
		return sortedList;
	}

	// Get PreOrder List
	std::vector<int> GetPreOrderList()
	{
		sortedList.clear();

		PreOrder(root); // 前序遍历

		return sortedList;
	}

	// Get PostOrder List
	std::vector<int> GetPostOrderList()
	{ 
		sortedList.clear();

		PostOrder(root); //后续遍历

		return sortedList;
	}

	void Insert(int key)
	{
		InsertIntoTree(key, root);
		
	}

	// binary tree find O(H)
	void Find(int key, Node* &parent, Node* &LocationNode)
	{
		Node* temp = root;


		while (temp != nullptr)
		{
			if (key > temp->key)
			{
				parent = temp;
				temp = temp->right;
			}
			else if (key < temp->key)
			{
				parent = temp;
				temp = temp->left;
			}
			else
			{
				LocationNode = temp;	
				break;
			}
		}

		
	}

	// delete Node
	Node* DeleteFromTree(int key)
	{
		if (root == nullptr)
			return nullptr;// we couldn't find the node to delete because it is null

		Node* parent = nullptr;
		Node* LocationNode = nullptr;
		
		Find(key, parent, LocationNode);

		//std::cout << "Parent addy: " << parent << " | Location Node addy: " << LocationNode << std::endl;

		if (LocationNode == nullptr)
			return nullptr; // we couldn't find the node to delete because it is null


		// when both of node are null, how do we delete
		if (LocationNode->left == nullptr && LocationNode->right == nullptr)
		{
			if (parent == nullptr) // root node
			{
				root = NULL; // clear root;
				capacity = 0;
			}
			else
			{
				if (LocationNode == parent->left)
				{
					//std::cout << "0Deleting Node left " << LocationNode->key << " parent left addy: " << (parent->left) << " location addy: " << LocationNode << std::endl;
					parent->left = nullptr;

				}
				else if (LocationNode == parent->right)
					parent->right = nullptr;

				capacity--;
			}

			return LocationNode;
		}
		// when left or right node is not empty, but another side is empty.
		if ((LocationNode->left != nullptr && LocationNode->right == nullptr))
		{
			if (parent == nullptr)
			{
				LocationNode->left = LocationNode;


				LocationNode->right = LocationNode;
			}
			else
			{
				if (LocationNode == parent->left)
				{
					//std::cout << "1Deleting Node left " << LocationNode->key << std::endl;
					parent->left = (LocationNode->left != nullptr) ? LocationNode->left : LocationNode->right;

				}
				else
				{
					parent->right = (LocationNode->left != nullptr) ? LocationNode->left : LocationNode->right;
					//std::cout << "2Deleting Node right " << LocationNode->key << std::endl;
				}

			}

		}

		if ((LocationNode->left == nullptr && LocationNode->right != nullptr))
		{
			if (parent == nullptr)
			{
				root = NULL; // clear root;
				capacity = 0;
			}
			else
			{
				if (LocationNode == parent->left)
				{
					//std::cout << "3Deleting Node left " << LocationNode->key << std::endl;
					parent->left = (LocationNode->left != nullptr) ? LocationNode->left : LocationNode->right;

				}
				else
				{
					parent->right = (LocationNode->left != nullptr) ? LocationNode->left : LocationNode->right;

					//std::cout << "4Deleting Node right " << LocationNode->key << std::endl;

				}

			}

		}

		if (LocationNode->left != nullptr && LocationNode->right != nullptr)
		{
			if (parent == nullptr)
			{
				root = NULL;
				capacity = 0;
			}
			else
			{
				if (LocationNode == parent->left)
					parent->left = LocationNode->left;
				else
					parent->right = LocationNode->left;

				Node* rightDownMostNode = RecursiveFindRightNode(parent->left);

				rightDownMostNode->right = LocationNode->right;
			}

		}

		return LocationNode;
	}
private:
	void InOrder(Node* node)
	{
		if (node != nullptr)
		{
			InOrder(node->right); // adding left side first
			sortedList.push_back(node->key); // then add subtree root
			InOrder(node->left); // add right side
		}
	}

	void PreOrder(Node* node)
	{
		if (node != nullptr)
		{
			//std::cout << "tree addy: " << &node->key << std::endl;
			sortedList.push_back(node->key); // then add subtree root
			PreOrder(node->left); // adding left side first
			PreOrder(node->right); // add right side
		}
	}

	void PostOrder(Node* node)
	{
		if (node != nullptr)
		{
			PostOrder(node->left); // adding left side first
			PostOrder(node->right); // add right side

			sortedList.push_back(node->key); // then add subtree root
		}
	}

	Node* RecursiveFindRightNode(Node* node)
	{
		if (node->right == nullptr)
			return node;

		else
			return RecursiveFindRightNode(node->right);

	}

	// by passing in &address of node, ensure referencing the pass in address
	void InsertIntoTree(int key, Node* &node)
	{
		if (!node)
		{
			node = new Node(key);

			return;
		}

		if (key < node->key)
		{
			InsertIntoTree(key, node->left);
			//node->left->parent = node;

		}
		else
		{
			InsertIntoTree(key, node->right);
			//node->right->parent = node;
		}
	}


};


