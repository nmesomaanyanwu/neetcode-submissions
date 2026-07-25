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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        Given its a binary seach tree we know p->val < root->val < q-> val
        So that means basically:
        1) we check if p and q are on opposite sides or one is equal to root we return root ;
        2) if p and q is less than root we recurse the root->left case
        3) if p and q is greater we recurse the right case
        */

        if ((p->val <= root->val && root->val <= q->val) || (q->val <= root->val && root->val <= p->val) ){
            return root;
        }
        else if ((p->val < root->val) && (q->val < root->val)){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if ((p->val > root->val) && (q->val > root->val)){
            return lowestCommonAncestor(root->right, p, q);
        }
        
    }
};
