#include<iostream>
#include<vector>
#include<queue>
using namespace std;

enum color {white, gray, black};

struct Node{
	int d;//距离
	int p;//前驱节点
	color c;//颜色
	Node() :d(INT_MAX), p(-1), c(white){}
};

//通过访问广度优先树打印从s到v的最短路径
void PrintPath(vector<Node>& BFT, int s, int v){
	if (v == s){
		cout << s;
	}
	else if (BFT[v].d == INT_MAX){
		cout << "不存在从点" << s << "到点" << v << "的最短路径" << endl;
	}
	else{
		PrintPath(BFT, s, BFT[v].p);
		cout << "-->" << v;
	}
}

//广度优先遍历
//Adj是输入的邻接表, s是源点
void BFS(vector<vector<int>>& Adj, int s){
	//下面三行初始化广度优先树
	vector<Node> BFT(Adj.size());
	BFT[s].d = 0;
	BFT[s].c = gray;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()){
		int u = Q.front();//取队头
		Q.pop();
		//遍历与u连接的所有点
		for (int v : Adj[u]){
			//v没有被访问
			if (BFT[v].c == white){
				//以下三行修改v的前驱性质
				BFT[v].c = gray;
				BFT[v].d = BFT[u].d + 1;
				BFT[v].p = u;
				Q.push(v);
			}
		}
		BFT[u].c = black;
	}
	//开始打印
	for (int i = 0; i < Adj.size(); i++){
		if (i != s){
			PrintPath(BFT, s, i);
			if (BFT[i].d != INT_MAX)
				cout << "路径长度为:" << BFT[i].d << endl;
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
	int s;
	cout << "输入源点：";
	cin >> s;
	BFS(Adj, s);
	system("pause");
	return 0;
}