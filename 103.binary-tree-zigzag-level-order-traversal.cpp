/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.77%)
 * Likes:    2037
 * Dislikes: 100
 * Total Accepted:    358.7K
 * Total Submissions: 762.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> ret;
      if (root == nullptr) return ret;
      queue<TreeNode*> q;
      q.push(root);
      int level = 0;
      while (!q.empty()) {
        ret.push_back(vector<int>());
        int cur_size = q.size();
        for (int i = 0; i < cur_size;++i) {
            auto node = q.front();
            q.pop();
            ret.back().push_back(node->val);
            if(node->left) {
              q.push(node->left);
            }
            if(node->right) {
              q.push(node->right);
            }
        }
        if(level%2!=0) {
          reverse(ret.back().begin(), ret.back().end());
        }
        level++;
      }
      return ret;
    }
};
// @lc code=end

