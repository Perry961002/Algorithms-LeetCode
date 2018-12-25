class Solution {
    String longestPalindrome(String s) {
        //Manacher算法
        if(s.length() == 0 || s.length() == 1)
            return s;
        //现将s变为长度为奇数的串
        String news = "&#";
        for(int i=0;i<s.length();i++)
        {
            news += s.charAt(i);
            news += '#';
        }
        news += '\0';
        int len = news.length();   //新串的长度
        int maxlen = -1;  //记录最长回文子串的长度
        int maxid = 0; //记录最长回文子串的中心
        int[] p = new int[len];  //p[i]记录以i为中心的最长回文子串的半径，则maxlen = p[i] - 1
        int id = 0; //当前确定回文中心
        int mx = 0;  //当前回文中心能到达的右边界下标
        for(int i=1;i<len;i++)
        {
            if(i < mx)  //i在当前的回文子串中，确定以i为中心的构成的最长的回文半径
                p[i] = Math.min(mx - i, p[2 * id -i]);  //i关于id的对称下标为2*id-1，p[2*id-1]的最长半径已经确定，根据对称，p[i]应该取较小的一个
            else
                p[i] = 1;  //以他本身为回文子串
            while(news.charAt(i - p[i]) == news.charAt(i + p[i]))  //确定以i为中心的最长回文半径
                p[i]++;
            if(i + p[i] > mx)  //超出了mx的范围，应该更新mx和对称中心
            {
                id = i;
                mx = i + p[i];
            }
            if(maxlen < p[i] - 1)
            {
                maxlen = p[i] - 1;
                maxid = i;
            }
        }  
        String result = "";
        for(int i = maxid - maxlen;i<=maxid + maxlen;i++)
            if(news.charAt(i) != '#')
                result += news.charAt(i);
        return result;
    }
}