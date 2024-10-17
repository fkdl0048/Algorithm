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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Leaf;
        vector<int> root2Leaf;

        returnLeaf(root1, root1Leaf);
        returnLeaf(root2, root2Leaf);

        return root1Leaf == root2Leaf;
    }

private:
    void returnLeaf(TreeNode* node, vector<int>& v) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            v.push_back(node->val);
        }

        returnLeaf(node->left, v);
        returnLeaf(node->right, v);

        return;
    }
};
