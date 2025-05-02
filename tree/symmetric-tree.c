// Define the TreeNode structure for the binary tree
typedef struct TreeNode NODE;

// Helper function that checks if two trees (or subtrees) are mirrors of each other
bool isMirror(NODE* rt1, NODE* rt2) {
    // If both nodes are NULL, the trees are symmetric (mirror of each other)
    if (rt1 == NULL && rt2 == NULL)
        return true;
    
    // If only one of the nodes is NULL, the trees are not symmetric (not mirror of each other)
    else if (rt1 == NULL || rt2 == NULL)
        return false;
    
    // Otherwise, check if the values of the current nodes are the same
    // and recursively check the opposite subtrees (left with right, right with left)
    return (rt1->val == rt2->val) && 
           isMirror(rt1->left, rt2->right) &&  // Check left subtree of rt1 with right subtree of rt2
           isMirror(rt1->right, rt2->left);    // Check right subtree of rt1 with left subtree of rt2
}

// Function to check if a binary tree is symmetric (mirror image of itself)
bool isSymmetric(struct TreeNode* root) {
    // A tree is symmetric if its left and right subtrees are mirrors of each other
    return isMirror(root->left, root->right);
}
