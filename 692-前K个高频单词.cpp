struct cmp {
    //重载<运算符
    bool operator()(const pair<string, int> p1, const pair<string, int> p2){
        //单词出现频率由高到低排序,如果不同的单词有相同出现频率，按字母顺序排序
        if(p1.second != p2.second){
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;//记录<单词, 次数>
        //统计次数
        for(auto w : words){
            hash[w]++;
        }
        //建优先队列,参数为数据类型, 底层实现, 重载比较函数
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> heap;
        for(auto w : hash){
            //维护一个大小为k的大根堆
            if(heap.size() < k){
                heap.push(make_pair(w.first, w.second));
            }
            else{
                //比堆顶元素次数多,或者次数一样但是比堆顶的字典序小
                if(w.second > heap.top().second || (w.second == heap.top().second && w.first < heap.top().first)){
                    heap.pop();
                    heap.push(make_pair(w.first, w.second));
                }
            }
        }
        vector<string> res;
        while(!heap.empty()){
            res.push_back(heap.top().first);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};