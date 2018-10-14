#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//返回最长回文子串
string longestPalindrome(string s) {
	//Manacher算法
	if (s.size() == 0 || s.size() == 1)
		return s;
	//现将s变为长度为奇数的串
	string news = "&#";
	for (int i = 0; i<s.size(); i++)
	{
		news += s[i];
		news += '#';
	}
	news += '\0';
	int len = news.size();   //新串的长度
	int maxlen = -1;  //记录最长回文子串的长度
	int maxid = 0; //记录最长回文子串的中心
	vector<int> p(len);  //p[i]记录以i为中心的最长回文子串的半径，则maxlen = p[i] - 1
	int id = 0; //当前确定回文中心
	int mx = 0;  //当前回文中心能到达的右边界下标
	for (int i = 1; i<len; i++)
	{
		if (i < mx)  //i在当前的回文子串中，确定以i为中心的构成的最长的回文半径
			p[i] = min(mx - i, p[2 * id - i]);  //i关于id的对称下标为2*id-1，p[2*id-1]的最长半径已经确定，根据对称，p[i]应该取较小的一个
		else
			p[i] = 1;  //以他本身为回文子串
		while (news[i - p[i]] == news[i + p[i]])  //确定以i为中心的最长回文半径
			p[i]++;
		if (i + p[i] > mx)  //超出了mx的范围，应该更新mx和对称中心
		{
			id = i;
			mx = i + p[i];
		}
		if (maxlen < p[i] - 1)
		{
			maxlen = p[i] - 1;
			maxid = i;
		}
	}
	string result = "";
	for (int i = maxid - maxlen; i <= maxid + maxlen; i++)
		if (news[i] != '#')
			result += news[i];
	return result;
}

int main(){
	string str;
	cin >> str;
	cout << longestPalindrome(str) << endl;
	system("pause");
	return 0;
}