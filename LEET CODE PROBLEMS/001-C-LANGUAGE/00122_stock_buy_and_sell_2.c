// LEET CODE QUESTION 122
#include<stdio.h>
int maxProfit(int* prices, int pricesSize) {
    int i,profit=0,buy,sell;
    buy=prices[0];
    for(i=1;i<pricesSize;i++){
        if(buy > prices[i]){
            buy=prices[i];
            continue;   // can't sell on the same day
        }
        if((i==pricesSize-1) || (prices[i]-buy >= prices[i+1]-buy )){   // [i+1] is not unvalid for previos condition
            if((prices[i]-buy)>0)   // for last sell condition
                profit+=prices[i]-buy;
            buy=2147483647;     // MAX_INT in number form, to buy next after sell
        } 
    }
    return profit;
}
int main(){
    int n,i;
    printf("Enter number of day : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter prices : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Maximum profit is %d \n",maxProfit(arr,n));
    
    return 0;
}
/*
OUTPUT :
Enter number of day : 6
Enter prices : 
7       1       5       3       6       4
Maximum profit is 7 
*/