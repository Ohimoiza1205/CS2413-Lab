void preorder(struct TreeNode* root, int* arr, int* returnSize) {
    // Check if the current node is not NULL
    if (root) {
        // Store the current node's value in the array
        arr[(*returnSize)++] = root->val;

        // Recursively visit the left child
        preorder(root->left, arr, returnSize);

        // Recursively visit the right child
        preorder(root->right, arr, returnSize);
    }
}

// This function initializes the array and starts the traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate memory for the result array
    int* arr = (int*)malloc(sizeof(int) * 100);

    // Initialize the return size to 0
    *returnSize = 0;

    // Perform preorder traversal and store results in 'arr'
    preorder(root, arr, returnSize);

    // Return the result array
    return arr;
}
