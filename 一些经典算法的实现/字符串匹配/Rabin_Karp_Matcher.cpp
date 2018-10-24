#include<iostream>
#include<string>

using namespace std;

//判断P和T是否相等,相等就返回true
bool isSame(string P, string T){
	for (int i = 0; i < P.size(); i++){
		if (P[i] != T[i])
			return false;
	}
	return true;
}

//T是文本, P是模式串, d是字典的大小, q是素数
void Rabin_Karp_Matcher(string T, string P, int d, int q){
	int n = T.size();
	int m = P.size();
	//计算h
	int h = 1;
	for (int i = 0; i < m - 1; i++)
		h = (h * d) % q;
	int p = 0, t = 0;
	//利用霍纳法则计算P和T对应的d进制值
	for (int i = 0; i < m; i++){
		p = (d * p + (P[i] - 'a')) % q;
		t = (d * t + (T[i] - 'a')) % q;
	}
	//开始匹配
	for (int s = 0; s <= n - m; s++){
		//启发式测试
		if (p == t){
			//判断s是真的有效还是一个伪命中点
			if (isSame(P, T.substr(s, m)))
				cout << "Pattern occurs with shift " << s << endl;
		}
		//计算下一个t
		if (s < n - m){
			t = (d * (t - (T[s] - 'a') * h) + (T[s + m] - 'a')) % q;
			//对小于0的情况进行修正
			if (t < 0)
				t += q;
		}
	}
}

int main(){
	string T = "fdstabcdesgdyfgabdfgsabcdehfd";
	string P = "abcde";
	Rabin_Karp_Matcher(T, P, 26, 29);
	system("pause");
}