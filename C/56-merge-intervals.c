int compare(const void* a, const void* b) {
   return ((int**)a)[0][0] - ((int**)b)[0][0];
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    // handle edge case
    if (intervalsSize == 0) return res;
    // sort in asc
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // start at index 1
    int i = 1;
    int start = intervals[0][0];
    int end = intervals[0][1];

    while (i < intervalsSize)
    {
        // check if end is smaller than current first range
        if (intervals[i][0] <= end)
        {
            // if smaller, check if its end is bigger. Assign the bigger end
            end = (intervals[i][1] > end) ? intervals[i][1] : end;
        }
        // if end is bigger, add it into return array
        else
        {
            // create new range
            int* inner_res = (int*)malloc(sizeof(int) * 2);
            inner_res[0] = start;
            inner_res[1] = end;
            // assign the new range into res
            res[(*returnSize)] = inner_res;
            (*returnColumnSizes)[*returnSize] = 2;
            // get new range
            start = intervals[i][0];
            end= intervals[i][1];
            // increment return size
            (*returnSize)++;
        }
        i++;
    }
    // assign the rest/end into res
    int* inner_res = (int*)malloc(sizeof(int) * 2);
    inner_res[0] = start;
    inner_res[1] = end;
    res[(*returnSize)] = inner_res;
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    return res;
}