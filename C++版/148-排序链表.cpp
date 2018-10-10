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
    //使用快慢指针法找到链表的中点并断开
    ListNode* getMid(ListNode* head){
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        //保存中间节点
        fast = slow->next;
        //从中间断开
        slow->next = NULL;
        return fast;
    }
    
    //合并两个排序好的链表
    ListNode* mergeList(ListNode* h1, ListNode* h2){
        ListNode* newList = new ListNode(-1);
        ListNode* head = newList;
        while(h1 != NULL && h2 != NULL){
            if(h1->val < h2->val){
                head->next = h1;
                h1 = h1->next;
            }
            else{
                head->next = h2;
                h2 = h2->next;
            }
            head = head->next;
        }
        //将没有遍历完的链表接在后面
        if(h1 != NULL){
            head->next = h1;
            h1 = h1->next;
        }
        if(h2 != NULL){
            head->next = h2;
            h2 = h2->next;
        }
        return newList->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* back = getMid(head);
        //排序前后两个部分
        head = sortList(head);
        back = sortList(back);
        //合并
        head = mergeList(head, back);
        return head;
    }
};