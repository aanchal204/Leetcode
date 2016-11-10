// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit(int* prices, int pricesSize) {
    int min = 0;
    int i;
    int ans = 0;
    min = prices[0];
    for(i=1;i<pricesSize;i++){
        if(prices[i]-min > ans)
            ans = prices[i]-min;
        if(prices[i] < min)
            min = prices[i];
    }
    return ans;
}