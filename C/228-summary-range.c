/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** res = malloc(sizeof(char*) * numsSize);
    *returnSize = 0;

    if (numsSize == 0) return res;

    int start = nums[0];
    int i = 0;
    while (i < numsSize)
    {
        if (numsSize - 1 == i || nums[i] + 1 != nums[i + 1])
        {
            res[*returnSize] = (char*)malloc(sizeof(char) * 25);
            if (start == nums[i])
            {
                sprintf(res[*returnSize],"%d", start);
            }
            else
            {
                sprintf(res[*returnSize],"%d->%d", start, nums[i]);
            }
            if (i < numsSize - 1)
            {
                start = nums[i + 1];
            }
            (*returnSize)++;
        }
        i++;
    }
    return (res);
}