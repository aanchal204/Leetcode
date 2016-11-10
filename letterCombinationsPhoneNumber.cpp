/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
class Solution {
public:
    void findCombinations(string digits, string res, vector<string>& ans,int pos){
        if(pos == digits.size()){
            ans.push_back(res);
            return;
        }
        switch(digits[pos]){
            case '2':
                findCombinations(digits, res+"a",ans,pos+1);
                findCombinations(digits, res+"b",ans,pos+1);
                findCombinations(digits, res+"c",ans,pos+1);
                break;
            case '3':
                findCombinations(digits, res+"d",ans,pos+1);
                findCombinations(digits, res+"e",ans,pos+1);
                findCombinations(digits, res+"f",ans,pos+1);
                break;
            case '4':
                findCombinations(digits, res+"g",ans,pos+1);
                findCombinations(digits, res+"h",ans,pos+1);
                findCombinations(digits, res+"i",ans,pos+1);
                break;
            case '5':
                findCombinations(digits, res+"j",ans,pos+1);
                findCombinations(digits, res+"k",ans,pos+1);
                findCombinations(digits, res+"l",ans,pos+1);
                break;
            case '6':
                findCombinations(digits, res+"m",ans,pos+1);
                findCombinations(digits, res+"n",ans,pos+1);
                findCombinations(digits, res+"o",ans,pos+1);
                break;
            case '7':
                findCombinations(digits, res+"p",ans,pos+1);
                findCombinations(digits, res+"q",ans,pos+1);
                findCombinations(digits, res+"r",ans,pos+1);
                findCombinations(digits, res+"s",ans,pos+1);
                break;
            case '8':
                findCombinations(digits, res+"t",ans,pos+1);
                findCombinations(digits, res+"u",ans,pos+1);
                findCombinations(digits, res+"v",ans,pos+1);
                break;
            case '9':
                findCombinations(digits, res+"w",ans,pos+1);
                findCombinations(digits, res+"x",ans,pos+1);
                findCombinations(digits, res+"y",ans,pos+1);
                findCombinations(digits, res+"z",ans,pos+1);
                break;
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        findCombinations(digits,"",ans,0);
        return ans;
    }
};