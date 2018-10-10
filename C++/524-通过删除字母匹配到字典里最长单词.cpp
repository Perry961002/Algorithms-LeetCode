class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string longest_str = "";
        for (auto t : d) {
            if (longest_str.size() > t.size() ||(longest_str.size() == t.size() && longest_str < t))
                continue;
            if (isValid(s, t)) 
                longest_str = t;
        }
        return longest_str;
    }

    bool isValid(const string &s1, const string &s2) 
    {
        int i = 0, j = 0; 
        while (i < s1.size() && j < s2.size()) 
            if (s1[i++] == s2[j]) 
                j++;
        return 
            j == s2.size();
    }
};