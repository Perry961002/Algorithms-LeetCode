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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        //找到A和B其中一个先结束的地方
        while(pA != nullptr && pB != nullptr){
            pA = pA->next;
            pB = pB->next;
        }
        //将较长的链表的头节点定位到剩余长度能和另一个相等的地方
        while(pA != nullptr){
            headA = headA->next;
            pA = pA->next;
        }
        while(pB != nullptr){
            headB = headB->next;
            pB = pB->next;
        }
        while(headA != nullptr && headB != nullptr){
            if(headA == headB)
                return headA;
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};