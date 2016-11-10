// https://leetcode.com/problems/move-zeroes/
void moveZeroes(int* nums, int numsSize) {
    int left,right,i;
    left = right = 0;
    while(right<numsSize){
        if(nums[right]){
            nums[left] = nums[right];
            left++;
        }
        right++;
    }
    while(left<numsSize)
        nums[left++] = 0;
}
int main(void){
    int arr[] = {0,1,0,3,12};
    moveZeroes(arr,5);
    int i;
    for(i=0;i<5;i++)
        printf("%d ",*(arr+i));
    return 0;
}