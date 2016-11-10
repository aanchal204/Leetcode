// https://leetcode.com/problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i;
        vector<int> arr;
        arr.push_back(1);
        if(rowIndex == 0){
            return arr;
        }if(rowIndex == 1){
            arr.push_back(1);
            return arr;
        }else{
            arr.push_back(1);
            int prev,curr;
            for(int j = 2;j<=rowIndex;j++){                
                prev = 0;
                curr = arr.back();
                arr.pop_back();
                for(i=1;i<j;i++){
                    arr.insert(arr.begin(),prev+curr);
                    prev = curr;
                    curr = arr.back();
                    arr.pop_back();
                }
                arr.insert(arr.begin(),prev+curr);
                arr.insert(arr.begin(),1);
            }
            
            return arr;
        }
    }
}; 