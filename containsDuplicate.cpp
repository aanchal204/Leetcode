// https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> bucket;
        for(int i=0;i<nums.size();i++){
            if(bucket.find(nums[i]) != bucket.end())
                return true;
            bucket[nums[i]] = i;
        }
        return false;
    }
};