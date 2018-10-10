class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        //第一次遍历是为了找它后面比它大的元素
        for(int i=0;i<n;i++){
            //栈顶元素的第一个更大元素
            while(!s.empty() && nums[s.top()] < nums[i]){
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        //第一趟结束之后栈中都是递减元素，第二次遍历是为了找前面比他大的元素
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                res[s.top()] = nums[i];
                s.pop();
            }
        }
        return res;
    }
};