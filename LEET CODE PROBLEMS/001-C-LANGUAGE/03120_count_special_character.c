#include <stdio.h>
#include <string.h>

int numberOfSpecialChars(char word[]) {
    // 2 hashtable create for lower and upper
    int i, countLower[26] = {0}, countUpper[26] = {0},count = 0;
    
    for(i=0; i< strlen(word); i++) {
        if(word[i] >= 'A' && word[i] <= 'Z')
            countUpper[word[i] - 'A']++;
        else
            countLower[word[i] - 'a']++;
    }
    // if word consist lower and upper then it special character
    for(i=0; i<26; i++) //count total special character
        if(countLower[i] != 0 && countUpper[i] != 0)
            count++;
    
    
    return count;
}

int main() {
    const char *word = "aaAbcBC";
    printf("Number of special characters: %d\n", numberOfSpecialChars(word));
    return 0;
}