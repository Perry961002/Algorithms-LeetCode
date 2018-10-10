class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        if(strs.size() == 1)
            return strs[0];
        string str = "";
        for(int i=0;i<strs[0].size();i++){
            for(int j=0;j<strs.size();j++){
                if(strs[0][i] != strs[j][i])
                    return str;
            }
            str += strs[0][i];
        }
        return str;
    }
};