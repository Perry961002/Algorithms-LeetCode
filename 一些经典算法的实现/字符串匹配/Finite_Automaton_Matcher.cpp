#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

//判断Pk是不是Pq+a的后缀(下标从1开始)
bool isPostfix(string &P, int k, int q, char a){
	//空串是每一个字符串的后缀
	if (k == 0)
		return true;
	string target = P.substr(0, q) + a;
	//倒序比较
	for (int i = k - 1; i >= 0; i--){
		if (P[i] != target.back())
			return false;
		target.pop_back();
	}
	return true;
}

//计算并返回转移函数,P是模式串,A是字符集
vector<unordered_map<char, int>> Compute_Transition(string &P, string &A){
	int m = P.size();
	vector<unordered_map<char, int>> transition(m + 1);
	for (int q = 0; q <= m; q++){
		for (char a : A){
			int k = min(m, q + 1);// 1<= k <= m
			//把transition[q][a]置为满足Pk是Pq+a后缀的最大的k
			while (!isPostfix(P, k, q, a))
				k--;
			transition[q][a] = k;
		}
	}
	return transition;
}

//匹配函数,T是文本串, transition是转移函数, m是自动机的唯一接受状态
void Finite_Automaton_Matcher(string &T, vector<unordered_map<char, int>>& transition, int m){
	bool flag = false;//标志是否匹配成功
	int n = T.size();
	int q = 0;//q是初始状态
	for (int i = 0; i < n; i++){
		//得到T[i]的状态
		q = transition[q][T[i]];
		//q是接受状态,P匹配成功
		if (q == m){
			cout << "Pattern occurs with shift: " << i - m + 1 << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << "Not Fount" << endl;
}

int main(){
	string A = "abc", P = "ababaca", T = "bacbababacaababcababacaaba";
	vector<unordered_map<char, int>> transition_map = Compute_Transition(P, A);
	cout << "转移函数为：" << endl;
	for (int i = 0; i < transition_map.size(); i++){
		for (char a : A){
			cout << transition_map[i][a] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Finite_Automaton_Matcher(T, transition_map, P.size());
	system("pause");
}