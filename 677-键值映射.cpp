/**
class MapSum {
private:
    struct Trie {
        bool isEnd;//结束标志,true表示结束
        int value;//isEnd == true时有效
        vector<Trie*> child;//子节点集
        Trie(){
            isEnd = false;
            value = 0;
            child = vector<Trie*>(26, nullptr);
        }
    };
    
    Trie* root;
    
    //深度搜索字典树
    //返回node的所以子树的值和
    int dfs(Trie* node){
        if(node == nullptr)
            return 0;
        int res = 0;
        if(node->isEnd)
            res += node->value;
        for(auto next : node->child)
            res += dfs(next);
        return res;
    }
public:
    /** Initialize your data structure here. 
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        Trie* node = root;
        for(auto c : key){
            int index = c - 'a';
            //创建新的节点
            if(node->child[index] == nullptr){
                node->child[index] = new Trie();
            }
            //继续在下一层插入
            node = node->child[index];
        }
        node->isEnd = true;//结束
        node->value = val;//赋值
    }
    
    int sum(string prefix) {
        Trie* node = root;
        //找到目标字符串结束的地方
        for(auto c : prefix){
            int index = c - 'a';
            //字典树中不存在这个字符串
            if(node->child[index] == nullptr){
                return 0;
            }
            else{
                node = node->child[index];
            }
        }
        return dfs(node);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

class MapSum {
    //以上解法采用字典树,但其实本题用hash表其实更快
private:
    unordered_map<string, int> hash;
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        hash[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for(auto str : hash){
            if(prefix == str.first.substr(0, prefix.size())){
                res += str.second;
            }
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */