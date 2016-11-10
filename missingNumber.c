// https://leetcode.com/problems/missing-number/
int missingNumber(int* nums, int numsSize) {
    int i, sum;
    sum = 0;
    for(i=1;i<=numsSize;i++)
        sum += i;
    for(i=0;i<numsSize;i++)
        sum -= nums[i];
    return sum;
}