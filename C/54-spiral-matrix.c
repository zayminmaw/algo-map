/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    // matrixSize = how many rows
    // matrixColSize = how many cols in each rows
    if (matrixSize == 0) return NULL;
    *returnSize = matrixSize * matrixColSize[0];
    int* res = malloc(sizeof(int) * (*returnSize));

    int i = 0;
    int top = 0;
    int left = 0;
    int bottom = matrixSize - 1;
    int right = matrixColSize[0] - 1;
    while (i < (*returnSize))
    {
        for (int col = left; col <= right; col++)
        {
            res[i++] = matrix[top][col];
        }
        top++;
        for (int row = top; row <= bottom; row++)
        {
            res[i++] = matrix[row][right];
        }
        right--;
        if (top <= bottom)
        {
            for(int col = right; col >= left; col--)
            {
                res[i++] = matrix[bottom][col];
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int row = bottom; row >= top; row--) {
                res[i++] = matrix[row][left];
            }
            left++; 
        }

    }
    return res;
}