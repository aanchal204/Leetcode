class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left,right;
        left = 0;
        right = numbers.size()-1;
        vector<int> ans;
        while(left<right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }if(sum < target)
                left++;
            else
                right--;
        }
        return ans;
    }
};