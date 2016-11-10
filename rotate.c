// https://leetcode.com/problems/rotate-function/
int maxRotateFunction(int* A, int ASize) {
    long long int max = 0;
    long long int sum = 0;
    int i;
    long long int prev = 0;
    for(i=0;i<ASize;i++){
        sum += A[i];
        prev += i*A[i];
    }
    max = prev;
    for(i=ASize-1;i>0;i--){
        long long int curr = prev + sum - A[i]*ASize;
        if(curr > max)
            max = curr;
        prev = curr;
    }
    return max;
}
int main(void){
    int arr = {10000004};
    printf("%d\n",arr,1);
    return 0;
}