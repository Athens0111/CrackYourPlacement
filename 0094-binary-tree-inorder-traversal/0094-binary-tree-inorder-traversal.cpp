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
    vector<int> inorderTraversal(TreeNode* root) {
        
    vector<int> result;
    stack<TreeNode*> s;

    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        // Traverse left subtree and push nodes onto the stack
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Process the current node
        current = s.top();
        s.pop();
        result.push_back(current->val);

        // Move to the right subtree
        current = current->right;
    }

    return result;

    }
};