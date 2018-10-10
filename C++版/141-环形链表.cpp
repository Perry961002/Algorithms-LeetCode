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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;  //慢指针
        ListNode* fast = head;  //快指针
        while(slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;  //快指针走两步
            if(slow == fast)
                return true;
        }
        return false;
    }
};