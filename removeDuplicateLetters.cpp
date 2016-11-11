/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

https://leetcode.com/problems/remove-duplicate-letters/
*/
class Solution {
public:
    #define SIZE 26
    string removeDuplicateLetters(string s) {
        vector<int> remaining(SIZE,0);
        for(const auto& c : s){
            remaining[c-'a']++;
        }
        vector<bool> inStack(SIZE);
        string st;
        for(const auto& c : s){
            if(!inStack[c-'a']){
                while(!st.empty() && st.back() > c && remaining[st.back()-'a']){
                    inStack[st.back()-'a'] = false;
                    st.pop_back();
                }
                st.push_back(c);
                inStack[c-'a'] = true;
            }
            remaining[c-'a']--;
        }
        return st;
    }
};