/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.92%)
 * Likes:    3659
 * Dislikes: 86
 * Total Accepted:    604.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Follow up: Solve it both recursively and iteratively.
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
 bool isSymmetric(TreeNode* root) {
   if (root == NULL) return true;
   return isMirror(root->left, root->right);
 }
 bool isMirror(TreeNode* t1, TreeNode* t2) {
   if (t1 == NULL && t2 == NULL) return true;
   if (t1 == NULL || t2 == NULL) return false;
   return (t1->val == t2->val) && isMirror(t1->left, t2->right) &&
          isMirror(t1->right, t2->left);
    }
};
// @lc code=end

/*
对称二叉树：（如果同时满足下面的条件，两个树互为镜像）
1）它们的两个根节点具有相同的值
2）每个树的右子树都与另一个树的左子树镜像对称
可以用递归函数来判断是不是对称二叉树
*/