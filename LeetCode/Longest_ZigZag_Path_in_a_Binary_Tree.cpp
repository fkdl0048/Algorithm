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
    int longestZigZag(TreeNode* root) {
        int maxLength = 0;
        dfs(root, true, 0, maxLength);
        dfs(root, false, 0, maxLength);
        return maxLength;
    }

private:
    void dfs(TreeNode* node, bool isLeft, int currentLength , int& maxLength) {
        if (node == nullptr) {
            return;
        }

        maxLength = max(currentLength, maxLength);

        if (isLeft) {
            dfs(node->left, false, currentLength + 1, maxLength);
            dfs(node->right, true, 1, maxLength);
        }
        else {
            dfs(node->right, true, currentLength + 1, maxLength);
            dfs(node->left, false, 1, maxLength);
        }
    }
};
