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
vector<int> ans{};
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if (preorder.empty()) return nullptr; 

        TreeNode* node = new TreeNode(preorder[0]);

        int mid = find(inorder.begin(), inorder.end(),preorder[0]) - inorder.begin();

        vector<int> leftPre(preorder.begin()+ 1 , preorder.begin()+ 1+mid);
        vector<int> leftIn(inorder.begin() , inorder.begin() +mid);
        vector<int> rightPre(preorder.begin()+ 1 + mid , preorder.end());
        vector<int> rightIn(inorder.begin()+ mid+ 1 ,inorder.end());
        
        
        node->left  = buildTree(leftPre,  leftIn);
        node->right = buildTree(rightPre, rightIn);

        return node;
        
    }
};
