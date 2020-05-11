/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (44.59%)
 * Likes:    1301
 * Dislikes: 100
 * Total Accepted:    435.8K
 * Total Submissions: 974.5K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* deleteDuplicates(ListNode* head) {
   if (NULL == head) return head;
   ListNode* current = head;  //用current指针操作链表，head返回链表
   while (current != NULL && current->next != NULL) {
     if (current->val == current->next->val) {
       ListNode* p = current->next;
       current->next = p->next;
       delete p;
       current->next = current->next->next;
     } else {
       current = current->next;
     }
    }
    return head;
 }
};
// @lc code=end

