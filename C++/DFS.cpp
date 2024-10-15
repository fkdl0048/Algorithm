#include <iostream>

// 노드 구조체 정의
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

// 전위 순회 함수 정의
void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->value << " "; // 현재 노드 방문
    preOrderTraversal(root->left);   // 왼쪽 자식 방문
    preOrderTraversal(root->right);  // 오른쪽 자식 방문
}

// 노드 삽입 함수 정의
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode(value);
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 122);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 3);

    // 전위 순회를 통해 요소를 방문
    preOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}