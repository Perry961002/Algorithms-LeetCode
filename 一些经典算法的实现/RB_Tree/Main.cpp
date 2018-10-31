#include"RBTree.h"
#include<iostream>

using namespace std;

int main(){
	vector<int> A = {9, 0, 7, 8, 3, 6, 4, 2, 1, 5};
	RBNode *root = new RBNode(A[0]);
	RB_Tree tree =  RB_Tree(root);
	for (int i = 1; i < A.size(); i++){
		RBNode *temp = new RBNode(A[i]);
		tree.RBTInsert(temp);
	}
	cout << "红黑树初始化为：";
	tree.InOrderTraverse();
	cout << endl;
	int input;
	while (1){
		input = 0;
		cout << "输入要插入红黑树的关键字的值，输入-1表示结束输入：";
		cin >> input;
		if (input == -1)
			break;
		else{
			RBNode *temp = new RBNode(input);
			if (tree.RBTInsert(temp))
				cout << "节点" << input << "插入成功" << endl;
		}
	}
	cout << endl;
	cout << "中序遍历红黑树：";
	tree.InOrderTraverse(); cout << endl;
	while (1){
		input = 0;
		cout << "输入要删除红黑树的关键字的值，输入-1表示结束输入：";
		cin >> input;
		if (input == -1)
			break;
		else{
			if (tree.RBTDelete(input))
				cout << "节点" << input << "删除成功" << endl;
		}
	}
	cout << "中序遍历红黑树：";
	tree.InOrderTraverse(); cout << endl;
	system("pause");
	return 0;
}