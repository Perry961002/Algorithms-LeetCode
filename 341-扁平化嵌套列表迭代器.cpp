/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    //用栈装迭代器,begins装第一个元素的迭代器, ends装末尾元素的下一个位置的迭代器
    stack<vector<NestedInteger> :: iterator> begins, ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        //返回begins的栈顶包含的单个整数
        return (begins.top() ++)->getInteger();
    }

    bool hasNext() {
        while(!begins.empty()){
            //nestedList的两端的迭代器相等,说明nestedList为空
            if(begins.top() == ends.top()){
                begins.pop();
                ends.pop();
            }
            else{
                auto now = begins.top();
                //元素是整数
                if(now->isInteger())
                    return true;
                else{
                    //是列表,应该取出表中整数的迭代器
                    begins.top()++;
                    begins.push(now->getList().begin());
                    ends.push(now->getList().end());
                }
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */