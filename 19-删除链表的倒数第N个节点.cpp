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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( head == NULL)
            return head;
        ListNode *mylist = new ListNode(0); //构造头结点
        mylist->next = head;
        ListNode *p = mylist;
        ListNode *q = mylist;
        for(int i =0;i<n;i++)
            q = q->next;
        while( q->next !=NULL)
        {
            q = q->next;
            p = p->next;
        }
        q = p->next;
        p->next = p->next->next;
        free(q);
        return mylist->next;
    }
};