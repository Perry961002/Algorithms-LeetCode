/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode result = new ListNode(0);   //结果链表
		ListNode temp = result;
		int sum = 0;    //存放每一位相加之和
		while(l1 != null || l2 != null)    //走完两个链表截止
		{
			if(l1 != null)  //如果l1非空，加上这一位的值到中间结果
			{
				sum += l1.val;
				l1 = l1.next;
			}
			if(l2 != null)  //如果l2非空，加上这一位的值到中间结果
			{
				sum += l2.val;
				l2 = l2.next;
			}
			temp.next = new ListNode(sum % 10);
			sum /= 10;   //产生的进位
			temp = temp.next;
        
		}
		if(sum != 0)  //计算最终的进位
		{
			temp.next = new ListNode(sum);
		}
		return result.next;   //第一位是0，从下一位开始
	}
};