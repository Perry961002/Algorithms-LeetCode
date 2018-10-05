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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* cur = p;
        //找到第m-1个节点
        for(int i=0;i<m-1;i++)
            cur = cur->next;
        //反转
        ListNode *pre, *front, *last;
        pre = cur;
        last = cur->next;
        for(int i=m;i<=n;i++){
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        return p->next;
    }
};