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
        for (int ltr = left; ltr <= right; ltr++)
        {
            res[i++] = matrix[top][ltr];
        }
        top++;
        for (int ttb = top; ttb <= bottom; ttb++)
        {
            res[i++] = matrix[ttb][right];
        }
        right--;
        if (top <= bottom)
        {
            for(int rtl = right; rtl >= left; rtl--)
            {
                res[i++] = matrix[bottom][rtl];
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int btt = bottom; btt >= top; btt--) {
                res[i++] = matrix[btt][left];
            }
            left++; 
        }

    }
    return res;
}