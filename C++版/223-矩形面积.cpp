static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int p = (C-A)*(D-B);
        int q = (G-E)*(H-F);
        if(G<=A || E>=C || H<=B || F>=D) //不重叠
            return p + q;
        else
        {
            int all = (min(C,G)-max(E,A) ) * (min(D,H)-max(B,F) );//重叠部分
            return p + q - all;
        }
    }
};