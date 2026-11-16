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
    TreeNode* dfs(vector<int>& preorder, unordered_map<int,int>& indexMap, int& preindex, int left, int right){
        
        if(left > right){
            return nullptr;
        }
        int rootVal = preorder[preindex];
        preindex++;
        TreeNode* node = new TreeNode(rootVal);

        int mid = indexMap[rootVal];

        node->left = dfs(preorder, indexMap, preindex, left, mid- 1);
        node->right = dfs(preorder, indexMap, preindex, mid + 1, right);
        
        return node;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;

        unordered_map<int, int> indexMap;
        for(int i = 0; i < inorder.size(); i++){
            indexMap[inorder[i]] = i;
        }

        return dfs(preorder, indexMap, preindex, 0, preorder.size() - 1);
    }
};
