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
    int maxDepth(TreeNode* root) {
        
        stack<pair<TreeNode*, int>> st;
        if(!root){
            return 0;
        }
        int max_depth = 0;
        st.push({root, 1});

        while(!st.empty()){

            auto [current, depth]  = st.top(); //depth is the current;
            st.pop();

            max_depth = max(max_depth, depth); // the maximum found before 

            if(current->left){
                st.push({current->left, depth + 1});
            } 

            if(current->right){
                st.push({current->right, depth + 1});
            }

        }

        return max_depth;

    }
};
