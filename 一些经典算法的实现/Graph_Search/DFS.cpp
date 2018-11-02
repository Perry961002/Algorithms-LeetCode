#include<iostream>
#include<vector>
#include<queue>
using namespace std;

enum color {white, gray, black};
int time = -1;

struct Node{
	int s;//开始访问时间
	int e;//结束访问时间
	int p;//前驱节点
	color c;//颜色
	Node() :p(-1), c(white){}
};

//从u开始广度优先遍历
//Adj是输入的邻接表, V是点集, u是开始节点
void DFS_Visit(vector<vector<int>>& Adj, vector<Node>& V, int u){
	//开始访问节点u
	time++;
	V[u].s = time;
	V[u].c = gray;
	cout << "(" << u;
	//往纵深方向搜索
	for (int next : Adj[u]){
		if (V[next].c == white){
			V[next].p = u;
			DFS_Visit(Adj, V, next);
		}
	}
	//对节点u访问结束
	V[u].c = black;
	time++;
	V[u].e = time;
	cout << ")";
}

//以DFS方式访问整个图
void DFS(vector<vector<int>>& Adj){
	vector<Node> V(Adj.size());
	for (int i = 0; i < Adj.size(); i++){
		if (V[i].c == white){
			DFS_Visit(Adj, V, i);
			cout << endl;
		}
	}
}

int main(){
	int n, m;
	cout << "输入点数和边数：";
	cin >> n >> m;
	vector<vector<int>> Adj(n);//邻接表
	int flag;
	cout << "无向图选0,有向图选1：";
	cin >> flag;
	cout << "输入边的两个端点(如果是有向图的话注意顺序)：" << endl;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if (flag){
			Adj[u].push_back(v);
		}
		else{
			Adj[u].push_back(v);
			Adj[v].push_back(u);
		}
	}
	cout << "访问顺序为( '('表示开始访问, ')'表示访问结束)：" << endl;
	DFS(Adj);
	system("pause");
	return 0;
}