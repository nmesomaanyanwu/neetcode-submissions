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
        1) if root is null then return null ;
        2) for the stepcase we check if both p& q is less than root , if p is less and q is greater or if both is greater
        3) we return root->left , root or root-> right depending on what it is
        */

        if (root == nullptr){
            return nullptr;
        }
        else if (root != nullptr && p == nullptr && q == nullptr){
            return root;
        }
        else{
            if ((root->left != nullptr) && (p->val <root->val)&& (q->val <root->val)){
                return root->left;
            }
            else if ((root->right != nullptr && root->left != nullptr) && (p->val <root->val )&& (q->val >root->val)){
                    return root;
            }
            else if ((root->right != nullptr && root->left != nullptr) && (p->val >root->val )&& (q->val <root->val)){
                return root;
            }
            else if ((root->right != nullptr) && (p->val >root->val)&& (q->val >root->val)){
                return root->right;
            }
            else{
                return root;
            }

            TreeNode* left = lowestCommonAncestor(root->left,p , q);
            TreeNode* right = lowestCommonAncestor(root->right,p , q);

        }

    }
};
