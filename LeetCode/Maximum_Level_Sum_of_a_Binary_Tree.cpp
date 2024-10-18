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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        int currentLevel = 0;
        int maxSum = INT_MIN;
        int maxLevel = 0;

        q.push(root);

        while (!q.empty()){
            int n = q.size();
            currentLevel++;
            int currentSum = 0;

            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();
                
                currentSum += node->val;

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            if (maxSum < currentSum) {
                maxSum = currentSum;
                maxLevel = currentLevel;
            }
        }

        return maxLevel;
    }
};
