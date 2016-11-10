// https://leetcode.com/problems/remove-element/
int removeElement(int* nums, int numsSize, int val) {
    int i,pos = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i] != val){
            nums[pos] = nums[i];
            pos++;
        }
    }
    return pos;
}