/* LeetCode : 1910. Remove All Occurrences of a Substring*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to delete a substring of 'len' starting at index 'i'
void deleteDigit(char *s, int i, int len) {
    int n = strlen(s);
    while (i < n - len) {
        s[i] = s[i + len]; // shift left by 'len'
        i++;
    }
    s[i] = '\0'; // null-terminate after shifting
}

// Function to remove all occurrences of 'part' from string 's'
char* removeOccurrences(char* s, char* part) {
    int i = 0;
    int len = strlen(part);

    while (i < strlen(s)) {
        if (strncmp(s + i, part, len) == 0) {
            deleteDigit(s, i, len); // match found → remove
            i = (i - len >= 0) ? i - len : 0; // move back safely
        } else {
            i++;
        }
    }
    return s;
}

int main() {
    char s[100] = "abcabcabc";  
    char part[] = "abc";

    printf("Original string: %s\n", s);
    char *result = removeOccurrences(s, part);
    printf("After removal: %s\n", result);

    return 0;
}