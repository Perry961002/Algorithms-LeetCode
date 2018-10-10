/*
*get(key):

　　hash命中节点node，把node从list中移动到表头，否则返回-1

*put(key, value):

　　hash命中node，只需更新hash中的node，并把node从list中移动到表头。

　　hash不命中, 如果cache满，需要替换cache中的node，并删除list的表尾元素，cache未满，将node插入表头，更新cache。
*/
struct CacheNode
 {
    int key;   //秘钥
    int value;  //数据值
    CacheNode(int k, int v):key(k), value(v){}   //构造函数
 };
class LRUCache {
public:
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) //不存在
            return -1;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);   //存在，移动到前端
        cacheMap[key] = cacheList.begin();   //修改hash表中的值
        return cacheMap[key]->value;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) == cacheMap.end()) //找不到
         {
            CacheNode cacheItem(key, value);
            if (cacheMap.size() == cacheSize) //空间已满
            {
                cacheMap.erase(cacheList.back().key);  //删除hash表中双链表的表尾值
                cacheList.pop_back();   //删除表尾元素，就是最近最久未使用的
            }
            cacheList.push_front(cacheItem);  //双链表中加入值
            cacheMap[key] = cacheList.begin(); //更新hash表
        }
        else    //找到了
        {
            cacheMap[key]->value = value;   //更新数据值
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);   //移到表头
            cacheMap[key] = cacheList.begin();  //更新hash表中的值
        }
    }
private:
    int cacheSize;   //空间大小
    unordered_map<int, list<CacheNode>::iterator> cacheMap;      //hash表，存储双链表和key
    list<CacheNode> cacheList;    //双链表
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */