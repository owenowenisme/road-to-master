#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
#define int long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

typedef node node;

void buildtree(node *root,node *newnode) {
    
    
    node *cur = root;
    while (1) {
        if (newnode->data < cur->data) {
            if (cur->left == NULL) {
                cur->left = newnode;
                break;
            } else {
                cur = cur->left;
                continue;
            }
        } else {
            if (cur->right == NULL) {
                cur->right = newnode;
                break;
            } else {
                cur = cur->right;
                continue;
            }
        }
    }
}
void preorder_tree_traversal(node *cur){
    cout<< cur->data<<' ';
    if(cur->left!=NULL){
        preorder_tree_traversal(cur->left);
    }
    if(cur->right!=NULL){
        preorder_tree_traversal(cur->right);
    }
    return;
}
void inorder_tree_traversal(node *cur){
    if(cur->left){
        inorder_tree_traversal(cur->left);
    }
    cout<< cur->data<<' ';
    if(cur->right){
        inorder_tree_traversal(cur->right);
    }
}

void solve(){
    int t;
    while(cin >> t){
        node *tree = new node;
        int tmp=0;
        cin>>tmp;
        tree->data=tmp;
        for(int i=1;i<t;i++){
            cin>>tmp;
            node *newnode = new node;
            newnode->data = tmp;
            buildtree(tree,newnode);
        }
        // preorder_tree_traversal(tree);
        inorder_tree_traversal(tree);
        cout<<'\n';
    }
    
}
signed main(void){
    ac;
    solve();
    return 0;
}