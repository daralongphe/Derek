#include <iostream>
#include "Binarytree.h"

using namespace std;

int main()
{
	//Program Header
	cout << "Project_5" << endl;
	cout << "Long Beach City College" << endl;
	cout << "Author: Chandaralong" << endl;
	cout << "Apr. 30, 2020" << endl;
	cout << "======================================================================" << endl;
	binaryTreeType<int>  treeRoot;
	int data;

	cout << "Enter integers ending with -999" << endl;
	cin >> data;
	while (data != -999)
	{
		treeRoot.insert(data);
		cin >> data;
	}

	cout << endl << "Tree nodes in inorder: ";
	treeRoot.inorderTraversal();

	cout << endl << "Tree nodes in preorder: ";
	treeRoot.preorderTraversal();

	cout << endl << "Tree nodes in postorder: ";
	treeRoot.postorderTraversal();
	cout << endl;

	cout << "Number of Nodes with only one child: " << treeRoot.treeSingleParentCount() << endl;
	cout << "Tree Height: " << treeRoot.treeHeight() << endl;
	cout << "Number of Nodes: " << treeRoot.treeNodeCount() << endl;
	cout << "Number of leaves count: " << treeRoot.treeLeavesCount() << endl;
	cout << endl;

	return 0;
}
