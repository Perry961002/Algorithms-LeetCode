#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXDISTANCE = 100000;

//点的定义
struct Node{
	int id;//当前节点下标
	int parent;//前驱节点
	int  d;//最短路径估计
	Node() :id(-1), parent(-1), d(MAXDISTANCE){}
};

struct cmp {
	bool operator() (Node& a, Node& b){
		return a.d > b.d;
	}
};
//初始化最短路径树
//n是节点数,s是源点
vector<Node> InitializeSingleSource(int n, int s){
	vector<Node> res(n);
	for (int i = 0; i < n; i++)
		res[i].id = i;
	res[s].d = 0;
	return res;
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
		cout << "-->" << v;
	}
}

//松弛操作
//输入最短路径树, 有向边<u, v>及他的权值
void RELAX(vector<Node>& SPT, int u, int v, int w){
	if (SPT[v].d > SPT[u].d + w){
		SPT[v].d = SPT[u].d + w;
		SPT[v].parent = u;
	}
}

//Dijkstra算法
//SPT是最短路径树, Adj是邻接表, s是源点
void Dijkstra(vector<Node>& SPT, vector<vector<pair<int, int>>>& Adj, int s){
	vector<bool> visited(SPT.size(), false);//标记是否访问,false表示未访问
	priority_queue<Node, vector<Node>, cmp> Q;//优先队列
	Q.push(SPT[s]);
	while (!Q.empty()){
		int u = Q.top().id;//当前节点
		Q.pop();
		if (visited[u])
			continue;
		visited[u] = true;
		for (auto v : Adj[u]){
			if (!visited[v.first]){
				RELAX(SPT, u, v.first, v.second);
				Q.push(SPT[v.first]);
			}
		}
	}
	cout << "各条最短路径为：" << endl;
	for (int i = 0; i < SPT.size(); i++){
		if (i != s){
			Print_Path(SPT, s, i);
			cout << " 最短路径权值为:" << SPT[i].d << endl;
		}
	}
}

int main(){
	cout << "输入节点数和有向边的个数：";
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> Adj(n);//邻接表
	cout << "输入有向边的起点,终点,权值(每条边权值不要超过100,路径长度不要超过100000,节点编号从0开始)：" << endl;
	int input1, input2, input3;
	for (int i = 0; i < m; i++){
		cin >> input1 >> input2 >> input3;
		Adj[input1].push_back(make_pair(input2, input3));
	}
	cout << "输入源点：";
	int s; cin >> s;
	vector<Node> SPT = InitializeSingleSource(n, s);
	Dijkstra(SPT, Adj, s);
	system("pause");
	return 0;
}