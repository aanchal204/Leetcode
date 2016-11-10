class Solution {
public:
    //this solution will give a time limit exceeded error
    //thus use dp!
    /*
    int combinations(string s, int pos){
        if(pos == s.length())
            return 1;
         int ans = 0;
         if(s[pos]!='0')
            ans = combinations(s,pos+1);
         if(pos+1 < s.length()){
             if((s[pos]=='1') || (s[pos]=='2' && s[pos+1]<='6'))
                ans += combinations(s,pos+2);
         }
         return ans;
    }
    int numDecodings(string s) {
        if(s.length() == 0)
            return 0;
        return combinations(s,0);
    }*/

    class Solution {
    public:
        bool isValid(char c){
            return (c>='1' && c<='9') ? true : false;
        }
        bool isValid(char a, char b){
            return ((a=='1') || (a=='2'&&b<='6')) ? true : false;
        }
        int numDecodings(string s) {
            vector<int> dp(s.length()+1,0);
            if(isValid(s[0]))
                dp[0] = 1;
            if(isValid(s[1]))
                dp[1] = dp[0];
            if(isValid(s[0],s[1]))
                dp[1] += 1;
            for(int i=2;i<s.length();i++){
                if(isValid(s[i]))
                    dp[i] += dp[i-1];
                if(isValid(s[i-1],s[i]))
                    dp[i] += dp[i-2];
            }
            return dp[s.length()-1];
        }
};
};