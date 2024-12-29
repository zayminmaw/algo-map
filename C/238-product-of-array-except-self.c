/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    if (numsSize == 0) return res;
    int i = 0;
    int pre = 1;
    int suf = 1;
    while (i < numsSize)
    {
        if (i != 0)
            pre *= nums[i - 1];
        res[i] = pre;
        i++;
    }
    i = numsSize - 1;
    while (i >= 0)
    {
        res[i] *= suf;
        suf *= nums[i];
        i--;
    }
    return res;
}