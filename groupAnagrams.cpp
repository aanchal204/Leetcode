/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

https://leetcode.com/problems/anagrams/
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string> >ans;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(ans.find(s) == ans.end()){
                vector<string> v;
                v.push_back(strs[i]);
                ans[s] = v;
            }else{
                ans[s].push_back(strs[i]);
            }
        }
        vector<vector<string> >anagrams;
        for(map<string,vector<string> >::iterator it = ans.begin(); it!=ans.end(); it++){
            anagrams.push_back(it->second);
        }
        return anagrams;
    }
};