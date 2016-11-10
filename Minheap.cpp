/*
Min Heap: insert(), heapify(), and getMin()
*/
#include<iostream>
#include<vector>
#include<climits>
#define SIZE 5000
using namespace std;
int heap[SIZE];
int size;
int parent(int x){
	return (x-1)/2;
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void insert(int x){
	if(size == SIZE){
		cout<<"Heap overflow!"<<endl;
		return ;
	}
	heap[size] = x;
	size++;
	int i = size-1;
	while(i>=0 && heap[i]<heap[parent(i)]){
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}
void heapify(int root){
	int left,right,index;
	left = 2*root+1;
	right = 2*root+2;
	index = root;
	if(left<size && heap[left]<heap[index])
		index = left;
	if(right<size && heap[right]<heap[index])
		index = right;
	if(index != root){
		swap(heap[root],heap[index]);
		heapify(index);
	}
}
int getMin(void){
	if(size == 0)
		return INT_MAX;
	if(size == 1){
		size --;
		return heap[0];
	}
	int min = heap[0];
	heap[0] = heap[size-1];
	size--;
	heapify(0);
	return min;
}
int main(void){
	int n,x;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		cin>>x;
		arr.push_back(x);
		insert(x);
	}
	int min;
	while((min=getMin())!=INT_MAX)
		cout<<min<<" ";
	return 0;
}