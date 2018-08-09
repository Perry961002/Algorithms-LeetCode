/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    //有关环链表的证明在PDF文件中，这里就不写了
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                fast = head;
                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};