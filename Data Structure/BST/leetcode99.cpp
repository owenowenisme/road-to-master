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
    TreeNode *first=NULL,*second= NULL,*prev= NULL;

    void inorder_tree_traversal(TreeNode* cur){
       if(cur->left){
           inorder_tree_traversal(cur->left);
       }
                
           if(prev&&cur -> val < prev -> val ){
                if(!first) first = prev ;
                second = cur;
            }
        prev = cur;
       if(cur->right){
           inorder_tree_traversal(cur->right);
       }
       return ;
    }
public:
    void recoverTree(TreeNode* root) {
        inorder_tree_traversal(root);
        swap (first->val , second ->val);
    }
};