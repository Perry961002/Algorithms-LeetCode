class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        //利用反证法可知每个图只有不超过2个最小高度树的根节点
        //如果有3个根节点，为a，b，c。看节点b，那么其他两个节点肯定在b的子树中，所以不论怎么分布发现b都不是最小高度树
        //发现矛盾
        //没有每次删除叶子节点，剩下的两个或一个节点就是根节点
        vector<int> leafSet;  
        unordered_map<int, set<int>> hashTable;  
        for (int i = 0; i < edges.size(); i++) 
        {  
            hashTable[edges[i].first].insert(edges[i].second);  
            hashTable[edges[i].second].insert(edges[i].first);  
        }  
        for (int i = 0; i < hashTable.size(); i++) 
        {  
            if (hashTable[i].size() == 1) 
            {  
                leafSet.push_back(i);  
            }  
        }  
        while (leafSet.size() > 2 || (leafSet.size() == 2 && *hashTable[leafSet[0]].begin() != leafSet[1])) 
        {  
            vector<int> newLeafSet;  
            for (int i = 0; i < leafSet.size(); i++) 
            {  
                hashTable[*hashTable[leafSet[i]].begin()].erase(leafSet[i]);  
                if (hashTable[*hashTable[leafSet[i]].begin()].size() == 1) 
                {  
                    newLeafSet.push_back(*hashTable[leafSet[i]].begin());  
                }  
                hashTable[leafSet[0]].clear();  
            }  
            leafSet = newLeafSet;  
        } 
        if (n == 1) 
        {  
            leafSet = {0};  
        }  
        return leafSet;  
    }
};