#pragma once
#include"Tree.h"
class RBT: public Tree
{
private:
	int flag = 0; int K = 0;
	void insert(int n, Node*& root, Node*& temp)
	{
		if (root == nullptr)
		{
			if (flag == 0)
			{
				root = newNode(n);
				root->colour = 'B';
				flag = 1;
				temp = root;
			}
			else
			{
				root = newNode(n);
				root->colour = 'R';
				temp = root;
			}
			return;
		}
		if (n < root->data)
		{
			insert(n, root->leftChild, temp);
		}
		else
		{
			insert(n, root->rightChild, temp);
		}
	}
	void InorderTraversalCode(Node* temp)
	{
		if (temp != nullptr)
		{
			InorderTraversalCode(temp->leftChild);
			cout << temp->data << " Node->colour " << temp->colour << endl;
			cout << "\t\t\t\t\t\t";
			InorderTraversalCode(temp->rightChild);
		}
	}
	void InorderTraversalCode2(Node* temp)
	{
		if (temp != nullptr)
		{
			InorderTraversalCode2(temp->rightChild);

			cout << temp->data << " Node->colour " << temp->colour << endl;
			cout << "\t\t\t\t\t\t";
			InorderTraversalCode2(temp->leftChild);
		}
	}

	Node* SEARCH_WRAPPER(int Value, Node* R)
	{
		while (R && Value != R->data)
		{
			if (Value < R->data)
			{
				R = R->leftChild;
			}
			else
			{
				R = R->rightChild;
			}
		}
		return R;
	}

	/////////////////
	// parent display
	/////////////////
	int displayingParent(Node* temp, int n, int& check, Node* T)
	{
		if (root == nullptr)
		{
			cout << "\t\t\t\t\t\t   EmptyTree " << endl;
		}
		else
		{
			if (n == root->data)
			{
				cout << "\t\t\t\t\t\t This is the root of Tree " << endl;
				check++;
				return root->data;

			}
			else
			{
				if (temp != nullptr)
				{
					if (n < temp->data)
					{

						if (n == temp->data)
						{
							check++;
							return T->data;
						}
						T = temp;
						displayingParent(temp->leftChild, n, check, T);
					}
					else
					{

						if (n == temp->data)
						{
							check++;
							return T->data;
						}
						T = temp;
						displayingParent(temp->rightChild, n, check, T);
					}
				}
			}
		}




	}

	/////////////////////////////////////////////////
	// Inorder, preorder and post order traversal //
	///////////////////////////////////////////////
	void preorderTraversalCode(Node* temp)
	{
		if (temp != nullptr)
		{

			cout << temp->data << " Node->colour " << temp->colour << endl;
			cout << "\t\t\t\t\t\t";
			preorderTraversalCode(temp->leftChild);
			preorderTraversalCode(temp->rightChild);
		}

	}
	void preorderTraversalCode2(Node* temp)
	{
		if (temp != nullptr)
		{

			cout << temp->data << " Node->colour " << temp->colour << endl;
			cout << "\t\t\t\t\t\t";
			preorderTraversalCode2(temp->rightChild);
			preorderTraversalCode2(temp->leftChild);

		}

	}
	void postorderTraversalCode(Node* temp)
	{
		if (temp != nullptr)
		{
			postorderTraversalCode(temp->leftChild);
			postorderTraversalCode(temp->rightChild);

			cout << temp->data << " Node->colour " << temp->colour << endl;
			cout << "\t\t\t\t\t\t";
		}

	}

	void postorderTraversalCode2(Node* temp)
	{
		if (temp != nullptr)
		{
			postorderTraversalCode2(temp->rightChild);
			postorderTraversalCode2(temp->leftChild);


			cout << temp->data << " Node->colour " << temp->colour << endl;
			cout << "\t\t\t\t\t\t";
		}

	}
	void rotateROOT(Node*& temp3, Node*& root, Node*& temp2, Node*& temp)
	{
		if (temp3->leftChild == temp2)
		{

			if (temp2->colour == 'R' && temp->colour == 'R')
			{
				if (temp3->rightChild != NULL && temp3->rightChild->colour == 'R')
				{


					temp3->rightChild->colour = 'B';
					temp2->colour = 'B';
				}
				else if (temp3->rightChild == NULL || temp3->rightChild->colour == 'B')
				{
					Node* T = temp2->rightChild;
					temp3->leftChild = NULL;
					root = temp2;
					temp2->rightChild = temp3;
					temp3->leftChild = T;
					temp3->colour = 'R';
				}

			}
		}
		else if (temp3->rightChild == temp2)
		{
			if (temp2->colour == 'R' && temp->colour == 'R')
			{
				if (temp3->leftChild != NULL && temp3->leftChild->colour == 'R')
				{
					temp3->leftChild->colour = 'B';
					temp2->colour = 'B';
				}
				else
				{

					temp3->rightChild = NULL;
					temp3->rightChild = temp2->leftChild;
					root = temp2;
					temp2->leftChild = temp3;

					temp3->colour = 'R';
				}
			}
		}
	}

	void del(Node* T)
	{
		Node* TN = root;
		if (T)
		{
			Node* TP = nullptr;


			if (!ParentFun(T, TN))
			{
				TP = ParentFun(T, TN);

			}
			if (T->leftChild)
			{
				del(T->leftChild);
				if (TP)
				{
					TP->leftChild = nullptr;
				}
				else if (T->rightChild)
				{
					del(T->rightChild);
					if (TP)
					{
						TP->rightChild = nullptr;
					}

				}
				free(T);
				T = nullptr;
			}
		}
	}

	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////

public:

	void SEARCH(int Value)
	{
		if (SEARCH_WRAPPER(Value, this->root))
		{
			cout << "Found" << endl;
		}
		else
			cout << "Not Found" << endl;
	}

	void displayParent(int n)
	{
		int check = 0;
		Node* T = nullptr;
		int val = displayingParent(root, n, check, T);
		if (check > 0)
		{
			cout << "\t\t\t\t\t\t Parent value : " << val << endl;

		}
		else
		{
			cout << "\t\t\t\t\t\t";
			cout << "Given NOde does not exit in the tree " << endl;
		}



	}
	// destruction
	void destroyTree()
	{
		if (root)
		{
			del(root);
			root = nullptr;
		}
	}

	/// <summary>
	/// Traversals
	/// </summary>
	void preorderTraversal2()
	{
		preorderTraversalCode2(root);
	}
	void preorderTraversal()
	{
		preorderTraversalCode(root);
	}
	void postorderTraversal()
	{
		postorderTraversalCode(root);
	}
	void postorderTraversal2()
	{
		postorderTraversalCode2(root);
	}
	void InorderTraversal()
	{
		InorderTraversalCode(root);
	}
	void InorderTraversal2()
	{
		InorderTraversalCode2(root);
	}

	Node* ParentFun(Node* temp, Node* temp2)
	{
		if (temp != nullptr && temp != root)
		{
			while (true)
			{

				if (temp2->leftChild != nullptr)
				{
					if (temp->data == temp2->leftChild->data)
					{
						break;
					}
				}
				if (temp2->rightChild != nullptr)
				{
					if (temp->data == temp2->rightChild->data)
					{
						break;
					}
				}
				if (temp->data > temp2->data)
				{

					temp2 = temp2->rightChild;

				}
				else if (temp->data < temp2->data)
				{

					temp2 = temp2->leftChild;

				}

			}
		}
		else
		{
			return NULL;
		}

		return temp2;
	}

	void fixviolation(Node*& temp, Node*& temp2, Node*& temp3, int& C)
	{
		Node* temp4 = root;
		if (temp == root)
		{
			return;
		}
		else
		{
			if (K == 0)
			{
				K++;
			}
			else
			{
				temp2 = root;
				temp3 = nullptr;

				while (true)
				{
					if (temp2->leftChild != nullptr)
					{
						if (temp->data == temp2->leftChild->data)
						{
							break;
						}
					}
					if (temp2->rightChild != nullptr)
					{
						if (temp->data == temp2->rightChild->data)
						{
							break;
						}
					}
					if (temp->data > temp2->data)
					{
						temp3 = temp2;
						temp2 = temp2->rightChild;

					}
					else if (temp->data < temp2->data)
					{
						temp3 = temp2;
						temp2 = temp2->leftChild;

					}

				}

				if (K == 1)
				{

					K++;
					if (temp3 == root)
					{

						rotateROOT(temp3, root, temp2, temp);

					}

				}
				else
				{
					while (temp2 != nullptr && temp2->colour == 'R')
					{
						if (temp3->leftChild != nullptr && temp3->leftChild->colour == 'R' && temp3->leftChild->data != temp2->data)
						{
							temp3->leftChild->colour = 'B';
							temp3->rightChild->colour = 'B';
							temp3->colour = 'R';
							break;
						}
						if (temp3->rightChild != nullptr && temp3->rightChild->colour == 'R' && temp3->rightChild->data != temp2->data)
						{
							temp3->leftChild->colour = 'B';
							temp3->rightChild->colour = 'B';
							temp3->colour = 'R';
							break;
						}
						else
						{

							int i = 0;
							while (true)
							{
								if (temp3 == temp4->rightChild)
								{
									break;
								}
								if (temp4->leftChild == temp3)
								{
									break;
								}
								if (temp3->data > temp4->data)
								{
									temp4 = temp4->rightChild;
								}
								else if (temp3->data < temp4->data)
								{
									temp4 = temp4->leftChild;
								}
							}
							if (temp3->rightChild == NULL || (temp3->rightChild->colour == 'B' && temp3->rightChild != temp2))
							{
								if (temp3->leftChild == temp2)
								{
									if (temp2->leftChild == temp)
									{
										Node* T = temp2->rightChild;
										temp4->leftChild = NULL;
										temp3->leftChild = NULL;

										temp2->rightChild = temp3;
										temp2->rightChild->leftChild = T;
										temp4->leftChild = temp2;
										temp3->colour = 'R';
										temp2->colour = 'B';
									}
									else
									{
										temp3->leftChild = NULL;
										temp2->rightChild = NULL;
										temp3->leftChild = temp;
										temp->leftChild = temp2;
										temp4->leftChild = temp;
										temp3->leftChild = NULL;
										temp->rightChild = temp3;
										temp->colour = 'B';
										temp3->colour = 'R';
									}
								}
							}
							else
							{

								if (temp3->rightChild == temp2)
								{
									if (temp2->rightChild == temp)
									{
										Node* T = temp2->leftChild;
										temp3->rightChild = NULL;
										temp2->leftChild = temp3;
										temp2->leftChild->rightChild = T;
										temp4->rightChild = temp2;
										temp2->colour = 'B';
										temp3->colour = 'R';
									}
									else
									{
										temp3->rightChild = NULL;
										temp2->leftChild = NULL;
										temp3->rightChild = temp;
										temp->rightChild = temp2;
										temp3->rightChild = NULL;
										temp4->rightChild = NULL;
										temp4->rightChild = temp;
										temp->leftChild = temp3;
										temp->colour = 'B';
										temp3->colour = 'R';
										temp2->colour = 'R';
									}
								}
							}
							break;
						}
					}
				}

			}
		}

		if (K > 1)
		{
			Node* R = root;
			Node* R2 = R;
			R = ParentFun(temp3, R);

			if (R != nullptr)
			{

				if (R->colour == 'R' && temp3->colour == 'R')
				{
					Node* R2 = root;
					R2 = ParentFun(R, R2);
					if (R2 == root)
					{
						C = 1;
						temp = temp3;
					}
					else if (R2 != root)
					{
						C = -1;
						temp = temp3;
					}
				}
			}



		}

		root->colour = 'B';
	}

	///////////////////////
	/// / insertion in tree
	///////////////////////
	void Insert(int n)
	{
		Node* temp = nullptr;
		Node* temp2 = root;
		Node* temp3 = nullptr;
		int check = 0;
		insert(n, root, temp);
		fixviolation(temp,temp2,temp3,check);
		if (check == 1)
		{
			K = 1;
		
			fixviolation(temp, temp2, temp3, check);
		}
		else if (check == -1)
		{
			fixviolation(temp, temp2, temp3, check);
		}

	}
	Node* newNode(int n)
	{
		Node* node = new Node;
		node->data = n;
		node->leftChild = nullptr;
		node->rightChild = nullptr;
		return node;
	}
	RBT()
	{
		// this is the constructor
	}
	~RBT()
	{
		destroyTree();
	}
};
