#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//拓扑排序算法
vector<int> Topological_Sort(vector<vector<int>>& Adj, vector<int>& InDegree){
	stack<int> S;
	vector<int> res;
	//将入度为0的节点入栈
	for (int i = 0; i < InDegree.size();i++){
		if (InDegree[i] == 0)
			S.push(i);
	}
	//深度搜索,拓扑排序
	while (!S.empty()){
		int node = S.top();
		S.pop();
		//搜索与节点相连的点
		for (int i : Adj[node]){
			InDegree[i]--;//更新节点的入度信息
			//入度为0了,加入结果数组
			if (InDegree[i] == 0)
				S.push(i);
		}
		//node成为孤立节点
		res.push_back(node);
	}
	return res;
}
int main(){
	cout << "输入节点数和有向边的个数：";
	int n, m;
	cin >> n >> m;
	vector<vector<int>> Adj(n);//邻接表
	cout << Adj.size() << endl;
	vector<int> InDegree(n, 0);//计算节点的入度
	cout << "输入有向边的起点,终点(节点编号从0开始)：" << endl;
	int input1, input2;
	for (int i = 0; i < m; i++){
		cin >> input1 >> input2 ;
		Adj[input1].push_back(input2);
		InDegree[input2]++;
	}
	vector<int> SortRes = Topological_Sort(Adj, InDegree);
	if (SortRes.size() != n){
		cout << "图中存在环路,不能拓扑排序" << endl;
	}
	else{
		for (int i : SortRes)
			cout << i << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}