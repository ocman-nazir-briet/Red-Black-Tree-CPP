#include"RBT.h"
#include<fstream>
void DesignLogo()
{
	cout << "\t\t\t\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~" << endl;
	cout << "\t\t\t\t                   RED BLACK TREE          " << endl;
	cout << "\t\t\t\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~" << endl;
}
int options(int choice)
{
	cout << endl;
	cout << "\t\t\t\t\t\t++++++++++++++++++++++" << endl;
	cout << "\t\t\t\t\t\t+        MENU        +" << endl;
	cout << "\t\t\t\t\t\t++++++++++++++++++++++" << endl << endl;
	
	cout << "  \t\t\t\tPress 1 to insert values one by one in the tree" << endl;
	cout << "  \t\t\t\tPress 2 for searching a value from the tree" << endl;
	cout << "  \t\t\t\tPress 3 for pre-order traversal NLR" << endl;
	cout << "  \t\t\t\tPress 4 for in - order traversal LNR" << endl;
	cout << "  \t\t\t\tPress 5 for post - order traversal LRN" << endl;
	cout << "  \t\t\t\tPress 6 for pre - order traversal 2 NRL" << endl;
	cout << "  \t\t\t\tPress 7 for in - order traversal 2 RNL" << endl;
	cout << "  \t\t\t\tPress 8 for post - order traversal 2 RLN" << endl;
	cout << "  \t\t\t\tPress 9 for displaying parent of a node present in Tree" << endl;
	cout << "  \t\t\t\tPress 10 to read integer values from the file “input.txt”" << endl;
	cout << "  \t\t\t\tPress 11 to delete all the duplicate values from the tree" << endl;
	cout << "  \t\t\t\tPress 12 to destroy the tree(all nodes must be deleted)" << endl;
	cout << "  \t\t\t\tPress 13 to EXIT" << endl;
	cout << "  \t\t\t\t\t\t****************" << endl;
	cout << "  \t\t\t\t\t\t    Choice : ";
	cin >> choice;
	cout << "  \t\t\t\t\t\t****************" << endl;
	cout << endl;
	return choice;
}



int main()
{
	RBT r1;
	DesignLogo();
	int choice = 0;

	ifstream fin;
	

	while (true)
	{

		choice = options(choice);

		if (choice==1)
		{

			cout << "\t\t\t\t\t\tInsert Values in Trees" << endl << endl;;
			cout << "\t\t\t\t\t\tEnter -99 to terminate insertion" << endl << endl;
			cout << "\t\t\t\t\t\t";
			int n;
			while (cin>>n)

			{
				if (n==-99)
				{
					break;
				}
				r1.Insert(n);
				cout << "\t\t\t\t\t\t";
			}



		}
		else if (choice==2)
		{
			cout << "\t\t\t\t\t\t    Search values in Tree    " << endl << endl;
			cout << "\t\t\t\t\t\t";


			cout << "Enter value to Search in Tree: ";
			int s;
			cin >> s;
			cout << "\t\t\t\t\t\t";
			r1.SEARCH(s);
		}
		else if (choice==3)
		{
			cout << "\t\t\t\t\t\t        Preorder Traversal     " << endl << endl;
			cout << "\t\t\t\t\t\t";
			r1.preorderTraversal();
		}
		else if (choice==4)
		{
			cout << "\t\t\t\t\t\t        Inorder Traversal     " << endl << endl;
			cout << "\t\t\t\t\t\t";
			r1.InorderTraversal();
		}
		else if (choice==5)
		{
			cout << "\t\t\t\t\t\t        Postorder Traversal     " << endl << endl;
			cout << "\t\t\t\t\t\t";
			r1.postorderTraversal();
		}
		else if (choice==6)
		{
			cout << "\t\t\t\t\t\t        Preorder Traversal 2    " << endl << endl;
			cout << "\t\t\t\t\t\t";
			r1.preorderTraversal2();
		}
		else if (choice==7)
		{
			cout << "\t\t\t\t\t\t        Inorder Traversal 2    " << endl << endl;
			cout << "\t\t\t\t\t\t";
			r1.InorderTraversal2();
			
		}
		else if (choice==8)
		{
			cout << "\t\t\t\t\t\t        Postorder Traversal     " << endl << endl;
			cout << "\t\t\t\t\t\t";
			r1.postorderTraversal2();
			
		}
		else if (choice == 9)
		{
			cout << "\t\t\t\t\t\t        Parent of Node         " << endl << endl;
			int n;
			cout << "\t\t\t\t\t\t Enter Value : ";
			cin >> n;
		 r1.displayParent(n);

		}
		else if (choice == 10)
		{
			fin.open("input.txt");
			cout << "\t\t\t\t\t\t         Read from file named ''input.txt''    " << endl << endl;
			int c = 0;
			while (fin>>c)
			{
			
				r1.Insert(c);
			}
			fin.close();
		}
		else if (choice == 12)
		{
			cout << "\t\t\t\t\t\t           Destroy Red Black Tree           " << endl << endl;
			cout << "\t\t\t\t\t\t";

			r1.destroyTree();
		}
		else if (choice == 13)
		{
			cout << "\t\t\t\t\t\t            EXIT Program             " << endl << endl;
			cout << "\t\t\t\t\t\t";
			cout << "Exit " << endl;
			break;
		}

	}

	return 0;
}