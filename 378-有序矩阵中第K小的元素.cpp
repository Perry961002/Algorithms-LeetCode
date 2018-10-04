class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;//优先队列,默认是大根堆
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(pq.size() < k)
                    pq.push(matrix[i][j]);
                else{
                    //保证pq中的元素个数是k
                    if(pq.top() <= matrix[i][j])
                        break;
                    else{
                        pq.push(matrix[i][j]);
                        pq.pop();
                    }
                }
            }
        }
        return pq.top();
    }
};