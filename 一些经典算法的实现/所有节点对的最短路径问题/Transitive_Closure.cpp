#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//用类似Floyd_Warshall算法的方法迭代计算邻接矩阵
void Transitive_Closure(vector<vector<bool>>& G){
	int n = G.size();
	//动态规划
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				G[i][j] = G[i][j] || (G[i][k] && G[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (G[i][j] && i != j)
				cout << "从点" << i << "到点" << j << "有路径可达" << endl;
		}
	}
}
int main(){
	int n, m;//顶点数和边数
	cout << "输入顶点数和边数：";
	cin >> n >> m;
	vector<vector<bool>> G(n, vector<bool>(n, false));//邻接矩阵
	//对角线置true
	for (int i = 0; i < n; i++)
		G[i][i] = true;
	cout << "输入边的起点,终点：" << endl;
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v ;
		G[u][v] = true;
	}
	Transitive_Closure(G);
	system("pause");
	return 0;
}