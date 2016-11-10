/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
https://leetcode.com/problems/sort-colors/
*/
class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int left,mid,right;
        left = mid = 0;
        right = nums.size()-1;
        while(mid<=right){
            if(nums[mid] == 0){
                swap(nums[left],nums[mid]);
                left++;
                mid++;
            }else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[mid],nums[right]);
                right--;
            }
        }
    }
};