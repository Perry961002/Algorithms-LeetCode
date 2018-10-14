#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//对数组进行原址重排,选出一个数作为基准,前半部分都小于等于他,后半部分 大于他.最后返回基准的下标
int Partition(vector<int>& nums, int left, int right){
	int mid = nums[right];
	int i = left - 1;
	for (int j = left; j < right; j++){
		//找到小于等于mid的数
		if (nums[j] <= mid){
			i++;
			//把小于等于mid的数都在前面
			swap(nums[i], nums[j]);
		}
	}
	//把基准值放在前半部分之后
	swap(nums[i+1], nums[right]);
	return i + 1;
}

//递归实现快速排序
void QuickSort1(vector<int>& nums, int left, int right){
	if (left < right){
		int mid = Partition(nums, left, right);
		//递归前半部分
		QuickSort1(nums, left, mid-1);
		//递归后半部分
		QuickSort1(nums, mid+1, right);
	}
}

//非递归实现
void QuickSort2(vector<int>& nums, int left, int right){
	if (left < right){
		stack<int> s;
		s.push(left);
		s.push(right);
		while (!s.empty()){
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();
			int mid = Partition(nums, l, r);
			//前半部分
			if (l < mid - 1){
				s.push(l);
				s.push(mid-1);
			}
			//后半部分
			if (r > mid + 1){
				s.push(mid+1);
				s.push(r);
			}
		}
	}
}

int main(){
	vector<int> nums1, nums2;
	cout << "原数组：" << endl;
	for (int i = 0; i < 200; i++){
		int num = rand() % 200;
		cout << num << " ";
		nums1.push_back(num);
		nums2.push_back(num);
	}
	cout << endl;
	cout << "递归实现：" << endl;
	QuickSort1(nums1, 0, nums1.size()-1);
	for (int i = 0; i < 200; i++)
		cout << nums1[i] << " ";
	cout << endl;
	cout << "非递归实现：" << endl;
	QuickSort2(nums2, 0, nums2.size() - 1);
	for (int i = 0; i < 200; i++)
		cout << nums2[i] << " ";
	cout << endl;
	while (1);
	return 0;
}