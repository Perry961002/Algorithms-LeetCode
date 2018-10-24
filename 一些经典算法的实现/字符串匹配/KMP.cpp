#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> Compute_Prefix(string& P){
	int m = P.size();
	//前缀数组,P[q] = k表示Pq的真后缀的所有前缀Pk
	vector<int> next(m);
	next[0] = 0;
	int k = 0;//初始化0
	for (int q = 1; q < m; q++){
		//递推计算next[q]
		while (k > 0 && P[q] != P[k])
			k = next[k-1];
		//Pk扩展到Pk+1，得到Pq的真后缀
		if (P[q] == P[k])
			k++;
		next[q] = k;
	}
	return next;
}

void KMP_Matcher(string& T, string& P){
	int n = T.size();
	int m = P.size();
	vector<int> next = Compute_Prefix(P);
	//打印next
	for (int i = 0; i < m; i++)
		cout << next[i] << " ";
	cout << endl;
	int q = 0;//已经匹配的字符数
	for (int i = 0; i < n; i++){
		//出现不匹配,回到之前的q
		while (q > 0 && P[q] != T[i])
			q = next[q-1];
		//匹配了新的字符
		if (P[q] == T[i])
			q ++;
		if (q == m){
			cout << "Pattern occurs with shift: " << i - m + 1 << endl;
			//重置q
			q = next[m-1];
		}
	}
}

int main(){
	string P = "ababaca", T = "bacbababacaababcababacaaba";
	vector<int> test = Compute_Prefix(P);
	KMP_Matcher(T, P);
	system("pause");
}