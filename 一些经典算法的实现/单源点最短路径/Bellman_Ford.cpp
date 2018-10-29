#include<iostream>
#include<vector>
using namespace std;
const int MAXDISTANCE = 100000;
//有向边定义
struct Edge{
	int start, end;//有向边的端点
	int weight;//边的权值
	Edge() :start(-1), end(-1), weight(0){}
};

//点的定义
struct Node{
	int parent;//前驱节点
	int  d;//最短路径估计
	Node() :parent(-1), d(MAXDISTANCE){}
};

//初始化最短路径树
//n是节点数,s是源点
vector<Node> InitializeSingleSource(int n, int s){
	vector<Node> res(n);
	res[s].d = 0;
	return res;
}

//松弛操作
//输入最短路径树, 有向边<u, v>及他的权值
void RELAX(vector<Node>& SPT, int u, int v, int w){
	if (SPT[v].d > SPT[u].d + w){
		SPT[v].d = SPT[u].d + w;
		SPT[v].parent = u;
	}
}

//Bellman-Ford算法
//返回False表示输入的图中包含从源节点到达的权值为负的环路
//SPT表示最短路径树, edges是边集合, n是点的个数
bool Bellman_Ford(vector<Node>& SPT, vector<Edge>& edges, int n){
	//对每条边进行|V| - 1次松弛操作
	for (int i = 0; i < n - 1; i++){
		for (auto e : edges){
			RELAX(SPT, e.start, e.end, e.weight);
		}
	}
	//判断是否存在权值为负的环路
	//如果存在的话,每经过一次环路时最短路径都会更小
	//存在就返回false, 否则返回true
	for (auto e : edges){
		if (SPT[e.end].d > SPT[e.start].d + e.weight)
			return false;
	}
	return true;
}

//根据最短路径树打印从点v到点s的最短路径
void Print_Path(vector<Node>& SPT, int s, int v){
	if (v == s){
		cout << s;
	}
	else if (SPT[v].d == MAXDISTANCE){
		cout << "不存在从节点" << s << "到节点" << v << "的路径" << endl;
	}
	else{
		Print_Path(SPT, s, SPT[v].parent);
		cout << "-->" << v ;
	}
}

int main(){
	cout << "输入节点数和有向边的个数：";
	int n, m;
	cin >> n >> m;
	vector<Edge> edges(m);
	cout << "输入有向边的起点,终点,权值(每条边权值不要超过100,路径长度不要超过100000,节点编号从0开始)：" << endl;
	int input1, input2, input3;
	for (int i = 0; i < m; i++){
		cin >> input1 >> input2 >> input3;
		edges[i].start = input1;
		edges[i].end = input2;
		edges[i].weight = input3;
	}
	cout << "输入源点：";
	int s; cin >> s;
	vector<Node> SPT = InitializeSingleSource(n, s);
	if (!Bellman_Ford(SPT, edges, n)){
		cout << "图中存在权值为负的环路" << endl;
	}
	else{
		cout << "各条最短路径为：" << endl;
		for (int i = 0; i < n; i++){
			if (i != s){
				Print_Path(SPT, s, i);
				cout << " 最短路径权值为:" << SPT[i].d << endl;
			}
		}
	}
	system("pause");
	return 0;
}