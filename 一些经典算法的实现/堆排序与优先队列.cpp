#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//返回左子节点下标
int Left(int i){
	return 2 * i + 1;
}

//返回右子节点下标
int Right(int i){
	return 2 * (i + 1);
}

//维护一个以root为根的,末尾下标为len大根堆
void MaxHeapify(vector<int>& heap, int root, int len){
	int left = Left(root);
	int right = Right(root);
	int largest;//保存左右子树中的最大值
	//先比较左子树
	if (left <= len && heap[left] > heap[root])
		largest = left;
	else
		largest = root;
	//比较右子树
	if (right <= len && heap[right] > heap[largest])
		largest = right;
	//子节点中有更大的数
	if (largest != root){
		swap(heap[root], heap[largest]);
		//交换之后可能破坏子树的大根堆性质,递归下去维护
		MaxHeapify(heap, largest, len);
	}
}

//自底向上建大根堆
void BuildMaxHeap(vector<int>& heap){
	//最后一个叶节点的双亲节点
	int lastParent = heap.size() / 2 - 1;
	for (int i = lastParent; i >= 0; i--){
		MaxHeapify(heap, i, heap.size()-1);
	}
}

//堆排序
void HeapSort(vector<int>& heap){
	//建大根堆
	BuildMaxHeap(heap);
	//每次将堆顶和末尾元素交换
	for (int i = heap.size() - 1; i >= 1; i--){
		swap(heap[0], heap[i]);
		//因为堆顶和末尾交换了,维护这个堆
		MaxHeapify(heap, 0, i - 1);
	}
}

//返回优先队列的队头元素
int getFront(vector<int>& Q){
	if (Q.empty())
		return INT_MIN;
	else
		return Q[0];
}

//删除队头元素
void popMax(vector<int>& Q){
	if (Q.empty())
		cout << "队空,不能删除" << endl;
	else{
		swap(Q[0], Q.back());
		Q.pop_back();
		MaxHeapify(Q, 0, Q.size() - 1);
	}
}

//将下标index节点的值变成k
void Update(vector<int>& Q, int index, int k){
	if (k >= Q[index]){
		Q[index] = k;
		//向上维护堆
		while (index > 0 && Q[(index - 1)/ 2] < Q[index]){
			swap(Q[(index - 1) / 2], Q[index]);
			index = (index - 1) / 2;
		}
	}
}

//向队列插入节点
void Insert(vector<int>& Q, int k){
	Q.push_back(INT_MIN);
	Update(Q, Q.size()-1, k);
}

int main(){
	int select;
	cout << "模拟堆排序选择0, 模拟优先队列选1,请选择：" << endl;
	cin >> select;
	if (select == 0){
		vector<int> nums;
		cout << "排序前：";
		for (int i = 0; i < 100; i++){
			nums.push_back(rand() % 100);
			cout << nums.back() << " ";
		}
		cout << endl << endl;
		HeapSort(nums);
		cout << "堆排序之后：";
		for (int i = 0; i < 100; i++)
			cout << nums[i] << " ";
		cout << endl << endl;
	}
	else{
		vector<int> nums;
		cout << "需要加入优先队列的数：";
		for (int i = 0; i < 10; i++){
			nums.push_back(rand() % 15);
			cout << nums.back() << " ";
		}
		cout << endl;
		BuildMaxHeap(nums);
		cout << "队内元素为：" << endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		char c;
		cout << "需要删除队头元素吗？y/n：";
		cin >> c;
		if (c == 'y')
			popMax(nums);
		int insert;
		cout << "输入你要插入的数：";
		cin >> insert;
		Insert(nums, insert);
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
	}
	system("pause");
}