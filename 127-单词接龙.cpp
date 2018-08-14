//构造结构体
struct wordnode{
    string word;  //单词
    int len; //到这个单词走的距离
    wordnode(string w, int l) : word(w), len(l){}
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //BFS
        unordered_set<string> book(wordList.begin(), wordList.end());//转换成set，有利于查找
        queue<wordnode*> que;
        unordered_map<string, bool> m;//存放访问过的节点
        //先期准备
        wordnode* begin = new wordnode(beginWord,1);
        que.push(begin);
        m[beginWord] = true;
        //开始BFS
        while(!que.empty())
        {
            wordnode* front = que.front();
            que.pop();
            string frontword = front->word;
            //查找与frontword只有一个不同的单词
            for(int i = 0;i < frontword.size();i++)
            {
                for(char j = 'a';j<='z';j++)
                {
                    //找到不一样的字母
                    if(j == frontword[i])
                        continue;
                    string nextword = frontword;
                    nextword[i] = j;//替换成不一样的
                    //nextword存在，并且就是endWord，返回最短距离
                    if(book.find(nextword) != book.end() && nextword == endWord)
                        return front->len + 1;
                    //nextword存在，但没有访问过
                    if(book.find(nextword) != book.end() && m[nextword] == false)
                    {
                        wordnode* nextnode = new wordnode(nextword, front->len + 1);
                        que.push(nextnode);
                        m[nextword] = true;
                    }
                }
            }
        }
        return 0;
    }
};