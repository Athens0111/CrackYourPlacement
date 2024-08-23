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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;  // Initialize a variable to store the sum of values within the given range

        // If the root is not null and its value lies within the range [low, high], add it to the sum
        if (root && (root->val) >= low && (root->val) <= high)
            ans += root->val;

        // Recursively check the left subtree and add the sum of nodes within the range
        if (root && root->left)
            ans += rangeSumBST(root->left, low, high);

        // Recursively check the right subtree and add the sum of nodes within the range
        if (root && root->right)
            ans += rangeSumBST(root->right, low, high);

        // Return the total sum of nodes' values that fall within the given range
        return ans;
    }
};