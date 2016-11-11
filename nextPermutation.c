/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

https://leetcode.com/problems/next-permutation/
*/
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void nextPermutation(int* nums, int numsSize) {
    int i,j,pos;
    for(i=numsSize-2;i>=0;i--)
        if(nums[i]<nums[i+1])
            break;
    if(i>=0){
    	//printf("yo");
        int min = i+1;
        for(j=i+1;j<numsSize;j++)
            if(nums[j] > nums[i] && nums[j] < nums[min])
                min = j;
        swap(&nums[i],&nums[min]);
    }
    pos = i+1;
    for(i=i+1;i<numsSize-1;i++)
    {
        for(j=pos;j<numsSize-1;j++)
        {
        	//printf("%d ",nums[j]);
            if(nums[j] > nums[j+1])
                swap(&nums[j],&nums[j+1]);
        }
    }
}