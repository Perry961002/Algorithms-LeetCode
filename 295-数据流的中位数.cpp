class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> front;//以大根堆存放前半部分的数
    priority_queue<int, vector<int>, greater<int>> back;//以小根堆存放后半部分的数
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        front.push(num);
        int frontMax = front.top();//前半部分的最大值
        front.pop();//弹出
        back.push(frontMax);
        //调整两个堆的大小,因为一开始插入之后back会越来越大而front不变
        //这样保证两个堆大小的差不会超过1
        if(back.size() > front.size()){
            int backMin = back.top();
            back.pop();
            front.push(backMin);
        }
    }
    
    double findMedian() {
        //中间元素在前半部分
        if(front.size() > back.size())
            return front.top() * 1.0;
        else if(front.size() < back.size())//后半部分
            return back.top() * 1.0;
        else
            return (front.top() + back.top()) / 2.0;//中间两个数的平均数
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */