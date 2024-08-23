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
    int height(TreeNode *root) {
        // Base case: If the node is a leaf node (no children), return height as 1
        if (!root->left && !root->right)
            return 1;

        int x = 0, y = 0; // Initialize height of left and right subtrees

        // Recursively calculate height of left subtree if it exists
        if (root->left)
            x = height(root->left);

        // Recursively calculate height of right subtree if it exists
        if (root->right)
            y = height(root->right);

        // Return the maximum of left and right subtree heights plus 1 (for the current node)
        return (x > y ? x : y) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize variables to store the height of the left and right subtrees
        int ans = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            int left = 0, right = 0;
            TreeNode *p = stk.top();
            stk.pop();
            // Calculate height of the left subtree if it exists
            if (p->left){        
                left = height(p->left);
                stk.push(p->left);
            }

            // Calculate height of the right subtree if it exists
            if (p->right){
                right = height(p->right);
                stk.push(p->right);
            }

            if(ans < (left+right))
                ans = left+right;
        }
        // The diameter of the tree is the sum of the heights of the left and right subtrees
        return ans;
    }
};