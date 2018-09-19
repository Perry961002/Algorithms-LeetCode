static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    //判断是不是回文串
    bool isPalin(string& str)
    {
        int i = 0, j = str.size() - 1;
        while(i < j)
        {
            if(str[i] != str[j])
                return false;
            i++;j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> hash;//记录字符串和他的位置
        for(int i=0;i<words.size();i++)
            hash[words[i]] = i;
        vector<vector<int>> result;
        for(int i=0;i<words.size();i++)
        {
            string str = words[i];
            reverse(str.begin(), str.end());//反转
            int len = str.size();
            //寻找能和str构成回文串的串
            for(int j = 0;j<=len;j++)
            {
                string left = str.substr(0,j);//取前j个字符
                string right = str.substr(j);//取后面的字符
                //可以按 left-源串的方式构成回文对，即left-right-left
                if(hash.count(left) && isPalin(right) && hash[left] != i)
                    result.push_back({hash[left], i});
                if(hash.count(right) && isPalin(left) && hash[right] != i && j > 0)//避免和前面重复，j>0
                    result.push_back({i, hash[right]});
            }
        }
        return result;
    }
};