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
    void dfs(TreeNode* node, int current_val_max, int& count){
        if(node == nullptr){
            return;
        }

        if(node->val >= current_val_max){
            count++;
        }

        current_val_max = max(current_val_max, node->val);

        dfs(node->left, current_val_max, count);
        dfs(node->right, current_val_max, count);

    }

    int goodNodes(TreeNode* root) {
        
        if(root == nullptr){
            return 0;
        }

        int current_val_max = INT_MIN;
        int count = 0;
        dfs(root, current_val_max, count);

        return count;

        
    }
};
