class RandomizedCollection {
private:
    unordered_map<int, vector<int>> hash;//记录<数字, 下标集合>,因为插入,查找的效率为O(1)
    vector<pair<int, int> > nums;//因为要随机返回数,记录<数字,在hash的集合的下标>
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = (hash.count(val) == 0)? true : false;
        //插入hash表和数组
        hash[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, hash[val].size() - 1));
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        //没有这个数
        if(hash.count(val) == 0)
            return false;
        else{
            auto last = nums.back();//数组的末尾
            //将末尾的数放到原来val的位置上,注意把hash表中末尾数的下标集合更新,然后删了数组末尾
            hash[last.first][last.second] = hash[val].back();
            nums[hash[val].back()] = last;
            hash[val].pop_back();
            
            //val的下标集合为空了,就删了这个节点
            if(hash[val].empty())
                hash.erase(val);
            
            nums.pop_back();//把数组末尾删了
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */