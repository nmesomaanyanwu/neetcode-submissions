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
    int prev = INT_MIN;
    int count = 0;
public:
    int goodNodes(TreeNode* root) {
        good(root , prev);
        return count;
    }
private:
    void good(TreeNode* node,int p ){
        if (node == nullptr){
            return ;
        }
        
        if (!(p > node->val) ){
            count++;
            
        }
        p = max(p, node->val);
        good(node->left, p);
        good(node->right, p);

        

    }
};
