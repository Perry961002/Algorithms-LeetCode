class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() < 2)
            return courses.size();
        //按结束时间从早到晚排序
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<int> studyTime;//存放课程的上课时间
        int nowTime = 0;//选课的上课时间
        for(auto couse : courses){
            studyTime.push(couse[0]);
            nowTime += couse[0];
            //超时
            if(nowTime > couse[1]){
                nowTime -= studyTime.top();
                studyTime.pop();
            }
        }
        return studyTime.size();
    }
};