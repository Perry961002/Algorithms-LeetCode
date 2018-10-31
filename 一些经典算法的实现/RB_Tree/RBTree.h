#include<iostream>
#include<vector>

using namespace std;

//定义节点颜色
enum NodeColor{RED, BLACK};

//节点类的定义
class RBNode{
public:
	NodeColor color;//颜色
	int key;//关键值
	RBNode *parent;//父亲节点
	RBNode *left;//左孩子
	RBNode *right;//右孩子
	//有参构造函数
	RBNode(int k);
};

//红黑树的定义
class RB_Tree{
public:
	RBNode *root;//根节点
	//红黑树的构造函数
	explicit RB_Tree(RBNode *n);

	void LeftRotate(RBNode *x);//左旋函数
	void RightRotate(RBNode *y);//右旋函数

	RBNode* RBTSearch(int k);//搜索函数

	bool RBTInsert(RBNode *z);//插入函数
	void RBTInsertFixup(RBNode *z);//插入后的调整函数

	RBNode* RBMINIMUM(RBNode *x);//返回以x为根的最小节点

	void RBTTansplant(RBNode *u, RBNode *v);//替换两个节点
	bool RBTDelete(int k);//删除值为k的节点
	void RBTDeleteFixup(RBNode *z);//删除后的调整函数

	void InOrderTraverse();//中序遍历
};