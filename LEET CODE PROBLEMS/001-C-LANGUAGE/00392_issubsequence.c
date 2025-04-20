/*LeetCode : 392. Is Subsequence */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if 's' is a subsequence of 't'
bool isSubsequence(char* s, char* t) {
    int i = 0, j;
    int lenS = strlen(s);
    int lenT = strlen(t);  

    for (j = 0; j < lenT; j++) {
        if (s[i] == t[j]) {
            i++; // move to next character in s
        }
    }

    return i == lenS; // all characters in s were matched in order
}

int main() {
    char s1[] = "abc";
    char t1[] = "ahbgdc";

    char s2[] = "axc";
    char t2[] = "ahbgdc";

    printf("Is '%s' a subsequence of '%s'? %s\n", s1, t1, isSubsequence(s1, t1) ? "Yes" : "No");
    printf("Is '%s' a subsequence of '%s'? %s\n", s2, t2, isSubsequence(s2, t2) ? "Yes" : "No");

    return 0;
}
/* bool isSubsequence(char* s, char* t) {

    if(strlen(s)==0)return true;
    int i=0,j=0;

    while(j<strlen(t)){
        while(s[i] != t[j] && t[j] != '\0'){
            j++;
        }
        i++;j++;
        if(i == strlen(s) && j <= strlen(t)) return true;
        
    }
    return false;
}*/