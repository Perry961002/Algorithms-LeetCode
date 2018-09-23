/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto _ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //用stack依次装入数字，这样弹出的时候就是逆序了
        stack<int> nums1, nums2;
        while(l1 || l2)
        {
            if(l1)
            {
                nums1.push(l1->val);
                l1 = l1->next;
            }
            if(l2)
            {
                nums2.push(l2->val);
                l2 = l2->next;
            }
        }
        int sum = 0;
        ListNode* sumList = NULL;//最后的结果链表
        ListNode* nowSum;//单次计算时产生的节点
        while(!nums1.empty() || !nums2.empty())
        {
            //计算两个数各位上的和
            if(!nums1.empty())
            {
                sum += nums1.top();
                nums1.pop();
            }
            if(!nums2.empty())
            {
                sum += nums2.top();
                nums2.pop();
            }
            //加入链表,注意是顺序的
            nowSum = new ListNode(sum % 10);//各位上的数应该取余
            nowSum->next = sumList;
            sumList = nowSum;
            sum /= 10;//进位
        }
        if(sum != 0)
        {
            nowSum = new ListNode(1);//
            nowSum->next = sumList;
            sumList = nowSum;
        }
        return sumList;
    }
};