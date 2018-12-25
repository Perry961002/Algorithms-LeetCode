class Solution {
    public int reverse(int x) {
        int result = 0;
        while(x != 0){
            int temp = result * 10 + x % 10;
            //出现溢出
            if(temp / 10 != result)
                return 0;
            result = temp;
            x /= 10;
        }
        return result;
    }
}