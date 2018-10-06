static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int countSubstrings(string s) {
        //Manacher算法
        if(s.size() < 2)
            return s.size();
        int res = 0;
        string t = "$#";
        //做添补
        for(char c : s){
            t += c;
            t += '#';
        }
        t += '\0';
        int len = t.size();
        //p[i]表示以t[i]为中心的最长回文串的半径,则能形成的回文子串的个数为p[i] / 2
        vector<int> p(len);
        int id = 0;//之前确定的回文中心
        int maxR = 0;//回文中心能到达的右边界下标
        for(int i=1;i<len;i++){
            //确定以i为中心的并且在包含在maxR之间的最长回文半径
            if(i < maxR)
                p[i] = min(maxR - i, p[2 * id - i]);//2 * id - i是i关于id的对称点
            else
                p[i] = 1;
            while(t[i - p[i]] == t[i + p[i]])//确定以i为中心的真正最长回文半径
                p[i]++;
            //更新id和maxR
            if(maxR < i + p[i]){
                id = i;
                maxR = i + p[i];
            }
            res += p[i] / 2;
        }
        return res;
    }
};