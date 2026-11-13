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

void dfs(pair<TreeNode*, int> node, int& max_depth){

    auto [current_node, current_depth] = node;

    if(current_node == nullptr){
        return;
    }

    max_depth = max(current_depth, max_depth);

    dfs({current_node->left, current_depth + 1}, max_depth); 
    dfs({current_node->right, current_depth + 1}, max_depth);

    

}


int dfs_bis(TreeNode* node){
    if(node == nullptr){
        return 0;
    }

    int depth_left = dfs_bis(node->left);
    int depth_right = dfs_bis(node->right);

    return 1 + max(depth_left, depth_right);

}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        

        return dfs_bis(root);

        
    }
};
