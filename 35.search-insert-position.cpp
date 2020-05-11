/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.55%)
 * Likes:    1950
 * Dislikes: 231
 * Total Accepted:    547.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
        if(size == 0) {
            return 0;
        }
        // 特别判断
        if(nums[size-1] < target) {
            return size;
        }
        int left = 0; 
        int right = size-1;
        while(left <= right) {
            int mid = (right+left)/2;
            // 严格小于target的元素一定不是解
            if(nums[mid] < target) {
                // 下一轮搜索区间是 [mid+1, right]
                left = mid + 1;
            } else {
                right = mid-1;
            }
        }
        return left;
    }
};
// @lc code=end
