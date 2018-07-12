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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        ListNode *p = head;
        while(p != NULL && p->next != NULL)
        {   //交换节点的值即可，不用交换节点
            int temp = p->val;
            p->val = p->next->val;
            p->next->val = temp;
            p = p->next->next;
        }
        return head;
    }
};