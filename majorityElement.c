// https://leetcode.com/problems/majority-element/
int majorityElement(int* nums, int numsSize) {
    int count = 1;
    int maj_el = nums[0];
    int i;
    for(i=1;i<numsSize;i++){
        if(nums[i] == maj_el)
            count++;
        else
            count--;
        if(count == 0){
            maj_el = nums[i];
            count = 1;
        }
    }
    return maj_el;
}