void traversal(struct TreeNode* root, int* result, int* index) {
    // Check if the current node is not NULL
    if (root != NULL) {
        // Recursively visit the left child
        traversal(root->left, result, index);

        // Add the current node's value to the result array
        result[(*index)++] = root->val;

        // Recursively visit the right child
        traversal(root->right, result, index);
    }
}

// This function starts the inorder traversal and returns the result array
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int index = 0;  // Initialize index to track the current position in the result array
    int* result = malloc(100 * sizeof(int));  // Allocate memory for the result array

    // Perform inorder traversal and store the result
    traversal(root, result, &index);

    // Set the return size to the number of elements in the result
    *returnSize = index;

    // Return the result array containing the inorder traversal
    return result;
}
