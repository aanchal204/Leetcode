class Solution {
public:

     TreeNode *LCA( TreeNode *root,  TreeNode* p,  TreeNode* q, bool &v1, bool &v2){
         if(!root)
            return NULL;
        if(root == p){
            v1 = true;
            return root;
        }
        if(root == q){
            v2 = true;
            return root;
        }
         TreeNode * left = LCA(root->left, p,q, v1,v2);
        TreeNode * right = LCA(root->right, p,q, v1,v2);
        if(left && right)
            return root;
        return left?left:right;
     }
    bool find( TreeNode * root,  TreeNode *p ){
        if(root == NULL)
            return false;
        if(root->val == p->val || find(root->left,p) || find(root->right,p))
            return true;
        return false;
     }
     TreeNode* lowestCommonAncestor( TreeNode* root,  TreeNode* p,  TreeNode* q) {
        bool v1,v2;
        v1=v2=false;
         TreeNode *ans = LCA(root,p,q,v1,v2);
        if((v1 && v2) || (v1 && find(root,q)) || (v2&& find(root,p)))
            return ans;
        return NULL;
    }
};