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
    long prevl = LONG_MIN;
    long prevr = LONG_MAX; 
public:
    bool isValidBST(TreeNode* root) {
        return valid(root , prevl , prevr);
        
    }
private:
    bool valid (TreeNode* node , long lo , long hi){
        if (node == nullptr){
            return true;
        }
        else if (node->val <= lo || node->val >= hi ){
            return false;
        }
        return valid(node->left , lo, node->val) && valid(node->right , node->val, hi);

    }

};  
