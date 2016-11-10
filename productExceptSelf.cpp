/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<vector>
 #include<iostream>
 using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int prod = 1;
        res.push_back(1);
        for(int i=1;i<nums.size();i++){
            res.push_back(res.back()*nums[i-1]);
        }
        // for(int i=0;i<nums.size();i++)
        //     cout<<res[i]<<" ";
        prod = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            res[i] = res[i]*prod;
            prod = prod*nums[i];
        }
        return res;
    }

int main(void){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    vector<int> res = productExceptSelf(num);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    return 0;
}