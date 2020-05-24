/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (50.53%)
 * Likes:    1187
 * Dislikes: 203
 * Total Accepted:    299.3K
 * Total Submissions: 586.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
    int depth(TreeNode* root) {
      if (!root) return 0;
      return 1 + std::max(depth(root->left), depth(root->right));
    }
    void LevelOrder(vector<vector<int>>& ans, TreeNode* node, int level) {
      if (!node) return;
      ans[level].push_back(node->val);
      LevelOrder(ans, node->left, level - 1);
      LevelOrder(ans, node->right, level - 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //1. 计算最后输出数组中有多少个元素
        int d = depth(root);
        //2. 创建结果数组用于step3函数
        vector<vector<int>> ans(d, vector<int>{});
        //3. 获取每层结点值  vector中d个元素，d-1是最后一个索引(每一层来看)
        LevelOrder(ans, root, d-1);

        return ans;
    }
};
// @lc code=end

