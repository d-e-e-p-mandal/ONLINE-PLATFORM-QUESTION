#include <stdio.h>
#include <string.h>

int longestPalindrome(char* s) {
    int hashLower[26] = {0};
    int hashUpper[26] = {0};
    int i,flag = 0, count = 0;
    for(i=0; i< strlen(s); i++){
        if(s[i]<91)
            hashUpper[s[i] - 'A']++;
        else
            hashLower[s[i] - 'a']++;
    }

    for(i = 0; i<26; i++){  //ascii value lower to upper 
        if(hashUpper[i] % 2 == 0){
            count += hashUpper[i];
        }
        else{
            count += hashUpper[i] - 1;
            flag = 1;   // if any odd number character available then result will be +1
        }
    }

    for(i = 0; i<26; i++){  //ascii value lower to upper 
        if(hashLower[i] % 2 == 0){
            count += hashLower[i];
        }
        else{
            count += hashLower[i] - 1;
            flag = 1;   // if any odd number character available then result will be +1
        }
    }

    if(flag)return count+1;
    return count;
}

int main() {
    char str[] = "abccccdd";
    int length = longestPalindrome(str);
    printf("Length of longest palindrome that can be built is: %d\n", length);
    return 0;
}

/* Method : 2
int longestPalindrome(char* s) {
    int hash[256] = {0};
    int i, flag = 0, count = 0;

    for(i = 0; i < strlen(s); i++) {
        hash[(int)s[i]]++;
    }

    for(i = 65; i <= 122; i++) {// Check from 'A' (65) to 'z' (122) in ASCII
        if(hash[i] % 2 == 0) {
            count += hash[i];
        } else {
            count += hash[i] - 1;
            flag = 1; // We can add one odd character in the middle
        }
    }

    if(flag) return count + 1; //if odd character present then res : count + 1
    return count;
}*/