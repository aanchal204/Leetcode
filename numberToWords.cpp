#include<iostream>
#include<string>
using namespace std;
string convert(int n){
	string units[] = {"" , "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string lessThan20[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	string tens[] = {"", "" ,"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string hundreds[] = {"hundred", "thousand", "million", "billion"};
	string ans = "";
	if(n==0)
		return ans;
	if(n/100)
		ans = ans + units[n/100] + " " + hundreds[0] + " ";
	n = n%100;
	if(n<20){
		if(n<10)
			ans = ans + units[n%10];
		else
			ans = ans + lessThan20[n%10];
	}else{
		ans = ans + tens[n/10] + " " + units[n%10];
	}
	return ans;
}
string numberToWords(int n){
	if(n<0){
		return "No negative numbers allowed.";
	}
	if(n==0)
		return "Zero";
	int base = 1000;		//to extract the last 3 digits
	int count = 0;
	string ans = "";
	string hundreds[] = {"", "thousand", "million", "billion"};
	do{
		ans = convert(n%base) + " " + hundreds[count] + " " + ans;
		count++;
		n = n/base;
	}while(n);
	return ans;
}
int main(void){
	int n;
	cin>>n;
	cout<<numberToWords(n)<<endl;
	return 0;
}