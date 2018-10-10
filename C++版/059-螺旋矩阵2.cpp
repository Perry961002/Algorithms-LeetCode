class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0)return vector<vector<int> >();
        vector<vector<int> >result(n, vector<int>(n,0));
        int square = n * n;
        int num = 1;
        int x = 0, y = 0;
        while(num <= square)
        {
            while(y < n && result[x][y] == 0) 
            {
                result[x][y] = num;
                y++;
                num++;
            }
            y--;
            x++;
            while(x < n && result[x][y] == 0) 
            {
                result[x][y] = num;
                x++;
                num++;
            }
            x--;
            y--;
            while(y >= 0 && result[x][y] == 0) 
            {
                result[x][y] = num;
                y--;
                num++;
            }
            x--;
            y++;
            while(x >= 0 && result[x][y] == 0 ) 
            {
                result[x][y] = num;
                x--;
                num++;
            }
            x++;
            y++;
        }
        return result;
    }
};