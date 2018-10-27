#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
	int u, v;//路径的两端
	int w;//路径的权重
	Edge(int a, int b, int c) : u(a), v(b), w(c){}
};

//按权重从小到大对边排序 
bool cmp(const Edge& a, const Edge& b){
	return a.w < b.w;
}

//为点创造不相交集合
//返回数组vector<pair<int, int>> parent, parent[i].first表示点i的祖先节点,parent[i].second表示点isuoz集合的大小
vector<pair<int, int>> MakeSet(int n){
	vector<pair<int, int>> parent;
	for (int i = 0; i < n; i++){
		parent.push_back(make_pair(i, 1));
	}
	return parent;
}

//返回x所在集合的祖先
int FindParent(vector<pair<int, int>>& parent, int x){
	while (x != parent[x].first)
		x = parent[x].first;
	return x;
}

//将两个不同祖先的数合并为同一个祖先
void Union(vector<pair<int, int>>& parent, int x, int y){
	//把集合小的归到大的里面,这样查询时可以减少查询次数
	if (parent[x].second > parent[y].second){
		parent[y].first = x;
		parent[x].second += parent[y].second;
	}
	else{
		parent[x].first = y;
		parent[y].second += parent[x].second;
	}
}

//kruskal算法
vector<Edge> Kruskal(vector<Edge>& edges, int n){
	vector<Edge> res;
	vector<pair<int, int>> parent = MakeSet(n);
	for (auto e : edges){
		int x = FindParent(parent, e.u), y = FindParent(parent, e.v);
		//当前边的加入不会构成环路
		if (x != y){
			res.push_back(e);
			Union(parent, x, y);
			if (res.size() == n - 1)
				break;
		}
	}
	return res;
}

int main(){
	int n, m;
	cout << "请输入点数和边数：";
	cin >> n >> m;
	vector<Edge> edges, res;
	cout << "请输入边的两个端点(端点编号从0开始)和权值：" << endl;
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		Edge e = Edge(a, b, c);
		edges.push_back(e);
	}
	sort(edges.begin(), edges.end(), cmp);
	res = Kruskal(edges, n);
	cout << "结果为：" << endl;
	int sum = 0;
	for (auto e : res){
		cout << e.u << " " << e.v <<" "<< e.w << endl;
		sum += e.w;
	}
	cout << "最小权值和为：" << sum << endl;
	system("pause");
	return 0;
}