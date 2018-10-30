#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXNUM = 100000;

//自底向上计算最短路径权重
vector<vector<int>> Extxnd_Shortest_Paths(vector<vector<int>>& L, vector<vector<int>>& W){
	int n = L.size();
	vector<vector<int>> res(n, vector<int>(n, MAXNUM));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				if (res[i][j] > L[i][k] + W[k][j]){
					res[i][j] = L[i][k] + W[k][j];
				}
			}
		}
	}
	return res;
}

//使用重复平方技术计算矩阵
void Faster_APSP(vector<vector<int>>& W){
	int n = W.size();
	int m = 1;
	while (m < n - 1){
		W = Extxnd_Shortest_Paths(W, W);
		m *= 2;
	}
	//求解好了,打印路径
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (W[i][j] == MAXNUM){
				if (i != j)
					cout << "不存在从节点" << i << "到节点" << j << "的最短路径" << endl;
			}
			else if (i != j){
				cout << "从" << i << "到" << j << "的最短路径长度为" << W[i][j] << endl;
			}
		}
	}
}

int main(){
	int n, m;//顶点数和边数
	cout << "输入顶点数和边数：";
	cin >> n >> m;
	vector<vector<int>> W(n, vector<int>(n, MAXNUM));//邻接矩阵
	//对角线置0
	for (int i = 0; i < n; i++)
		W[i][i] = 0;
	vector<vector<int>> Path(n, vector<int>(n, -1));//前驱子图矩阵
	cout << "输入边的起点,终点,权重：" << endl;
	int u, v, w;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> w;
		W[u][v] = w;
	}
	Faster_APSP(W);
	system("pause");
	return 0;
}