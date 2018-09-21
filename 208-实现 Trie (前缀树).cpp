//Trie树的性质：
//根节点不包含字符，除根节点外每一个节点都只包含一个字符
//从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串
//每个节点的所有子节点包含的字符都不相同
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;//以<节点字符, 孩子节点>建立hash表
    bool isEnd;//标志一条路径是否结束
    TrieNode(){
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;//根节点
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word)
        {
            if(node->children.find(c) == node->children.end())//c字符不存在,插入一个
                node->children[c] = new TrieNode();
            node = node->children[c];//向下insert
        }
        node->isEnd = true;//插入结束
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word)
        {
            if(node->children.find(c) == node->children.end())//c字符不存在,返回false
                return false;
            node = node->children[c];//c存在,向下search
        }
        if(node->isEnd)//word所有的字符都存在,并且路径结束
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix)
        {
            if(node->children.find(c) == node->children.end())//c字符不存在,返回false
                return false;
            node = node->children[c];//c存在,向下search
        }
        return true;//前缀都找到
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */