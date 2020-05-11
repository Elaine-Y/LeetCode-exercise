/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.92%)
 * Likes:    7007
 * Dislikes: 319
 * Total Accepted:    923.3K
 * Total Submissions: 2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution {
public:
 int maxSubArray(vector<int>& nums) { 
    int n = nums.size();
    int sum_max = nums[0];
    for (int i = 1; i < n;++i) {
        if(nums[i-1]>0) {
          nums[i] += nums[i - 1];   //直接改变原数组的值，减小占用空间
        }
        sum_max = max(sum_max, nums[i]);
    }
    return sum_max;
 }
};
// @lc code=end

