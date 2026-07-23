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
int ans = true;
public:
    
    bool isBalanced(TreeNode* root) {
        balanced(root);
        return ans;  
        
    }
private:
    int balanced(TreeNode* node) {
        if (node == nullptr){
            return 0;
        }
        int left = balanced(node->left);
        int right = balanced(node->right);

        if (abs(left - right) > 1){
            ans = false;
        }
        return 1 + max(left, right);
    }

};
