#include<iostream>
#include<string>
#include<queue>
using namespace std;

//定义哈夫曼树的节点
struct TreeNode{
	char key;//字符
	int freq;//频数
	TreeNode *left, *right;//左右子节点的指针
	TreeNode(char k, int f) :key(k), freq(f), left(nullptr), right(nullptr){}
};

//自定义比较函数,用于优先队列
struct cmp{
	bool operator() (TreeNode* a, TreeNode* b){
		return a->freq > b->freq;
	}
};

//打印哈夫曼编码
void PrintTree(TreeNode* root, string s){
	if (root == nullptr)
		return;
	//左支为0
	if (root->left)
		s += '0';
	PrintTree(root->left, s);
	//到叶子节点了就打印
	if (!root->left && !root->right){
		cout << "字符为：" << root->key << "	" << "哈夫曼编码为：" << s << endl;
	}
	s.pop_back();//回退一个字符
	//右支为1
	if (root->right)
		s += '1';
	PrintTree(root->right, s);
}

//构造哈夫曼树
void Huffman(priority_queue<TreeNode*, vector<TreeNode*>, cmp>& Q){
	while (Q.size() > 1){
		TreeNode* pl = Q.top();//左节点
		Q.pop();
		TreeNode* pr = Q.top();//右节点
		Q.pop();
		TreeNode* p = new TreeNode('\0', 0);
		p->freq = pl->freq + pr->freq;//设置新节点的频数
		//将原来的两个节点接到新的节点上
		p->left = pl; 
		p->right = pr;
		Q.push(p);
	}
	//while结束后,哈夫曼树构造完成,打印他
	string s = "";
	PrintTree(Q.top(), s);
}
int main(){
	cout << "输入字符种类数:";
	int num; cin >> num;
	priority_queue<TreeNode*, vector<TreeNode*>, cmp> Q;
	cout << "请输入字符和他的频数:" << endl;
	for (int i = 0; i < num; i++){
		char c; int count;
		cin >> c >> count;
		TreeNode* tmp = new TreeNode(c, count);
		Q.push(tmp);
	}
	Huffman(Q);
	system("pause");
}