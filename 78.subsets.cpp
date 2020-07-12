/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (58.75%)
 * Likes:    3818
 * Dislikes: 83
 * Total Accepted:    584.6K
 * Total Submissions: 953.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
 vector<vector<int>> subsets(vector<int>& nums) { 
    vector<vector<int>> ret(1);
    for (int i = 0; i < nums.size();++i) {
      int n = ret.size();
      for (int j = 0; j < n;++j) {
        ret.push_back(ret[j]);
        ret.back().push_back(nums[i]);
      }
    }
    return ret;
 }
};
// @lc code=end

