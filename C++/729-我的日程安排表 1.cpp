class MyCalendar {
private:
    //记录时间出现的次数
    map<int, int> time;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //起始时间次数+1,结束时间次数-1,这样除了最开始的起点为1,其他时刻的次数<=0
        time[start]++;
        time[end]--;
        int sum = 0;//记录总次数
        //计算累计和
        for(auto t : time){
            sum += t.second;
            //如果没有交叉的,sum < 1
            if(sum > 1){
                //将这组计划删除
                time[start]--;
                time[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */