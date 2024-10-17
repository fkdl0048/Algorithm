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
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val);
    }

private:
    int countGoodNodes(TreeNode* node, int maxSoFar) {
        if (node == nullptr) {
            return 0;
        }

        int goodNodeCount = (node->val >= maxSoFar) ? 1 : 0;

        maxSoFar = max(maxSoFar, node->val);

        goodNodeCount += countGoodNodes(node->left, maxSoFar);
        goodNodeCount += countGoodNodes(node->right, maxSoFar);

        return goodNodeCount;
    }
};
