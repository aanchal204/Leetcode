class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i=2;i<=n;i++){
            string prev = s;
            s = "";
            char ch = prev[0];
            int count = 0;
            for(int j=0;j<prev.length();){
                while(j<prev.length() && ch == prev[j]){
                    count++;
                    j++;
                }
                
                s += to_string(count)+ch;
                count = 0;
                if(j<prev.length())
                    ch = prev[j];   
            }
        }
        return s;
    }
};