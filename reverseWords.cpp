#include<iostream>
#include<string>
using namespace std;
void reverseWords(string &s) {
    reverse(s.begin(),s.end());
    int index = s.find(' ');
    int curr = 0;
    while(index != string::npos){
        reverse(s.begin()+curr,s.begin()+index);
        curr = index+1;
        index = s.find(' ',curr+1);
    }
    reverse(s.begin()+curr,s.begin()+index);
}
int main(void){
    string s;
    getline(cin,s);
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}