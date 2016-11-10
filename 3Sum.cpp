class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >ans;
        for(int i=0;i<nums.size() && nums[i]<=0 ;i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int sum = -nums[i];
            int left,right;
            left = i+1;
            right = nums.size()-1;
            while(left<right){
                if(nums[left] + nums[right] == sum){
                    vector<int> v;
                    v.push_back(-sum);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    ans.push_back(v);
                    right--;
                    left++;
                    while(left<right && nums[left]==nums[left-1])
                        left++;
                    while(left<right && nums[right]==nums[right+1])
                        right--;
                }else if(nums[left] + nums[right] > sum)
                    right--;
                else
                    left++;
            }
        }
        return ans;
    }
};