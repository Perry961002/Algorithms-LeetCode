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
    void deleteNode(ListNode* node) {
        //因为节点的值是唯一,并且参数直接给的是需要删除的节点
        //所以先把节点的值改为他后继节点的值,然后修改next指针指向后继的后继
        node->val = node->next->val;
        node->next = node->next->next;
    }
};