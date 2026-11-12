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
    bool isSametree(TreeNode* root, TreeNode* second_root){
        if(root == nullptr && second_root == nullptr){
            return true;
        }

        if((root == nullptr && second_root != nullptr) || (root != nullptr && second_root == nullptr)){
            return false;
        }

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(root);
        q2.push(second_root);

        while(!q1.empty() && !q2.empty()){

            TreeNode* current = q1.front();
            TreeNode* second_current = q2.front();

            q1.pop();
            q2.pop();

            if(current == nullptr && second_current == nullptr){
                continue;
            }

            if(current == nullptr || second_current == nullptr){
                return false;
            }

            if(current->val != second_current->val){
                return false;
            }

            q1.push(current->left);
            q2.push(second_current->left);

            q1.push(current->right);
            q2.push(second_current->right);

        }

        return q1.empty() && q2.empty();

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == nullptr){
            return true;
        }

        if(root == nullptr){
            return false;
        }

        if(isSametree(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);


    }
};
