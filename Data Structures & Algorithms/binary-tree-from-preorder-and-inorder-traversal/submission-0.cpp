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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& preindex, int left, int right){
        
        if(left > right){
            return nullptr;
        }
        int rootVal = preorder[preindex];
        preindex++;
        TreeNode* node = new TreeNode(rootVal);

        int mid = -1;
        for(int i = left; i <= right; i++){
            if(inorder[i] == rootVal){
                mid = i;
                break;
            }
        }

        node->left = dfs(preorder, inorder, preindex, left, mid- 1);
        node->right = dfs(preorder, inorder, preindex, mid + 1, right);
        
        return node;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;

        return dfs(preorder, inorder, preindex, 0, preorder.size() - 1);
    }
};
