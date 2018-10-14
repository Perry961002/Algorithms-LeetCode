#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<string>

using namespace std;

unordered_map<string, int> grade = { { "(", -1 }, { "+", 0 }, { "-", 0 }, { "*", 1 }, { "/", 1 } };//操作符优先级

vector<string> transform(string str) {
	vector<string> result;
	if (str.empty())
		return result;
	stack<string> oper;//存放操作符
	str = "(" + str + ")";
	int len = str.size();
	for (int i = 0; i < len; i++) {
		//取出数字
		if (isdigit(str[i])){
			string tmp;
			while (i < len && isdigit(str[i])){
				tmp += str[i];
				i++;
			}
			result.push_back(tmp);
			i--;
			continue;
		}
		//左括号入栈
		if (str[i] == '(')
			oper.push(string(1,str[i]));
		//遇到右括号,左括号之前的操作符都出栈,加入结果
		else if (str[i] == ')'){
			while (oper.top() != "("){
				result.push_back(oper.top());
				oper.pop();
			}
			oper.pop();//左括号出栈
		}
		//当前操作符的优先级高于栈顶元素
		else if (oper.empty() || grade[string(1, str[i])] > grade[oper.top()])
			oper.push(string(1, str[i]));
		//栈顶元素优先级高或者相同
		else{
			while (!oper.empty()){
				string tmpoper = oper.top();
				if (grade[tmpoper] >= grade[string(1, str[i])]){
					result.push_back(tmpoper);
					oper.pop();
				}
				else
					break;
			}
			oper.push(string(1, str[i]));//当前操作数入栈
		}
	}
	return result;
}
int main(){
	string str;
	cout << "输入表达式,中间不能出现空格：";
	cin >> str;
	vector<string> res = transform(str);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	while (1);
	return 0;
}