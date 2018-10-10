class RandomizedSet {
private:
    unordered_map<int, int> hash;//记录<数字, 下标>,因为插入,查找的效率为O(1)
    vector<int> nums;//因为要随机返回数
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        //已经存在
        if(hash.count(val))
            return false;
        else{
            //插入hash表和数组
            hash[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        //没有这个数
        if(hash.count(val) == 0)
            return false;
        else{
            int index = hash[val];//取得val在数组中的下标
            //将这个数和数组末尾的数互换,把hash表中把原来末尾数的下标更改,然后删除末尾O(1)
            hash[nums.back()] = index;
            nums[index] = nums.back();
            nums.pop_back();
            hash.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */