#include"RBTree.h"
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

RBNode nil(-1);
RBNode *NIL = &nil;

//�ڵ㹹��
RBNode::RBNode(int k):key(k){
	parent = left = right = NIL;
	color = BLACK;
}

//���������
RB_Tree::RB_Tree(RBNode *n) :root(n){
	n->parent = n->left = n->right = NIL;
}

//��xΪ���Ľ�������
void RB_Tree::LeftRotate( RBNode *x){
	RBNode *y = x->right;//ȡx����ڵ�
	x->right = y->left;//y�����ӱ��x���Һ���
	//y����x�ĸ��׽ڵ�
	if (y->left != NIL)
		y->left->parent = x;
	y->parent = x->parent;
	//����x�����ҽڵ�������ȷ��y����x���ڵ���ĸ���֧��
	//x�Ǹ�
	if (x->parent == NIL)
		root = y;
	//�Ǹ��ڵ������
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	//��x�ŵ�y��������
	y->left = x;
	x->parent = y;//�޸�x�ĸ��׽ڵ�Ϊy����������
}

//��xΪ���Ľ�������
void RB_Tree::RightRotate(RBNode *x){
	RBNode *y = x->left;//ȡx����ڵ�
	x->left = y->right;//y�����ӱ��x���Һ���
	//y����x�ĸ��׽ڵ�
	if (y->right != NIL)
		y->right->parent = x;
	y->parent = x->parent;
	//����x�����ҽڵ�������ȷ��y����x���ڵ���ĸ���֧��
	//x�Ǹ�
	if (x->parent == NIL)
		root = y;
	//�Ǹ��ڵ������
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	//��x�ŵ�y���Һ�����
	y->right = x;
	x->parent = y;//�޸�x�ĸ��׽ڵ�Ϊy����������
}

//��ǰ�������ʽ���������,�ҵ��ͷ���true
RBNode* RB_Tree::RBTSearch(int k){
	RBNode *x = root;
	while (x != NIL){
		if (x->key == k)
			return x;
		//������������
		else if (x->key < k)
			x = x->right;
		else
			x = x->left;
	}
	return x;//û���ҵ�
}

//���ڵ�z���뵽�����
bool RB_Tree::RBTInsert(RBNode *z){
	if (RBTSearch(z->key) != NIL){
		cout << "�����ؼ�ֵΪ" << z->key << "�Ľڵ��Ѿ�����" << endl;
		return false;
	}
	else{
		//����zӦ�ñ������λ��,������ɫ��Ϊ��
		RBNode *x = root;
		RBNode *y = NIL;
		//�ҵ�zӦ�õ�λ��
		while (x != NIL){
			y = x;
			if (z->key < x->key)
				x = x->left;
			else if (z->key > x->key)
				x = x->right;
		}
		z->parent = y;
		//ȷ��zӦ���Ǹ��׽ڵ���ĸ�����
		if (y == NIL)
			root = z;
		else if (z->key < y->key)
			y->left = z;
		else
			y->right = z;
		//��z�ĺ�������NIL��,����Ϊ��ɫ
		z->left = NIL;
		z->right = NIL;
		z->color = RED;
		//��Ϊz����ɫΪ��,�п����ƻ������������
		RBTInsertFixup(z);
	}
	return true;
}

//��Ϊz�Ǻ�ɫ,���z�Ǹ��ڵ㣬��ô����2���ƻ�,���z�ĸ����Ǻ�ɫ,��ô����4���ƻ�
void RB_Tree::RBTInsertFixup(RBNode *z){
	while (z->parent->color == RED){
		//z�ĸ�����z���游������
		if (z->parent == z->parent->parent->left){
			//y��z����ڵ�
			RBNode *y = z->parent->parent->right;
			//z���׺�y���Ǻ�ɫ,Ӧ�ð�z���׺�y����ɺ�ɫ,��z���游��ɺ�ɫ(��������5),Ȼ����游��Ϊ�µ�z���ظ�����
			if (y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				//z����ڵ�y�Ǻ�ɫ
				//z���Һ���
				if (z == z->parent->right){
					z = z->parent;
					//����,z������
					LeftRotate(z);
				}
				//z������
				//z�ĸ��ױ�ɺ�ɫ
				z->parent->color = BLACK;
				//z���游��ɺ�ɫ,��������5
				z->parent->parent->color = RED;
				//����,z�ĸ��ױ�ɺ�ɫ,while����
				RightRotate(z->parent->parent);
			}
		}
		else{
			//z�ĸ�����z���游���Һ���
			//y��z����ڵ�
			RBNode *y = z->parent->parent->left;
			//z���׺�y���Ǻ�ɫ,Ӧ�ð�z���׺�y����ɺ�ɫ,��z���游��ɺ�ɫ(��������5),Ȼ����游��Ϊ�µ�z���ظ�����
			if (y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				//z����ڵ�y�Ǻ�ɫ
				//z������
				if (z == z->parent->left){
					z = z->parent;
					//����,z���Һ���
					RightRotate(z);
				}
				//z���Һ���
				//z�ĸ��ױ�ɺ�ɫ
				z->parent->color = BLACK;
				//z���游��ɺ�ɫ,��������5
				z->parent->parent->color = RED;
				//����,z�ĸ��ױ�ɺ�ɫ,while����
				LeftRotate(z->parent->parent);
			}
		}
	}
	//z�Ǹ��ڵ�,��ɫ
	root->color = BLACK;
}

//������xΪ������С�ڵ�
RBNode* RB_Tree::RBMINIMUM(RBNode *x){
	RBNode *y = x;
	while (y->left != NIL)
		y = y->left;
	return y;
}

//�滻�����ڵ�
void RB_Tree::RBTTansplant(RBNode *u, RBNode *v){
	if (u->parent == NIL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

//ɾ���ڵ�
bool RB_Tree::RBTDelete(int k){
	RBNode *z, *x;
	z = RBTSearch(k);
	if (z == NIL){
		cout << "�����ؼ�ֵΪ" << z->key << "�Ľڵ㲻����" << endl;
		return false;
	}
	else{
		RBNode *y = z;
		NodeColor y_original_color = y->color;//����y�ĳ�ʼ��ɫ
		if (z->left == NIL){
			x = z->right;
			RBTTansplant(z, z->right);
		}
		else if (z->right == NIL){
			x = z->left;
			RBTTansplant(z, z->left);
		}
		else{
			//y��z�ĺ�̽ڵ�
			y = RBMINIMUM(z->right);
			y_original_color = y->color;
			x = y->right;//x��y���Һ���
			//y����z�ĺ���
			if (y->parent == z)
				x->parent = y;
			else{
				//��y���Һ���x�ŵ�y��λ��
				RBTTansplant(y, y->right);
				//��z���Һ�����Ϊy���Һ���
				y->right = z->right;
				y->right->parent = y;
			}
			//��y��z
			RBTTansplant(z, y);
			//��ԭ��z��������Ϊy���Һ���
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

//ɾ������������
void RB_Tree::RBTDeleteFixup(RBNode *x){
	while (x != root && x->color == BLACK){
		//x��������
		if (x == x->parent->left){
			//w���ֵܽڵ�
			RBNode *w = x->parent->right;
			//�ֵܽڵ�w�Ǻ�ɫ,w�Ľڵ�����Ǻ�ɫ,�ı�w��x���ڵ����ɫ,��x���ڵ�����
			if (w->color == RED){
				w->color = BLACK;
				x->parent->color = RED;
				LeftRotate(x->parent);
				w = x->parent->right;
			}
			//w�Ǻ�ɫ,w�������ӽڵ��Ǻ�ɫ,w��Ϊ��ɫ,Ϊ�˲���ȥ���һ����ɫ,��x���ڵ��ϲ�һ����ɫ
			if (w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}
			else {
				//w�Ǻ�ɫ,w�������Ǻ�ɫ,w���Һ����Ǻ�ɫ
				if (w->right->color == BLACK){
					//����w��w���ӵ���ɫ,�ٶ�w����
					w->left->color = BLACK;
					w->color = RED;
					RightRotate(w);
					w = x->parent->right;
				}
				//w�Ǻ�ɫ��,w���Һ����Ǻ�ɫ��
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				LeftRotate(x->parent);
				x = root;
			}
		}
		else{
			//w���ֵܽڵ�
			RBNode *w = x->parent->left;
			//�ֵܽڵ�w�Ǻ�ɫ,w�Ľڵ�����Ǻ�ɫ,�ı�w��x���ڵ����ɫ,��x���ڵ�����
			if (w->color == RED){
				w->color = BLACK;
				x->parent->color = RED;
				RightRotate(x->parent);
				w = x->parent->left;
			}
			//w�Ǻ�ɫ,w�������ӽڵ��Ǻ�ɫ,w��Ϊ��ɫ,Ϊ�˲���ȥ���һ����ɫ,��x���ڵ��ϲ�һ����ɫ
			if (w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}
			else {
				//w�Ǻ�ɫ,w�������Ǻ�ɫ,w���Һ����Ǻ�ɫ
				if (w->left->color == BLACK){
					//����w��w���ӵ���ɫ,�ٶ�w����
					w->right->color = BLACK;
					w->color = RED;
					LeftRotate(w);
					w = x->parent->left;
				}
				//w�Ǻ�ɫ��,w���Һ����Ǻ�ɫ��
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

//�������
void RB_Tree::InOrderTraverse(){
	RBNode *y = root;
	stack<RBNode *> s;
	while (y != NIL || !s.empty()){
		//����������ߵĽڵ���ջ
		if (y != NIL){
			s.push(y);
			y = y->left;
		}
		else{
			//������ڵ�
			y = s.top();
			s.pop();
			if (y->color == 0){
				cout << y->key << "��"<< " ";
			}
			else{
				cout << y->key << "��" << " ";
			}
			//yΪҶ�ڵ�ʱ�´�ȡ�����Ǹ��ڵ�,����������ӽڵ�
			y = y->right;
		}
	}
}