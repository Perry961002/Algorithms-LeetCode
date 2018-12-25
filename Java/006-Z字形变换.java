class Solution {
    String convert(String s, int numRows) {
        if(numRows == 1) return s;
        int len = s.length();   //长度
        String result = "";   //结果字符串
        for(int i=0;i<numRows;i++)   //逐行定位字符
        {
            int leftstep = 2 * numRows - 2 - 2 * i;  //每行两个字符的第一类间隔
            int rightstep = 2 * i;    //第二类间隔
            int index = i;   //字符的下标，每一行的第一个就是i
            while(index < len)   //不能超过字符串的长度
            {
                if(leftstep > 0)
                {
                    result += s.charAt(index); //装入跳第一类间隔前的一个字符
                    index += leftstep;
                }
                if(index < len)   //不能超过字符串的长度
                {
                    if(rightstep > 0)
                    {
                        result += s.charAt(index);   //装入跳第二类间隔前的一个字符
                        index += rightstep;
                    }
                }
            }
        }
        return result;
    }
}