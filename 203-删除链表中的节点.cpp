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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newnode = new ListNode(-1);
        newnode->next = head;//保存头节点
        ListNode* front = newnode;//前驱节点
        ListNode* node = head;
        while(node != NULL)
        {
            if(node->val == val)
            {
                node = node->next;
                front->next = node;
            }
            else
            {
                front = node;
                node = node->next;
            }
        }
        return newnode->next;
    }
};