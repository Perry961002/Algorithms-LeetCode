class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        //对于非末尾行：
        //1.如果只有一个单词，那么就在后面把空格补齐
        //2.如果有多个单词，求出需要额外的空格
        //对于末尾行，每个单词间放一个间隔，额外空格全部放在末尾
        int wsize = words.size(); //单词表的长度
        int wlen = 0; //一行中单词的长度
        int idx = 0;  //单词的下标
        int start = 0; //一行中首单词的下标
        vector<string> result;
        while(idx < wsize)
        {
            if(wlen + words[idx].size() + idx - start <= maxWidth)  //找到每行最多放置的单词数
            {
                wlen += words[idx].size();
                idx ++;
            }
            else
            {
                string row = "";  //每行的句子
                int spacecnt = (idx - start > 1)? idx - start -1 : 1;  //间隙的个数
                int spacelen = (maxWidth - wlen) / spacecnt;  //单词之间空格的个数
                //开始放单词
                for(int i =0;i<idx-start;i++)
                {
                    row += words[start + i];
                    if(idx - start != 1 && i == idx - start - 1)
                        break;
                    if(i < maxWidth - wlen - spacecnt * spacelen)  //看有没有需要额外的空格
                        row += string(spacelen + 1, ' ');
                    else
                        row += string(spacelen,' ');
                }
                result.push_back(row);
                //为下一行初始化
                wlen = 0;
                start = idx;
            }
        }
        //开始最后一行
        string row = "";
        for(int i = start;i<idx;i++)
        {
            row += words[i];
            if(i == idx - 1)
                break;
            row += " ";
        }
        row += string(maxWidth - wlen - (idx - start - 1), ' ');
        result.push_back(row);
        return result;
    }
};