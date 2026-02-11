// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

// Example 1:


// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:


// Input: root = [2,1,3]
// Output: [2,1,3]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105

class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
    
    TreeNode* buildBalanced(vector<int>& nodes, int start, int end) {
        if (start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildBalanced(nodes, start, mid - 1);
        root->right = buildBalanced(nodes, mid + 1, end);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        
        // Step 1: Store inorder traversal (sorted)
        inorder(root, nodes);
        
        // Step 2: Build balanced BST
        return buildBalanced(nodes, 0, nodes.size() - 1);
    }
};
