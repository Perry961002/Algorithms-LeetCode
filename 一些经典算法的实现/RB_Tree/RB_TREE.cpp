#include"RBTree.h"
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

RBNode nil(-1);
RBNode *NIL = &nil;

//节点构造
RBNode::RBNode(int k):key(k){
	parent = left = right = NIL;
	color = BLACK;
}

//红黑树构造
RB_Tree::RB_Tree(RBNode *n) :root(n){
	n->parent = n->left = n->right = NIL;
}

//以x为中心进行左旋
void RB_Tree::LeftRotate( RBNode *x){
	RBNode *y = x->right;//取x的左节点
	x->right = y->left;//y的左孩子变成x的右孩子
	//y连上x的父亲节点
	if (y->left != NIL)
		y->left->parent = x;
	y->parent = x->parent;
	//根据x是左右节点的情况来确定y连到x父节点的哪个分支上
	//x是根
	if (x->parent == NIL)
		root = y;
	//是父节点的左孩子
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	//把x放到y的左孩子上
	y->left = x;
	x->parent = y;//修改x的父亲节点为y才算是连上
}

//以x为中心进行右旋
void RB_Tree::RightRotate(RBNode *x){
	RBNode *y = x->left;//取x的左节点
	x->left = y->right;//y的左孩子变成x的右孩子
	//y连上x的父亲节点
	if (y->right != NIL)
		y->right->parent = x;
	y->parent = x->parent;
	//根据x是左右节点的情况来确定y连到x父节点的哪个分支上
	//x是根
	if (x->parent == NIL)
		root = y;
	//是父节点的左孩子
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	//把x放到y的右孩子上
	y->right = x;
	x->parent = y;//修改x的父亲节点为y才算是连上
}

//以前序遍历方式搜索红黑树,找到就返回true
RBNode* RB_Tree::RBTSearch(int k){
	RBNode *x = root;
	while (x != NIL){
		if (x->key == k)
			return x;
		//迭代到右子树
		else if (x->key < k)
			x = x->right;
		else
			x = x->left;
	}
	return x;//没有找到
}

//将节点z插入到红黑树
bool RB_Tree::RBTInsert(RBNode *z){
	if (RBTSearch(z->key) != NIL){
		cout << "包含关键值为" << z->key << "的节点已经存在" << endl;
		return false;
	}
	else{
		//先找z应该被插入的位置,并把颜色设为红
		RBNode *x = root;
		RBNode *y = NIL;
		//找到z应该的位置
		while (x != NIL){
			y = x;
			if (z->key < x->key)
				x = x->left;
			else if (z->key > x->key)
				x = x->right;
		}
		z->parent = y;
		//确定z应该是父亲节点的哪个孩子
		if (y == NIL)
			root = z;
		else if (z->key < y->key)
			y->left = z;
		else
			y->right = z;
		//把z的孩子连到NIL上,并设为红色
		z->left = NIL;
		z->right = NIL;
		z->color = RED;
		//因为z的颜色为红,有可能破坏红黑树的性质
		RBTInsertFixup(z);
	}
	return true;
}

//因为z是红色,如果z是根节点，那么性质2被破坏,如果z的父亲是红色,那么性质4被破坏
void RB_Tree::RBTInsertFixup(RBNode *z){
	while (z->parent->color == RED){
		//z的父亲是z的祖父的左孩子
		if (z->parent == z->parent->parent->left){
			//y是z的叔节点
			RBNode *y = z->parent->parent->right;
			//z父亲和y都是红色,应该把z父亲和y都变成黑色,把z的祖父变成红色(保持性质5),然后把祖父作为新的z来重复调整
			if (y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				//z的叔节点y是黑色
				//z是右孩子
				if (z == z->parent->right){
					z = z->parent;
					//左旋,z成左孩子
					LeftRotate(z);
				}
				//z是左孩子
				//z的父亲变成黑色
				z->parent->color = BLACK;
				//z的祖父变成红色,保持性质5
				z->parent->parent->color = RED;
				//右旋,z的父亲变成黑色,while结束
				RightRotate(z->parent->parent);
			}
		}
		else{
			//z的父亲是z的祖父的右孩子
			//y是z的叔节点
			RBNode *y = z->parent->parent->left;
			//z父亲和y都是红色,应该把z父亲和y都变成黑色,把z的祖父变成红色(保持性质5),然后把祖父作为新的z来重复调整
			if (y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				//z的叔节点y是黑色
				//z是左孩子
				if (z == z->parent->left){
					z = z->parent;
					//右旋,z成右孩子
					RightRotate(z);
				}
				//z是右孩子
				//z的父亲变成黑色
				z->parent->color = BLACK;
				//z的祖父变成红色,保持性质5
				z->parent->parent->color = RED;
				//右旋,z的父亲变成黑色,while结束
				LeftRotate(z->parent->parent);
			}
		}
	}
	//z是根节点,黑色
	root->color = BLACK;
}

//返回以x为根的最小节点
RBNode* RB_Tree::RBMINIMUM(RBNode *x){
	RBNode *y = x;
	while (y->left != NIL)
		y = y->left;
	return y;
}

//替换两个节点
void RB_Tree::RBTTansplant(RBNode *u, RBNode *v){
	if (u->parent == NIL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

//删除节点
bool RB_Tree::RBTDelete(int k){
	RBNode *z, *x;
	z = RBTSearch(k);
	if (z == NIL){
		cout << "包含关键值为" << z->key << "的节点不存在" << endl;
		return false;
	}
	else{
		RBNode *y = z;
		NodeColor y_original_color = y->color;//保存y的初始颜色
		if (z->left == NIL){
			x = z->right;
			RBTTansplant(z, z->right);
		}
		else if (z->right == NIL){
			x = z->left;
			RBTTansplant(z, z->left);
		}
		else{
			//y是z的后继节点
			y = RBMINIMUM(z->right);
			y_original_color = y->color;
			x = y->right;//x是y的右孩子
			//y就是z的孩子
			if (y->parent == z)
				x->parent = y;
			else{
				//把y的右孩子x放到y的位置
				RBTTansplant(y, y->right);
				//将z的右孩子作为y的右孩子
				y->right = z->right;
				y->right->parent = y;
			}
			//用y换z
			RBTTansplant(z, y);
			//把原来z的左孩子作为y的右孩子
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		if (y_original_color == BLACK){
			RBTDeleteFixup(x);
		}
		return true;
	}
}

//删除后调整红黑树
void RB_Tree::RBTDeleteFixup(RBNode *x){
	while (x != root && x->color == BLACK){
		//x是左子树
		if (x == x->parent->left){
			//w是兄弟节点
			RBNode *w = x->parent->right;
			//兄弟节点w是红色,w的节点必须是黑色,改变w和x父节点的颜色,对x父节点左旋
			if (w->color == RED){
				w->color = BLACK;
				x->parent->color = RED;
				LeftRotate(x->parent);
				w = x->parent->right;
			}
			//w是黑色,w的两个子节点是黑色,w置为红色,为了补偿去掉的一个黑色,在x父节点上补一个黑色
			if (w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}
			else {
				//w是黑色,w的左孩子是红色,w的右孩子是黑色
				if (w->right->color == BLACK){
					//交换w和w左孩子的颜色,再对w右旋
					w->left->color = BLACK;
					w->color = RED;
					RightRotate(w);
					w = x->parent->right;
				}
				//w是黑色的,w的右孩子是红色的
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				LeftRotate(x->parent);
				x = root;
			}
		}
		else{
			//w是兄弟节点
			RBNode *w = x->parent->left;
			//兄弟节点w是红色,w的节点必须是黑色,改变w和x父节点的颜色,对x父节点左旋
			if (w->color == RED){
				w->color = BLACK;
				x->parent->color = RED;
				RightRotate(x->parent);
				w = x->parent->left;
			}
			//w是黑色,w的两个子节点是黑色,w置为红色,为了补偿去掉的一个黑色,在x父节点上补一个黑色
			if (w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}
			else {
				//w是黑色,w的左孩子是红色,w的右孩子是黑色
				if (w->left->color == BLACK){
					//交换w和w左孩子的颜色,再对w右旋
					w->right->color = BLACK;
					w->color = RED;
					LeftRotate(w);
					w = x->parent->left;
				}
				//w是黑色的,w的右孩子是红色的
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				RightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

//中序遍历
void RB_Tree::InOrderTraverse(){
	RBNode *y = root;
	stack<RBNode *> s;
	while (y != NIL || !s.empty()){
		//将所有最左边的节点入栈
		if (y != NIL){
			s.push(y);
			y = y->left;
		}
		else{
			//访问左节点
			y = s.top();
			s.pop();
			if (y->color == 0){
				cout << y->key << "红"<< " ";
			}
			else{
				cout << y->key << "黑" << " ";
			}
			//y为叶节点时下次取出的是根节点,否则就是右子节点
			y = y->right;
		}
	}
}