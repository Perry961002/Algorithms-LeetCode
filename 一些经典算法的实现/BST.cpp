#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class BSTNode{
public:
	int val;
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;
	BSTNode() :val(), parent(nullptr), left(nullptr), right(nullptr){}
	BSTNode(int v) :val(v), parent(nullptr), left(nullptr), right(nullptr){}
};

//输出一棵二叉搜索树
void InorderTreeWalk(BSTNode* x){
	if (x != nullptr){
		InorderTreeWalk(x->left);
		cout << x->val << " ";
		InorderTreeWalk(x->right);
	}
	return;
}

//中序遍历的非递归实现
void InorderUseStack(BSTNode* root){
	stack<BSTNode*> s;
	BSTNode *node = root;
	while (node != nullptr || !s.empty()){
		if (node != nullptr){
			s.push(node);
			node = node->left;
		}
		else{
			node = s.top();
			s.pop();
			cout << node->val << " ";
			node = node->right;
		}
	}
}

//不使用辅助栈的中序遍历
void InorderMorris(BSTNode* root){
	BSTNode *cur = root, *pre = nullptr;
	while (cur != nullptr){
		//当前节点的左子树不存在
		if (cur->left == nullptr){
			cout << cur->val << " ";
			//把当前节点换成右子树
			cur = cur->right;
		}
		else{
			pre = cur->left;
			//找到前驱节点
			while (pre->right != nullptr && pre->right != cur){
				pre = pre->right;
			}
			//前驱节点没有处理过
			if (pre->right == nullptr){
				//处理前驱节点
				pre->right = cur;
				//左子树
				cur = cur->left;
			}
			else{
				//还原回去
				pre->right = nullptr;
				cout << cur->val << " ";
				//把当前节点换成右子树
				cur = cur->right;
			}
		}
	}
}

//查找关键值为k的节点
BSTNode* TreeSearch(BSTNode* x, int k){
	if (x == nullptr || x->val == k)//x就是要找的节点,或者树为空
		return x;
	if (k < x->val)//在左子树中
		return TreeSearch(x->left, k);
	else//在右子树中
		return TreeSearch(x->right, k);
}

//得到最小节点
BSTNode* GetMin(BSTNode* x){
	//迭代到最左侧节点
	while (x->left != nullptr)
		x = x->left;
	return x;
}

//找到最大节点
BSTNode* GetMax(BSTNode* x){
	//找到最右侧节点
	while (x != nullptr)
		x = x->right;
	return x;
}

//得到后继节点
BSTNode* GetSuccessor(BSTNode* x){
	//右子树中的最小节点
	if (x->right != nullptr){
		return GetMin(x->right);
	}
	//后继就是x的最底层祖先
	BSTNode* y = x->parent;
	while (y != nullptr && x == y->right){
		x = y;
		y = y->parent;
	}
	return y;
}

//插入节点
void Insert(BSTNode* T, BSTNode* z){
	BSTNode* y = nullptr;
	BSTNode* x = T;
	//找到需要插入的位置
	while (x != nullptr){
		y = x;
		if (z->val < x->val)
			x = x->left;
		else
			x = x->right;
	}
	//把z接到树上
	z->parent = y;
	//T是空树
	if (y == nullptr)
		T = z;
	//确定z应该是哪个子节点
	else if (z->val < y->val)
		y->left = z;
	else
		y->right = z;
}

//用节点v去替换u
void Transplant(BSTNode* T, BSTNode* u, BSTNode* v){
	if (u->parent == nullptr)
		T = v;
	//确定u在父亲节点的哪个子树上
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	//把v接到父亲节点上
	if (v != nullptr)
		v->parent = u->parent;
}

//删除节点z
void Delete(BSTNode* T, BSTNode* z){
	//左子树不存在,用右子节点替代他
	if (z->left == nullptr)
		Transplant(T, z, z->right);
	//右子树存在,左子树不存在,用左子节点替代他
	else if (z->right == nullptr)
		Transplant(T, z, z->left);
	//两个节点都存在
	else{
		//y是z的后继节点
		BSTNode* y = GetMin(z->right);
		//y不是z的孩子
		if (y->parent != z){
			//用y的右孩子替换y
			Transplant(T, y, y->right);
			//把z的右孩子接到y上
			y->right = z->right;
			y->right->parent = y;
		}
		//用后继节点y替代z
		Transplant(T, z, y);
		//把z的左子树放到y的左边
		y->left = z->left;
		y->left->parent = y;
	}
}
int main(){
	vector<int> num = { 9, 5, 8, 6, 4, 3, 2, 7, 1, 10 };
	BSTNode* root = new BSTNode();
	for (int i = 0; i < num.size(); i++){
		cout << "插入值为" << num[i] << "的节点" << endl;
		if (i == 0)
			root->val = num[i];
		else{
			BSTNode* in = new BSTNode(num[i]);
			Insert(root, in);
		}
	}
	cout << "构造的二叉搜索树为：";
	InorderTreeWalk(root);
	//InorderUseStack(root);
	//InorderMorris(root);
	cout << endl;
	int input = 0;
	while (1){
		cout << "输入一个你需要插入节点的值，没有的话输入-1：";
		cin >> input;
		if (input == -1)
			break;
		else{
			BSTNode* in = new BSTNode(input);
			Insert(root, in);
		}
	}
	cout << "新的二叉搜索树为：";
	InorderTreeWalk(root);
	//InorderUseStack(root);
	//InorderMorris(root);
	cout << endl;
	while (1){
		cout << "输入一个你需要删除节点的值，没有的话输入-1：";
		cin >> input;
		if (input == -1)
			break;
		else{
			BSTNode* target = TreeSearch(root, input);
			if (target == nullptr)
				cout << "节点不存在" << endl;
			else
				Delete(root, target);
		}
	}
	cout << "新的二叉搜索树为：";
	InorderTreeWalk(root);
	//InorderUseStack(root);
	//InorderMorris(root);
	cout << endl;
	system("pause");
}