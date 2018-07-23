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
    ListNode* insertionSortList(ListNode* head) {
        //插入排序就是每一步都将一个待排数据按其大小插入到已经排序的数据中的适当位置，直到全部插入完毕
        ListNode* result = new ListNode(0);  //结果链表
        while(head !=NULL)
        {
            ListNode* temp = head->next;  //保存头结点
            ListNode* p = result;
            while(p->next !=NULL && p->next->val < head->val)  //在result找到插入的位置
                p = p->next;
            //已经找的位置，开始插入
            head->next = p->next;   //把result中比p大的节点接到head之后
            p->next = head;
            head = temp;  //从下一个开始
        }
        return result->next;
    }
};