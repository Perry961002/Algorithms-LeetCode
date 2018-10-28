#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//存放在邻接表中的节点
struct Node{
	int id;//当前点的编号
	int key;//边的权值
	//构造方法
	Node(int x, int k) :id(x), key(k){}
};

//Prim算法实现,start为开始节点编号
int Prim(vector<vector<Node>>& edges, int start){
	int n = edges.size();//节点数
	vector<bool> visited(n, false);//节点访问标识
	vector<int> path;//已经处理过的节点
	path.push_back(start);
	visited[start] = true;
	int nodeSum = 1, keySum = 0;
	int end = -1;
	while (nodeSum < n){
		int minKey = INT_MAX;
		//遍历已经处理过的节点
		for (int now : path){
			//遍历还没有处理的节点
			for (auto next : edges[now]){
				//选择连接path和path之外所有点的所有边中权值最小的一个
				if (!visited[next.id] && next.key < minKey){
					minKey = next.key;
					start = now;
					end = next.id;
				}
			}
		}
		nodeSum++;
		visited[end] = true;
		path.push_back(end);
		cout << start << "----" << end << " " << minKey << endl;
		keySum += minKey;
	}
	return keySum;
}
int main(){
	int n, m;//点数,边数
	cout << "请输入点数和边数：";
	cin >> n >> m;
	vector<vector<Node>> edges(n);//邻接表
	cout << "请输入边的两个端点(编号从0开始)和权值:" << endl;
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		Node tmp = Node(b, c);
		edges[a].push_back(tmp);
		tmp = Node(a, c);
		edges[b].push_back(tmp);
	}
	cout << "输入开始节点：";
	int start; cin >> start;
	int res = Prim(edges, start);
	cout << "最小权值和为：" << res << endl;
	system("pause");
	return 0;
}