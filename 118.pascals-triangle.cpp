/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (50.72%)
 * Likes:    1300
 * Dislikes: 104
 * Total Accepted:    363.7K
 * Total Submissions: 708.1K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
 vector<vector<int>> generate(int numRows) {
   vector<int> line;
   vector<vector<int> > triangle;
   if(numRows==0) {
     return triangle;
   }
   line.push_back(1);
   triangle.push_back(line);
   if(numRows==1) {
     return triangle;
   }
   line.push_back(1);
   triangle.push_back(line);
   if(numRows==2) {
     return triangle;
   }
   for (int i = 2; i < numRows; ++i) {
     line.clear();
     vector<int> tmp = triangle[i-1];
     for (int j = 0; j < i + 1; ++j) {
       if (j == 0 || j == i) {
         line.push_back(1);
       } else {
         line.push_back(tmp[j-1]+tmp[j]);
       }
     }
     triangle.push_back(line);
   }
   return triangle;
 }
};
// @lc code=end

// 可以归类为动态规划，要基于前一行来构造每一行
// 要考虑特殊情况： numRows=0、1、2（2可以放到后面一起算）