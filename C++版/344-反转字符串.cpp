class Solution {
public:
    string reverseString(string s) {
        //首位交换两字符
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i], s[j]);
            i ++;
            j --;
        }
        return s;
    }
};