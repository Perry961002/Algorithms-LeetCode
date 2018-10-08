class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(char c : word){
            if(c >= 'A' && c <= 'Z')
                count++;
        }
        //全部字母都是大写, 单词中所有字母都不是大写, 只有首字母大写
        if(count == word.size() || count == 0 || (count == 1 && word[0] >= 'A' && word[0] <= 'Z'))
            return true;
        else
            return false;
    }
};