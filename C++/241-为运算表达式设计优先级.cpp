class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        //分治法：
        //从运算符的地方将输入字符串分成两部分，分别计算出之后，计算总的值
        vector<int> result;
        for(int i=0;i<input.size();i++)
        {
            if(input[i] < '0' || input[i] > '9')
            {
                char c = input[i];//取出计算符
                vector<int> left = diffWaysToCompute(input.substr(0, i));//算右边可以算出的值
                vector<int> right = diffWaysToCompute(input.substr(i + 1));//算左边可以算出的值
                //从left和right中各取出一个值计算总结果
                for(auto l : left)
                    for(auto r : right)
                    {
                        switch(c)
                        {
                            case '+' : result.push_back( l + r);
                                break;
                            case '-' : result.push_back( l - r);
                                break;
                            case '*' : result.push_back( l * r);
                                break;
                            default:
                                break;
                        }
                    }
            }
        }
        //字符串中没有运算符
        if(result.size() == 0)
        {
            result.push_back(atoi(input.c_str()));
        }
        return result;
    }
};