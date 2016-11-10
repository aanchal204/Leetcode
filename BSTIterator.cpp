/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    list<int> inorder;
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> st;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            inorder.push_back(root->val);
            st.pop();
            root = root->right;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !inorder.empty();
            
    }

    /** @return the next smallest number */
    int next() {
        int val = inorder.front();
        inorder.pop_front();
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */