/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums 
being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        multiset<int> st;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            int ct = st.count(nums[i]);
            if(ct <= 2)
                ans++;
            else{
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return ans;
    }
};