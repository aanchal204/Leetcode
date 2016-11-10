// https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> bucket;
        int i;
        for(i=0;i<nums.size();i++){
            if(bucket.find(nums[i]) != bucket.end() && i-bucket[nums[i]]<=k)
                return true;
            bucket[nums[i]] = i;
        }
        return false;
    }
};