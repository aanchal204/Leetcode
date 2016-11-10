// https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> arr;
        while(digits.size()){
            int sum = digits.back() + carry;
            digits.pop_back();
            arr.insert(arr.begin() , sum%10);
            carry = sum/10;
        }
        if(carry)
            arr.insert(arr.begin(),carry);
        return arr;
    }
};