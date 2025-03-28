//LEETCODE - 383 : Ransom Note
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int i,hash[26] = {0};
    int l1 = strlen(ransomNote);
    int l2 = strlen(magazine);

    for(i=0; i<l2; i++) {
        hash[magazine[i] - 97]++;
    }
    // ransom character will be less than or equal to magazine character
    for(i=0; i<l1; i++) {
        if(hash[ransomNote[i] - 97] == 0) 
            return false;
        else
            hash[ransomNote[i] - 97]--;
    }

    return true;
}

// Test the function
int main() {
    char ransomNote[] = "aa";
    char magazine[] = "aab";

    if (canConstruct(ransomNote, magazine)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}