/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //返回链表的长度
    int getLen(ListNode* root){
        int len = 0;
        ListNode* p = root;
        while(p){
            len ++;
            p = p->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if(k == 1)
            return {root};
        vector<ListNode*> res;
        if(root == nullptr){
            while(k--){
                res.push_back(root);
            }
            return res;
        }
        int len = getLen(root);
        int aveLen = len / k;//k个链表的平均长度
        int front = len % k;//前front个链表的长度为aveLen + 1
        ListNode* p = root;
        if(aveLen == 0){
            //链表的长度为1或0
            while(p){
                ListNode* tmp = new ListNode(p->val);
                res.push_back(tmp);
                p = p->next;
                k --;
            }
            //用空链表补全
            while(k--){
                ListNode* tmp = nullptr;
                res.push_back(tmp);
            }
        }
        else{
            while(k > 0){
                //构造前面几个较长的子链表
                while(front > 0){
                    ListNode* tmproot = new ListNode(p->val);
                    ListNode* q = tmproot;
                    p = p->next;
                    for(int i=0;i<aveLen;i++){
                        ListNode* tmp = new ListNode(p->val);
                        q->next = tmp;
                        q = q->next;
                        p = p->next;
                    }
                    res.push_back(tmproot);
                    k--;
                    front --;
                }
                ListNode* tmproot = new ListNode(p->val);
                ListNode* q = tmproot;
                p = p->next;
                for(int i=1;i<aveLen;i++){
                    ListNode* tmp = new ListNode(p->val);
                    q->next = tmp;
                    q = q->next;
                    p = p->next;
                }
                res.push_back(tmproot);
                k--;
            }
        }
        return res;
    }
};