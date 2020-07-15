/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.80%)
 * Likes:    3016
 * Dislikes: 74
 * Total Accepted:    616.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
 vector<vector<int>> levelOrder(TreeNode* root) { 
    vector<vector<int>> ret;
    if (root == nullptr) return ret;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      int size = q.size();
      ret.push_back(vector<int> ());
      for (int i = 0; i < size; ++i) {
        TreeNode *node = q.front();
        q.pop();
        ret.back().push_back(node->val);
        if(node->left) { q.push(node->left); }
        if (node->right) { q.push(node->right); }
      }
    }
    return ret;
 }
};
// @lc code=end

