class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;//公牛，奶牛数
        //统计两个字符串中不满足公牛条件的数
        vector<int> Bulls(10,0);
        vector<int> Cows(10,0);
        int len = secret.size();
        if(len == 0)
            return "0A0B";
        for(int i=0;i<len;i++)
        {
            char s1 = secret[i], s2 = guess[i];
            if(s1 == s2)  //公牛条件
                bulls ++;
            else
            {
                Bulls[s1-'0'] ++;
                Cows[s2-'0'] ++;
            }
        }
        //都出现了，但位置不对
        for(int i=0;i<Bulls.size();i++)
            cows += min(Bulls[i], Cows[i]);
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};