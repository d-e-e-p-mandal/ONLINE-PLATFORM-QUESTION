// LEETCODE : 135 : Candy
#include <stdio.h>

int candy(int* ratings, int n) {
    if(n == 1)return 1; // one child

    int candy[n]; // to store each children candies

    // 1st children initlize with 0 or 1, (boundary case)
    if(ratings[0] > ratings[1])candy[0] = 2;
    else candy[0] = 1;

    for(int i=1; i < n; i++){
        if(ratings[i-1] < ratings[i])candy[i] = candy[i-1] + 1;
        else candy[i] = 1;
    }

    // more candies from right also condition 
    int totalCandy = candy[n-1];
    for(int i = n - 2; i >= 0 ;i--){
        if((ratings[i] > ratings[i+1]) && candy[i] <= candy[i+1])
            candy[i] = candy[i+1] + 1;
        totalCandy += candy[i]; //total count
    }

    return totalCandy;
}

int main() {
    int ratings[] = {1, 0, 2};
    int n = sizeof(ratings) / sizeof(ratings[0]);

    int result = candy(ratings, n);
    printf("Total candies required: %d\n", result);

    return 0;
}
/* OUTPUT : Total candies required: 5*/