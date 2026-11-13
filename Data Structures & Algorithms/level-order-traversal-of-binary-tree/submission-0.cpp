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
    

    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> results;
        
        while(!q.empty()){

            int level_size = q.size();

            vector<int> res;
            for(int i = 0; i < level_size; i++){
                
                TreeNode* current = q.front();
                q.pop();

                res.push_back(current->val);

                if(current->left != nullptr){
                    q.push(current->left);
                }

                if(current->right != nullptr){
                    q.push(current->right);
                } 
            }

            results.push_back(res);
        }

        return results;

    }
};
