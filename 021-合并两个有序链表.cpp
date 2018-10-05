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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode(-1);
        ListNode* head = newList;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            }
            else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        //将没有遍历完的链表接在后面
        if(l1 != NULL){
            head->next = l1;
            //l1 = l1->next;
        }
        if(l2 != NULL){
            head->next = l2;
            //l2 = l2->next;
        }
        return newList->next;
    }
};