//Trie树的节点定义和构造函数
class TrieNode {
public:
    bool isEnd;//结束标志
    TrieNode* children[26];//节点的孩子,因为只有小写字母,大小可定
    TrieNode():isEnd(false){
        memset(children, NULL, sizeof(children));//为孩子数组分配空间
    }
};
class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
         root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word)
        {
            if(node->children[c - 'a'] == NULL)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;//结束路径
    }
    
    //因为存在'.'，现在为search函数写深搜函数
    //参数分别为(单词, 字符在单词中的位置, 开始的前缀树节点)
    bool deepSearch(string word, int index, TrieNode* node)
    {
        //结束条件
        if(index == word.size())
            return node->isEnd;
        //非'.'字符，需要匹配
        if(word[index] != '.')
        {
            //没有匹配到
            if(node->children[word[index] - 'a'] == NULL)
                return false;
            //向下深搜
            else
                return deepSearch(word, index+1, node->children[word[index] - 'a']);
        }
        else
        {
            //遇到'.'了，node和word[i]匹配了,尝试从node的每个孩子开始继续搜索
            bool flag = false;
            for(int i =0;i<26;i++)
            {
                if(node->children[i] != NULL && deepSearch(word, index+1, node->children[i]))
                    flag = true;
            }
            return flag;
        }
        return true;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        //cout<<deepSearch(word, 0, root);
         return deepSearch(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */