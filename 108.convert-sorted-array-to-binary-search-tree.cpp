/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (55.89%)
 * Likes:    2147
 * Dislikes: 197
 * Total Accepted:    384.4K
 * Total Submissions: 679.1K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 TreeNode* CreateBST(int left, int right, vector<int>& nums) {
   if (left > right) return NULL;

   // always choose left middle node as a root
   int mid_idx = (left + right) / 2;

   // inorder traversal: left->node->right
   TreeNode* root = new TreeNode(nums[mid_idx]);
   root->left = CreateBST(left, mid_idx - 1, nums);
   root->right = CreateBST(mid_idx + 1, right, nums);
   return root;
 }

 TreeNode* sortedArrayToBST(vector<int>& nums) {
   return CreateBST(0, nums.size() - 1, nums);
 }
 
};
// @lc code=end

