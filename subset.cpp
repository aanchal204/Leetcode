/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
https://leetcode.com/problems/subsets/
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1LL<<(nums.size());
        vector<vector<int> >ans;
        for(int i=0;i<n;i++){
            int x = i;
            vector<int>v;
            int index = 0;
            while(x){
                if(x&1)
                    v.push_back(nums[index]);
                x = x>>1;
                index++;
            }
            ans.push_back(v);
        }
        return ans;
    }
};