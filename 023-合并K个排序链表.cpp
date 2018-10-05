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
    //合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        while(lists.size() > 1){
            ListNode* l1 = lists.back();
            lists.pop_back();
            ListNode* l2 = lists.back();
            lists.pop_back();
            lists.push_back(mergeTwoLists(l1, l2));
        }
        return lists.back();
    }
};