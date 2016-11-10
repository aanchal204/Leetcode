/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int prod = 1;
        res.push_back(1);
        for(int i=1;i<nums.size();i++){
            res.push_back(res.back()*nums[i-1]);
        }
        prod = nums[nums.size()]-1;
        for(int i=nums.size()-2;i>=0;i--){
            res[i] = res[i]*prod;
            prod = prod*nums[i];
        }
        return res;
    }

int main(void){
    int arr[] = {0,0};
    int *ans = productExceptSelf(arr,2,2);
    for(int i=0;i<2;i++)
        printf("%d ",ans[i]);
    return 0;
}