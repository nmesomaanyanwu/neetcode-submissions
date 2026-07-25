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
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int treeLevel = q.size(); // tree level 
            vector<int> current;
            for (int i = 0 ; i < treeLevel; i++){
                TreeNode* node = q.front();
                q.pop();
                current.push_back(node->val);
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(current);

        }

        return ans;
        
        
    }
};
