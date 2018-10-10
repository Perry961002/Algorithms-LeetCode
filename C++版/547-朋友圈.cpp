
class Solution {
public:
    void findCircle(vector<vector<int>>& M, vector<bool>& visit, int stu){
        visit[stu] = true;//已访问
        for(int i=0;i<M.size();i++){
            //找到没有访问的stu的朋友,继续深搜下去
            if(visit[i] == false && M[stu][i] == 1){
                findCircle(M, visit, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visit(M.size(), false);
        int result = 0;
        //找到所有的朋友圈
        for(int i=0;i<M.size();i++){
            if(visit[i] == false){
                findCircle(M, visit, i);
                result ++;
            }
        }
        return result;
    }
};