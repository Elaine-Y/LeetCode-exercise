/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (47.54%)
 * Likes:    749
 * Dislikes: 193
 * Total Accepted:    273.1K
 * Total Submissions: 567.6K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

// @lc code=start
class Solution {
public:
 vector<int> getRow(int rowIndex) { 
  vector<int> A(rowIndex+1,0);
  A[0] = 1;
  for (int i = 1; i < rowIndex + 1;i++) {  //利用前一行求后一行->第k行要遍历k次
    for (int j = i; j >= 1; j--) {  //每一行从最后一个位置开始往前更新A数组;每一行最后一个值的下标=行号(j=i)
      A[j] += A[j - 1];
    }
  }
  return A;
 }
}; // 时间复杂度O(k^2), 空间复杂度O(k)

// @lc code=end

