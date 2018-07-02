class Solution {
public:
    void per(vector<int> nums,int start,vector<vector<int> > &result){  
        if(start==nums.size()-1){  
            result.push_back(nums);  
        }  
        else{  
            for(int i=start;i<nums.size();i++){  
                swap(nums[start],nums[i]);  
                per(nums,start+1,result);  
                swap(nums[start],nums[i]);  
            }  
        }  
    } 
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int> > result;  
        if(nums.size()==0)
        {   
            result.push_back(nums);  
            return result;  
        }  
        per(nums,0,result);  
        return result;  
    }
};