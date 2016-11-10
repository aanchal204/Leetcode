class Solution {
public:
    string multiply(string num1, string num2) {
        int carry=0;
        string ans(num1.length() + num2.length(),'0');
        int last = ans.length()-1;
        for(int i=num1.size()-1;i>=0;i--){
            int x = num1[i]-'0';
            int curr = last;
            carry = 0;
            for(int j=num2.size()-1;j>=0;j--,curr--){
                int y = num2[j]-'0';
                int sum = x*y+carry+(ans[curr]-'0');
                ans[curr] = (sum%10)+'0';
                carry = sum/10;
                
            }
            if(carry)
                ans[curr] = ans[curr]-'0' + carry + '0';
            last--;
        }
        while(ans.length()>1 && ans[0] == '0')
            ans = ans.erase(0,1);
        return ans;
    }
};