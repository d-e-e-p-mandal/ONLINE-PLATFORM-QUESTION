// LEETCODE - 9 : Palindrome Number
#include <stdio.h>

int isPalindrome(int x) { // Function to check if a number is a palindrome
    if (x < 0) return 0; // False if negative number

    int rem, sum = 0;
    int temp = x;

    while (temp) {
        if (sum > 2147483647 / 10) // Prevent integer overflow
            return 0;
        rem = temp % 10;
        sum = sum * 10 + rem;
        temp /= 10;
    }

    return x == sum; // Returns 1 if palindrome, 0 otherwise
}

int main() {
    int num;

    // Taking input from the user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Checking if the number is a palindrome
    if (isPalindrome(num))
        printf("%d is a palindrome.\n", num);
    else
        printf("%d is not a palindrome.\n", num);

    return 0;
}
/*OUTPUT : 
Enter an integer: 121
121 is a palindrome.

Enter an integer: -121
-121 is not a palindrome.

Enter an integer: 123
123 is not a palindrome. */

/*Time Complexity : O(log(N))
Space Complexity : O(1)*/