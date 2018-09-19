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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* temp = head->next;
        while(q && q->next) 
        {
            ListNode* r = q->next->next;
            q->next->next = temp;
            p->next = q->next;
            p = p->next;
            q->next = r;
            q = q->next;
        }
        return head;
    }
};