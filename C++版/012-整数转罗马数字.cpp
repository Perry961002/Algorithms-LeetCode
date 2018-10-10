static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};        
    vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string result = "";
        for(int i=0;i<nums.size();i++)
        {
            while(num >= nums[i])
            {
                num -= nums[i];
                result += roman[i];
            }
        }
        return result;
    }
};