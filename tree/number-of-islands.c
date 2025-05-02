// Helper function to perform Depth First Search (DFS) and mark connected land as visited
void visit(char **grid, int i, int j, int gridSize, int *gridColSize)
{
    // If the current cell is out of bounds, return
    if (i < 0 || j < 0 || i >= gridSize)
        return;
    
    // If the column index is out of bounds for this row, return
    if (j >= gridColSize[i])
        return;

    // If the current cell is water ('0'), return (no need to explore further)
    if (grid[i][j] == '0')
        return;

    // Mark the current land cell ('1') as visited by changing it to water ('0')
    grid[i][j] = '0';

    // Recursively visit all neighboring cells (up, down, left, right)
    visit(grid, i-1, j, gridSize, gridColSize);  // Visit cell above
    visit(grid, i+1, j, gridSize, gridColSize);  // Visit cell below
    visit(grid, i, j-1, gridSize, gridColSize);  // Visit cell to the left
    visit(grid, i, j+1, gridSize, gridColSize);  // Visit cell to the right
}

// Function to count the number of islands in the grid
int numIslands(char** grid, int gridSize, int* gridColSize){
    int i, j;
    int res = 0; // Initialize result to store the count of islands
    
    // Iterate over each cell in the grid
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            // If the current cell is land ('1')
            if (grid[i][j] == '1') {
                // Start a DFS to mark the entire island as visited
                visit(grid, i, j, gridSize, gridColSize);
                
                // Increment the result as we have found an island
                res++;
            }
        }
    }
    // Return the total number of islands found
    return res;
}
