/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (42.78%)
 * Likes:    2039
 * Dislikes: 156
 * Total Accepted:    430.2K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * Return false.
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
private:
 bool isBalancedTreeHelper(TreeNode* root, int& height) {
    if(!root) {
       height = -1;
       return true;
    }
    int left, right;
    if (isBalancedTreeHelper(root->left, left) && isBalancedTreeHelper(root->right, right) 
        && abs(left-right)<2) {
      height = max(left, right) + 1;  //height结果用于上一层递归
      return true;
    }else {
      return false;
    }
    }

public:
// 自底向上的递归 减少冗余
// 检查子树是否平衡。如果平衡，则使用它们的高度判断父节点是否平衡，并计算父节点的高度
 bool isBalanced(TreeNode* root) {
   int height;
   return isBalancedTreeHelper(root, height);
 }
 };
// @lc code=end

