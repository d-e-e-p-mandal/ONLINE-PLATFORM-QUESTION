//Leetcode : 1423 : Maximum Points You Can Obtain from Cards

#include <stdio.h>

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int sum = 0;

    for(int i = cardPointsSize - k; i < cardPointsSize; i++) sum += cardPoints[i]; // calculate sum of last k element
    int maxSum = sum;
    for(int i = 0; i < k; i++){
        sum = sum - cardPoints[cardPointsSize - k + i] + cardPoints[i]; // remove 1 and add from 1st as consecutive
        maxSum = (sum > maxSum) ? sum : maxSum;
    }

    return maxSum;
}

int main() {
    int cardPoints[] = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int size = sizeof(cardPoints) / sizeof(cardPoints[0]);

    int result = maxScore(cardPoints, size, k);
    printf("Maximum score: %d\n", result);

    return 0;
}

/*OUTPUT : Maximum score: 12 */
/* Time Complexity : O(N)
Space Complexity : O(1)*/