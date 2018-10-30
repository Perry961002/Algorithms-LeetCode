#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXNUM = 100000;

//打印路径
//Path是前驱子图, i是起点, j是终点
void PrintPath(vector<vector<int>>& Path, int i, int j){
	int k = Path[i][j];//i到j最短路径上j的前驱节点
	if (k == -1)
		return;
	else{
		PrintPath(Path, i, k);
		cout << k << "-->";
		PrintPath(Path, k, j);
	}
}

//Floyd算法
//W表示邻接矩阵,Path表示前驱子图矩阵
void Floyd_Warshall(vector<vector<int>>& W, vector<vector<int>>& Path){
	/**
	*令d(i, j, k)为从节点i到节点j的所有节点全部取自集合{1, 2,..., k}的一条最短路径的权重
	*动态转移方程为:
	*	d(i, j, k) = min(d(i, j, k-1), d(i, k, k-1) + d(k, j, k-1)) k >= 1
	*			   = w(i, j) k == 0
	*/
	int n = W.size();
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (W[i][j] > W[i][k] + W[k][j]){
					W[i][j] = W[i][k] + W[k][j];
					Path[i][j] = k;//记录路径
				}
			}
		}
	}
	//求解好了,打印路径
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (W[i][j] == MAXNUM){
				if (i != j)
					cout << "不存在从节点" << i << "到节点" << j << "的最短路径" << endl;
			}
			else if(i != j){
				cout << "从" << i << "到" << j << "的最短路径长度为" << W[i][j] << "	路径：";
				cout << i << "-->";
				PrintPath(Path, i, j);
				cout << j << endl;
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
	Floyd_Warshall(W, Path);
	system("pause");
	return 0;
}