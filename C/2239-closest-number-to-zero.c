int abs_num(int org)
{
    if (org < 0)
    {
        return (-org);
    }
    else
    {
        return (org);
    }
}

int findClosestNumber(int* nums, int numsSize) {
    int i = 0;
    int res = nums[0];
    int abs_res = abs_num(nums[0]);
    while (i < numsSize)
    {
        int abs_i = abs_num(nums[i]);
        if (abs_i < abs_res || (abs_i == abs_res && nums[i] > res))
        {
            res = nums[i];
            abs_res = abs_num(nums[i]);
        }
        i++;
    }
    return (res);
}