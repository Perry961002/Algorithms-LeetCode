#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int MAXDISTANCE = 100000;

//点的定义
struct Node{
	int parent;//前驱节点
	int  d;//最短路径估计
	Node() :parent(-1), d(MAXDISTANCE){}
};

//拓扑排序算法
vector<int> Topological_Sort(vector<vector<pair<int, int>>>& Adj, vector<int>& InDegree){
	stack<int> S;
	vector<int> res;
	//将入度为0的节点入栈
	for (int i = 0; i < InDegree.size(); i++){
		if (InDegree[i] == 0)
			S.push(i);
	}
	//深度搜索,拓扑排序
	while (!S.empty()){
		int node = S.top();
		S.pop();
		//搜索与节点相连的点
		for (auto i : Adj[node]){
			InDegree[i.first]--;//更新节点的入度信息
			//入度为0了,加入结果数组
			if (InDegree[i.first] == 0)
				S.push(i.first);
		}
		//node成为孤立节点
		res.push_back(node);
	}
	return res;
}

//初始化最短路径树
//n是节点数,s是源点
vector<Node> InitializeSingleSource(int n, int s){
	vector<Node> res(n);
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

//DAG算法
//SortRes是拓扑排序之后的节点数组, Adj是邻接表, SPT是最短路径树, s是源点
void DAG_Shortest_Paths(vector<int>& SortRes, vector<vector<pair<int, int>>>& Adj, vector<Node> SPT, int s){
	for (int u : SortRes){
		for (auto v : Adj[u]){
			RELAX(SPT, u, v.first, v.second);
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
	vector<int> InDegree(n, 0);//计算节点的入度
	cout << "输入有向边的起点,终点,权值(每条边权值不要超过100,路径长度不要超过100000,节点编号从0开始)：" << endl;
	int input1, input2, input3;
	for (int i = 0; i < m; i++){
		cin >> input1 >> input2 >> input3;
		Adj[input1].push_back(make_pair(input2, input3));
		InDegree[input2]++;
	}
	vector<int> SortRes = Topological_Sort(Adj, InDegree);
	cout << "输入源点：";
	int s; cin >> s;
	vector<Node> SPT = InitializeSingleSource(n, s);
	DAG_Shortest_Paths(SortRes, Adj, SPT, s);
	system("pause");
	return 0;
}