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
    int height(TreeNode *root, int &ans) {
        // Base case: If the node is null, return 0 as the height
        if (!root)
            return 0;

        // Recursively calculate the height of the left subtree
        int leftHeight = height(root->left, ans);

        // Recursively calculate the height of the right subtree
        int rightHeight = height(root->right, ans);

        // Update the diameter (ans) if the sum of left and right heights is greater than the current diameter
        ans = max(ans, leftHeight + rightHeight);

        // Return the height of the current node, which is the maximum height of its subtrees plus 1
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;  // Initialize the diameter (ans) as 0
        height(root, ans);  // Calculate the height of the tree and update the diameter in the process
        return ans;  // Return the diameter of the binary tree
    }
};