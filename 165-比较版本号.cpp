class Solution {
public:
    //去除'.',将每位的数字存放在数组中
    vector<int> toNumArray(string str)
    {
        vector<int> vec;
        int cur = 0;
        int index; 
        string subStr;
        while((index = str.find('.',cur)) != -1)
        {
            subStr = str.substr(cur,index - cur);
            vec.push_back(atoi(subStr.c_str()));
            cur = index + 1;
        }
        subStr = str.substr(cur,str.size());
        vec.push_back(atoi(subStr.c_str()));
        return vec;
    }
    int compareVersion(string version1, string version2) {
        vector<int> vec1 = toNumArray(version1);
        vector<int> vec2 = toNumArray(version2);
        int len1 = vec1.size();
        int len2 = vec2.size();
        //补成长度相同的数组，特殊情况1.0.0.1和1.0
        while(len1 < len2)
        {
            vec1.push_back(0);
            len1 ++;
        }
        while(len2 < len1)
        {
            vec2.push_back(0);
            len2 ++;
        }
        for (int i = 0;i<len1;i++)
        {
            if(vec1[i] < vec2[i]) 
                return -1;
            else if(vec1[i] > vec2[i]) 
                return 1;
        }
        return 0;

    }
};