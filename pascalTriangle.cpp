// https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> >pascal;
        for(int i=0;i<numRows;i++){
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<i;j++)
                v.push_back(pascal[i-1][j] + pascal[i-1][j-1]);
            if(i>0)
                v.push_back(1);
            pascal.push_back(v);
        }
        return pascal;
    }
};