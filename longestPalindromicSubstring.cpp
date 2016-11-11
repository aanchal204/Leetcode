/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

https://leetcode.com/problems/longest-palindromic-substring/
*/
class Solution {
public:
    int dp[1003][1003];
    string longestPalindrome(string s) {
        
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.length();i++)
            dp[i][i] = 1;
        int max = 1;
        int start = 0;
        for(int len = 2;len<=s.length();len++){
            for(int j=0;j+len-1<s.length();j++){
                int k = j+len-1;
                if(s[j] == s[k]){
                    if(len==2)
                        dp[j][k] = 2;
                    else if(dp[j+1][k-1])
                        dp[j][k] = dp[j+1][k-1]+2;
                    if(dp[j][k] > max){
                        max = dp[j][k];
                        start = j;
                    }
                }
            }
        }
        s = s.substr(start,max);
        return s;
    }
};