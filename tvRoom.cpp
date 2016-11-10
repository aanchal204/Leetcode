#include <iostream>
#include<vector>
#include<map>
using namespace std;
int tvRoom(vector<int>begin, vector<int> end){
	vector<pair<int, int> >interval;
	for(int i=0;i<begin.size();i++)
		interval.push_back(make_pair(begin[i],end[i]));
	sort(interval.begin(),interval.end());
	int left,right,hours;
	left = interval[0].first;
	right = interval[0].second;
	hours = 0;
	for(int i=1;i<interval.size();i++){
		cout<<interval[i].first<<" "<<interval[i].second<<endl;
		if(interval[i].first > right){
			hours += (right-left);
			left = interval[i].first;
			right = interval[i].second;
		}else
			right = max(right,interval[i].second);
	}
	hours += right-left;
	return hours;
}
int main() {
	// your code goes here
	int arr[] = {1,6,2,7,10};
	int barr[] = {4,8,4,9,15};
	vector<int>begin(arr,arr+5);
	vector<int>end(barr,barr+5);
	cout<<tvRoom(begin,end)<<endl;
	return 0;
}