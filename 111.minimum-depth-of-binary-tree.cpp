/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (36.78%)
 * Likes:    1245
 * Dislikes: 655
 * Total Accepted:    398K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
       if(root == NULL) {
         return 0;
       }
       int left_mindepth = minDepth(root->left);
       int right_mindepth = minDepth(root->right);
       if(root->left==NULL || root->right==NULL) {
         return 1 + left_mindepth + right_mindepth;
       }
       return std::min(left_mindepth, right_mindepth) + 1;
    }
};
// 最小高度，要考虑到只有根节点和一个叶子节点（题中是到叶子节点的最小深度）---> 最小深度是2
// 时间复杂度O(N); 空间复杂度没看明白？？？
// 空间复杂度：最坏情况下，整棵树是非平衡的，例如每个节点都只有一个孩子，递归会调用 N（树的高度）次，因此栈的空间开销是 O(N) 。但在最好情况下，树是完全平衡的，高度只有log(N)，因此在这种情况下空间复杂度只有 O(\log(N))O(log(N)) 。

// @lc code=end
