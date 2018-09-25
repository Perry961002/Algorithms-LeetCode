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
    /*翻转链表*/
    ListNode* reverseList(ListNode* root){
        ListNode* pre = NULL;
        ListNode* nextNode = NULL;
        while(root != NULL){
            nextNode = root->next;//保存下一个节点
            //逆序添加节点
            root->next = pre;
            pre = root;
            root = nextNode;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        //空链表, 或者只有一个节点
        if(head == NULL || head->next == NULL)
            return true;
        //快慢指针
        ListNode* slow = head;
        ListNode* fast = head;
        //找中间节点
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        //反转后半部分链表
        slow->next = reverseList(slow->next);
        slow = slow->next;
        //比较是不是回文
        while(slow != NULL){
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};