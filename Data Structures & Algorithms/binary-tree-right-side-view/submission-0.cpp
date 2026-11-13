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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<int> results;
        while(!q.empty()){

            int queue_size = q.size();

            for(int i = 0; i < queue_size; i++){
                TreeNode* current = q.front();
                q.pop();

                
                if(i == queue_size - 1){
                    results.push_back(current->val);
                }

                if(current->left != nullptr){
                    q.push(current->left);
                }   

                if(current->right != nullptr){
                    q.push(current->right);
                }   

            }

        }
        return results;
    }
};
