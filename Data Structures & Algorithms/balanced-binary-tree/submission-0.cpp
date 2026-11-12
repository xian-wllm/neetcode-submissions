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
    int dfs(TreeNode* node, bool& balanced){
        if(node == nullptr){
            return 0;
        }

        int left_depth = 0;
        int right_depth = 0;
        if(node->left != nullptr){
            left_depth = dfs(node->left, balanced);
        }

        if(node->right != nullptr){
            right_depth = dfs(node->right, balanced);
        }


        if(abs(left_depth - right_depth) > 1){
            balanced = false;
        }

        return 1 + max(left_depth, right_depth);

    }

    bool isBalanced(TreeNode* root) {
        
        bool balanced = true;
        dfs(root, balanced);

        return balanced;

    }
};
