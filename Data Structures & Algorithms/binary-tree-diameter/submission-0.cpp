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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        /*
        How i'd approach this;
        1. Do the base case if the tree is null then the maximum diamer is going to be null
        2. i think we want to get the makimum length at each time check if we wan to add the two sides once they reach like root
        
        */
        depth(root);
        return diameter;

    }

private:
    int depth(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        else{
            int left = depth(node->left);
            int right = depth(node->right);

            if ( left + right > diameter){
                diameter = left + right;
            }

            return 1 + max(left , right);
        }
    }
    
};
