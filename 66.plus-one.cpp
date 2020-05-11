/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.00%)
 * Likes:    1331
 * Dislikes: 2164
 * Total Accepted:    550.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */

// @lc code=start
class Solution {
public:
 vector<int> plusOne(vector<int>& digits) { 
    int len = digits.size();
    for (int i = len - 1; i >= 0;--i) {
      digits[i]++;
      digits[i] %= 10;
      if(digits[i]!=0) {
        return digits;
      }
    }
    digits[0] = 1;
    digits.push_back(0);
    return digits;
 }
};
// @lc code=end
// 需要考虑三种情况 1）可以直接加  2）499->500  3) 999->10000

