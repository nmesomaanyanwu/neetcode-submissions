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

vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        /*dfs*/
        
        depth_of_tree(root , 0);
        return ans;

        

        

        
    }
private:
    void depth_of_tree(TreeNode* node, int d){
        if (node == nullptr){
            return ;
        }
        else{
            if (d == ans.size()){
                ans.push_back(node->val);
                
            }
            depth_of_tree(node->right , d+1);
            
            depth_of_tree(node->left, d+ 1);

        }

        return;
    }

    
};
