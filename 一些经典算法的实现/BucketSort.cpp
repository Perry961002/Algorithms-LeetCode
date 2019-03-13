#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

/**
 * 打印nums里的数字
*/
void display(const vector<int> nums){
    if(nums.empty())
        return ;
    for(int val : nums)
        cout << val << " ";
    cout << endl;
}

/**
 * 输入3个整数min, max, n
 * 返回n个均匀分布在[min, max]里的数
 * 使用标准库里的uniform_int_distribution
*/
vector<int> initVector(const int min, const int max, const int n){
    vector<int> nums;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> u(min, max);
    for(int i = 0; i < n; ++i)
        nums.push_back(u(gen));
    return nums;
}

/**
 * 输入整型向量A
 * 将A进行原址的桶排序
*/
void BucketSort(vector<int>& A){
    if(A.size() < 2)
        return ;
    
    //找到min和max，确定桶的个数
    int min = A[0], max = A[0];
    for(int val : A){
        if(val < min)
            min = val;
        if(val > max)
            max = val;
    }
    int bucketNum = max - min + 1;

    //桶的间距为1，保证相同的桶里数都是一样的
    vector<vector<int>> B(bucketNum, vector<int> ());
    
    //把数放入桶中
    for(int val : A){
        B[val - min].push_back(val);
    }

    //依次从桶中取出数，并放入A中
    int index = 0;
    for(auto iter = B.begin(); iter != B.end(); ++ iter){
        //取非空桶中的数字
        if(!(*iter).empty()){
            for(int val : (*iter))
                A[index++] = val;
        }
    }
}

int main() {
    int min, max, n;
    cout << "input 3 integers: min, max, n; Get n numbers evenly distributed in [min, max]:";
    cin >> min >> max >> n;
    vector<int> nums = initVector(min, max, n);
    display(nums);

    cout << "after BucketSort:" << endl;
    BucketSort(nums);
    display(nums);

    /**
     * input 3 integers: min, max, n; Get n numbers evenly distributed in [min, max]:-100 100 100
     * 12 45 -30 83 -99 19 75 3 92 96 -66 32 -37 6 40 58 -49 -86 15 -34 -33 17 -53 -94 -66 86 94 
     * -97 31 56 -4 -33 -87 -32 -98 -17 69 82 -44 30 84 14 70 -99 12 -43 78 46 -100 41 -48 -9 -33 
     * -56 87 75 -4 44 96 77 54 -33 41 34 -67 21 0 -87 30 54 33 66 71 -71 7 -100 -39 -1 -35 -81 
     * -17 39 12 25 39 51 15 -8 -36 56 99 51 17 96 -21 -65 -18 -10 -72 67
     * after BucketSort:
    * -100 -100 -99 -99 -98 -97 -94 -87 -87 -86 -81 -72 -71 -67 -66 -66 -65 -56 -53 -49 -48 -44 -43 
    * -39 -37 -36 -35 -34 -33 -33 -33 -33 -32 -30 -21 -18 -17 -17 -10 -9 -8 -4 -4 -1 0 3 6 7 12 12 
    * 12 14 15 15 17 17 19 21 25 30 30 31 32 33 34 39 39 40 41 41 44 45 46 51 51 54 54 56 56 58 66 
    * 67 69 70 71 75 75 77 78 82 83 84 86 87 92 94 96 96 96 99
    */
}