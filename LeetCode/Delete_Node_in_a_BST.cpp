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
    // 주어진 키에 해당하는 노드를 삭제하는 함수
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root; // 트리가 비어있는 경우

        if (key < root->val) {
            // 왼쪽 서브트리에서 삭제 진행
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // 오른쪽 서브트리에서 삭제 진행
            root->right = deleteNode(root->right, key);
        } else {
            // 삭제할 노드를 찾은 경우
            if (!root->left) {
                // 왼쪽 자식이 없는 경우
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            } else if (!root->right) {
                // 오른쪽 자식이 없는 경우
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            } else {
                // 두 자식을 모두 가진 경우
                // 오른쪽 서브트리에서 최소값 노드를 찾음
                TreeNode* minNode = getMinNode(root->right);
                root->val = minNode->val; // 현재 노드의 값을 최소값으로 대체
                root->right = deleteNode(root->right, minNode->val); // 최소값 노드를 삭제
            }
        }
        return root;
    }

private:
    // 가장 작은 값을 가진 노드를 찾는 함수
    TreeNode* getMinNode(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
