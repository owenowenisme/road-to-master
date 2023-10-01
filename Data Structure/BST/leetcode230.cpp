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
private:
    int ans=0;
    void inorder_tree_traversal(TreeNode* cur,int &k ){
        if(cur->left){
            inorder_tree_traversal(cur->left,k);
        }
        --k;
        
        if (k==0)
            ans= cur->val;
        
        if(cur->right){
            inorder_tree_traversal(cur->right,k);
        }
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder_tree_traversal(root,k);
        return ans;
    }
};