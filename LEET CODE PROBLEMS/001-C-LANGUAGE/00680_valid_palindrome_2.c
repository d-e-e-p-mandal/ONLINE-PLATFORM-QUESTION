// LEETCODE - 680 : Valid Palindrome 2 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s, int i, int j) {
    while ( i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;j--;
    }
    return true;
}

bool validPalindrome(char *s) {
    int i = 0, j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            // Try skipping either left or right character
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }
        i++;j--;
    }
    return true; // It's already a palindrome
}

int main() {
    char s[] = "abca";

    printf("%s -> %s\n", s, validPalindrome(s) ? "true" : "false");

    return 0;
}