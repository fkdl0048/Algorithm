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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        return countSum(root, targetSum) 
        + pathSum(root->left, targetSum) 
        + pathSum(root->right, targetSum);
    }

private:
    int countSum(TreeNode* node, int target) {
        if (node == nullptr) {
            return 0;
        }

        int count = 0;

        if (node->val == target) {
            count++;
        }
        
        count += countSum(node->left, target - node->val);
        count += countSum(node->right, target - node->val);

        return count;
    }
};
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;  // long long 사용
        prefixSumCount[0] = 1;  // 루트에서의 기본 합 (0) 포함
        return dfs(root, 0, targetSum, prefixSumCount);
    }

private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0;

        // 현재 노드까지의 누적 합
        currentSum += node->val;
        
        // 이전 경로에서 targetSum을 만드는 가능한 방법의 수
        int count = prefixSumCount[currentSum - targetSum];

        // 현재 누적 합을 맵에 추가
        prefixSumCount[currentSum]++;
        
        // 왼쪽과 오른쪽 자식을 탐색하며 계속 경로를 누적
        count += dfs(node->left, currentSum, targetSum, prefixSumCount);
        count += dfs(node->right, currentSum, targetSum, prefixSumCount);
        
        // 해당 경로를 모두 탐색한 후, 현재 경로의 누적 합을 맵에서 제거 (백트래킹)
        prefixSumCount[currentSum]--;
        
        return count;
    }
};
